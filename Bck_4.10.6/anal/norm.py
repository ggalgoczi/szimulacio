import os
import matplotlib.pyplot as plt
import numpy as np
import operator
import pandas as pd
import math

pi = 3.1415926
R = 5000.
sinTheta = math.sin(0.09 / 180. * pi)
NormFactor = 4. * pi* pi * R* R *sinTheta *sinTheta
Treshold=30
binsize=100


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

def NormHistogram(filename,IntegrapSpect,NumberOfPrimaries):
  #  print "../build/"+filename
    f_In = open("../build/"+filename, 'r')
    f_Out = open("normed/normed_"+filename, 'w')
    Values=[]
    for line_in in f_In:
        writeout=float(line_in)/float(NumberOfPrimaries)*float(IntegrapSpect)*float(NormFactor)
#        print "start"
#        print "line in:",line_in
#        print NumberOfPrimaries, IntegrapSpect, NormFactor
#        print "line out",writeout
#        print "end"

        Values.append(writeout)
       # print writeout
        f_Out.write(str(writeout)+"\n")
    SaveHisto(Values,filename)
  #  print "For file: ",filename, " integral is:"
  #  print sum(Values[Treshold:])
    return filename,sum(Values[Treshold:])
   # exit()


def PrintTable(ListOfEntries):
    f_Out = open("latex_table", 'w')
    f_Out.write('\\begin{table}[h!]'+'\n')
    f_Out.write("\\begin{center}"+"\n")
    f_Out.write("\\begin{tabular}{ |c|c|c|c|c|c|c|c|c|c|c|c|c|}"+"\n")
    f_Out.write(" \hline"+"\n")
    f_Out.write("Name of module & mass [g] & Type of material & Mass ratio [\%]\\\hline"+"\n")


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
        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
               # if Comm.find("CXB_gruber500_lines") != -1:
              #      f_Out.write(Int+' & ')

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("Ajello_et_al_2008_500_lines") != -1:
                    f_Out.write(Int+' & ')


        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("Albedo_gamma_ray_Ajello_et_al_2008") != -1:
                    f_Out.write(Int+' & ')


        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("cr_setting1_fluxes_sec_e") != -1:
                    f_Out.write(Int+' & ')

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("cr_qarm_setting2_fluxes_albedo_n") != -1:
                    f_Out.write(Int+' & ')

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])

                if Comm.find("cr_setting2_fluxes_sec_pos") != -1:
                    f_Out.write(Int+' & ')

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("cr_fluxes_sec_p.dat") != -1:
                    f_Out.write(Int+' & ')

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("cr_setting2_fluxes_pos.dat") != -1:
                    f_Out.write(Int+' & ')

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("cr_setting2_fluxes_e.dat") != -1:
                    f_Out.write(Int+' & ')
                    print 9

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("gcr_magnetosphere_stormy_fluxes_He.dat") != -1:
                    f_Out.write(Int+' & ')

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("gcr_magnetosphere_stormy_fluxes_H.dat") != -1:
                    f_Out.write(Int+' & ')

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                Int=str(parsedentry[3])
                if Comm.find("spenvis_tri_electrons.txt") != -1:
                    f_Out.write(Int+' & ')
        f_Out.write("\n")


          #  if Comment_Joined
        #    print parsedentry[2]
 #    for parsedentry in ListOfLists:
  #      if parsedentry[0] == 1.5:
   

       # if(Thickness == 1):
       #     print FullName
  #      if(Thickness == 1.5):

   #     if(Thickness == 2):


    f_Out.write("\hline"+"\n")
    f_Out.write("\end{tabular}"+"\n")
    f_Out.write("\end{center}"+"\n")
    f_Out.write("\caption{The mass ratio of materials that are used for the satellite (Courtesy of C3S LLC) \cite{drawing}}"+"\n")
    f_Out.write("\label{table:materials}"+"\n")
    f_Out.write("\end{table}"+"\n")

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
        f = open("../build/master.txt", 'r') # look for the original input spectrum file
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
                Pair=NormHistogram(filename,IntegrapSpect,NumberOfPrimaries) 
           #     print "Pair is",Pair
                SumAndFileNamePairList.append(Pair)
                print "OK"

# Now check which entries from master.txt were not in  the output data
f = open("../build/master.txt", 'r') # look for the original input spectrum file
for line in f:
    if [line.split()[3],line.split()[0]] not in Checklist:
        print (line.split()[3],line.split()[0]), "was not found!"

PrintTable(SumAndFileNamePairList)


    #f = open(file, 'r')
    #for line in f: