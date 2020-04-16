import os
import matplotlib.pyplot as plt
import numpy as np
import operator
import pandas as pd
import math

pi = 3.1415926
R = 5000.
sinTheta = math.sin(0.5729 / 180. * pi)
NormFactor = 4. * pi* pi * R* R *sinTheta *sinTheta
Treshold=26
binsize=100
Master1=np.zeros(10001)
Master1p5=np.zeros(10001)
Master2=np.zeros(10001)

def Rebin(value):
    value_rebinned = []
    k=0
    buff=0
    counter=0
    for i in value:
        buff+=i
        k+=1
        counter+=1
        if k==binsize:
            k=0
            value_rebinned.append(buff)
            buff=0
    return value_rebinned

def SaveHisto(Values,filename):

    RebinnedValues=Rebin(Values)
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.set_yscale('log')

    ax.set_xlabel('Number of detected photons')
    ax.set_ylabel('Count rate [cps]')
    plt.errorbar(
            [x * binsize for x in np.arange(len(RebinnedValues))],
            RebinnedValues,
            yerr=[math.sqrt(x) for x in RebinnedValues],
            marker=".",
            linestyle="None",
            label='Measured scintillation spectrum for 50$^{\circ}$'
            )
    
    plt.legend()
    fig.savefig("./plots/"+filename+".png")
    plt.close(fig)
   # plt.show()

def NormHistogram(filename,IntegrapSpect,NumberOfPrimaries,thickness):
  #  print "../build/"+filename
    f_In = open("../build/"+filename, 'r')
    f_Out = open("normed/normed_"+filename, 'w')
    Values=[]
    PlaceHolder=0
    for line_in in f_In:
        writeout=float(line_in)/float(NumberOfPrimaries)*float(IntegrapSpect)*float(NormFactor) # the norm factor from the real solid angle is taken care later on, 12.5664 is 4 pi

        if filename.find("CXB_gruber500_lines") != -1 or \
            filename.find("Ajello_et_al_2008_500_lines") != -1 or \
            filename.find("cr_setting2_fluxes_pos") != -1 or \
            filename.find("cr_setting2_fluxes_e") != -1 or \
            filename.find("gcr_magnetosphere_stormy_fluxes_He") != -1 or \
            filename.find("gcr_magnetosphere_stormy_fluxes_H") != -1:
                writeout=writeout*0.685

        if filename.find("Albedo_gamma_ray_Ajello_et_al_2008") != -1 or \
            filename.find("cr_setting1_fluxes_sec_e") != -1 or \
            filename.find("cr_qarm_setting2_fluxes_albedo_n") != -1 or \
            filename.find("cr_setting2_fluxes_sec_pos") != -1 or \
            filename.find("cr_fluxes_sec_p") != -1:
                writeout=writeout*0.315

        if filename.find("spenvis_tri_electrons") != -1:
                writeout=writeout/12.56

        if float(thickness) == 1:
            if filename.find("CXB_gruber500_lines") == -1:
                Master1[PlaceHolder]=Master1[PlaceHolder]+writeout

        if float(thickness) == 1.5:
            if filename.find("CXB_gruber500_lines") == -1:
                Master1p5[PlaceHolder]=Master1p5[PlaceHolder]+writeout

        if float(thickness) == 2:
            if filename.find("CXB_gruber500_lines") == -1:
                Master2[PlaceHolder]=Master2[PlaceHolder]+writeout


        Values.append(writeout)
       # print writeout
        f_Out.write(str(writeout)+"\n")
#        print "start"
#        print "line in:",line_in
#        print NumberOfPrimaries, IntegrapSpect, NormFactor
#        print "line out",writeout
#        print "end"

        PlaceHolder=PlaceHolder+1
    SaveHisto(Values,filename)

    print "For file: ",filename, " integral is:"
    print sum(Values[Treshold:])
    return filename,sum(Values[Treshold:])
   # exit()


def PrintTable(ListOfEntries):
    f_Out1 = open("latex_table_rest", 'w')
    f_Out1.write('\\begin{table}[h!]'+'\n')
    f_Out1.write("\\begin{center}"+"\n")
    f_Out1.write("\\begin{tabular}{|c|c|c|c|c|c|c|c|}"+"\n")
    f_Out1.write("\hline"+"\n")
    f_Out1.write("&")
    f_Out1.write("CXB Gruber &")
    f_Out1.write("CXB Ajello &")
    f_Out1.write("Cosmic e$^{+}$ &")
    f_Out1.write("Cosmic e$^{-}$ &")
    f_Out1.write("Stormy $\\alpha$ &")
    f_Out1.write("Stormy p$^{+}$ &")
    f_Out1.write("Trapped e$^{-}$ &")
    f_Out1.write("\hline"+"\n")


    f_Out2 = open("latex_table_albedo", 'w')
    f_Out2.write('\\begin{table}[h!]'+'\n')
    f_Out2.write("\\begin{center}"+"\n")
    f_Out2.write("\\begin{tabular}{|c|c|c|c|c|c|}"+"\n")
    f_Out2.write("\hline"+"\n")
    f_Out2.write("&")
    f_Out2.write("Albedo $\gamma$ &")
    f_Out2.write("Secondary e$^{-}$ &")
    f_Out2.write("Albedo n$^{0}$ &")
    f_Out2.write("Secondary e$^{+}$ &")
    f_Out2.write("Secondary p$^{+}$ &")
    f_Out2.write("\hline"+"\n")


    ListOfLists=[] # this list contains a list of entries which are parsed by:
         # <thickness> <particle> <comment> <integral>
   # print ListOfEntries
    for entry in ListOfEntries:
        ListBuff=[]
        Integral=entry[1]
        FullName=entry[0]
        Thickness=FullName.split("_")[-2]
        Particle=FullName.split("_")[1]
        Comment=FullName.split("_")[2:-2]
        Comment_Joined='_'.join(Comment)
        ListBuff.append(Thickness)
        ListBuff.append(Particle)
        ListBuff.append(Comment_Joined)
        ListBuff.append(Integral)
        ListOfLists.append(ListBuff)
        if float(Thickness) == 1:
            print Comment_Joined
      #  print FullName

    # Now iterate through content 
    for tckness in[1,1.5,2]:    
        f_Out1.write(str(tckness)+" mm &")
        f_Out2.write(str(tckness)+" mm &")

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                if Comm.find("CXB_gruber500_lines") != -1:
                    print "itt", parsedentry[3]

                    Int=str(parsedentry[3])
                    print "itt", Int
                    f_Out1.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 1


        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("Ajello_et_al_2008_500_lines") != -1:
                    f_Out1.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 2


        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("Albedo_gamma_ray_Ajello_et_al_2008") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 3


        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("cr_setting1_fluxes_sec_e") != -1:
                    f_Out2.write("{:.2f}".format(float(Int))+' & ')
                    print "OKK", 4

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("cr_qarm_setting2_fluxes_albedo_n") != -1:
                    f_Out2.write("{:.2f}".format(float(Int))+' & ')
                    print "OKK", 5

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)

                if Comm.find("cr_setting2_fluxes_sec_pos") != -1:
                    f_Out2.write("{:.2f}".format(float(Int))+' & ')
                    print "OKK", 6

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("cr_fluxes_sec_p.dat") != -1:
                    f_Out2.write("{:.2f}".format(float(Int))+' & ')
                    print "OKK", 7

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("cr_setting2_fluxes_pos.dat") != -1:
                    f_Out1.write("{:.4f}".format(float(Int))+' & ')
                    print "OKK", 8

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("cr_setting2_fluxes_e.dat") != -1:
                    f_Out1.write("{:.2f}".format(float(Int))+' & ')
                    print "OKK", 9

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("gcr_magnetosphere_stormy_fluxes_He.dat") != -1:
                    f_Out1.write("{:.2f}".format(float(Int))+' & ')
                    print "OKK", 10

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("gcr_magnetosphere_stormy_fluxes_H.dat") != -1:
                    f_Out1.write("{:.2f}".format(float(Int))+' & ')
                    print "OKK", 11

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("spenvis_tri_electrons.txt") != -1:
                    f_Out1.write("{:.3f}".format(float(Int))+' & ')
                    print "OKK", 12

        f_Out1.write("\n")
        f_Out2.write("\n")


          #  if Comment_Joined
        #    print parsedentry[2]
 #    for parsedentry in ListOfLists:
  #      if parsedentry[0] == 1.5:
   

       # if(Thickness == 1):
       #     print FullName
  #      if(Thickness == 1.5):

   #     if(Thickness == 2):


    f_Out1.write("\hline"+"\n")
    f_Out1.write("\end{tabular}"+"\n")
    f_Out1.write("\end{center}"+"\n")
    f_Out1.write("\caption{Simulated detection rate (in counts per second) induced by background components for different Aluminium shielding thicknesses.}"+"\n")
    f_Out1.write("\label{table:materials}"+"\n")
    f_Out1.write("\end{table}"+"\n")


    f_Out2.write("\hline"+"\n")
    f_Out2.write("\end{tabular}"+"\n")
    f_Out2.write("\end{center}"+"\n")
    f_Out2.write("\caption{Simulated detection rate (in counts per second) induced by background components which originate in the atmosphere for different Aluminium shielding thicknesses.}"+"\n")
    f_Out2.write("\label{table:materials}"+"\n")
    f_Out2.write("\end{table}"+"\n")
#############################################################
#           Now running for the files to be processed       #
#############################################################

SumAndFileNamePairList=[]
Checklist = []
for filename in os.listdir("../build/"):
    #print filename
    if filename.find("rate") != -1:
       # print filename
       # print str(filename.split("_")[2:])
        thickness=filename.split("_")[-2]
        DataFile=filename.split("_")[2:-2]
        DataFileName='_'.join(DataFile)
      #  print DataFileName
        f = open("../build/master_safe.txt", 'r') # look for the original input spectrum file
        for line in f:
        
            if  line.split()[3].find(DataFileName) != -1 and thickness == line.split()[0]:
                TheRealNameofInputSpectrum=line.split()[3]
                NumberOfPrimaries=line.split()[1]
                try:
                    f2 = open(TheRealNameofInputSpectrum)
                    
                except:
                    print "ERROR" 
                    print "Could not open: ",TheRealNameofInputSpectrum
                Checklist.append([line.split()[3],line.split()[0]])
                lineIn=f2.readline() # Get integral spectrum
                IntegrapSpect=lineIn.split()[2]
                Pair=NormHistogram(filename,IntegrapSpect,NumberOfPrimaries,thickness) 
                print "Pair is",Pair
                SumAndFileNamePairList.append(Pair)
                print "OK"

# Now check which entries from master.txt were not in  the output data
f = open("../build/master.txt", 'r') # look for the original input spectrum file
for line in f:
    if [line.split()[3],line.split()[0]] not in Checklist:
        print (line.split()[3],line.split()[0]), "was not found!"

PrintTable(SumAndFileNamePairList)


f_master1 = open("bck_1mm", 'w')
f_master2 = open("bck_1p5mm", 'w')
f_master3 = open("bck_2mm", 'w')

for i in Master1:
    f_master1.write(str(i)+'\n')


for i in Master1p5:
    f_master2.write(str(i)+'\n')


for i in Master2:
    f_master3.write(str(i)+'\n')    
    #f = open(file, 'r')
    #for line in f: