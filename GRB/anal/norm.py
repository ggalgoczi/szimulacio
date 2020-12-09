import os
import matplotlib.pyplot as plt
import numpy as np
import operator
import pandas as pd
import math

pi = 3.1415926
R = 5000.
sinTheta = math.sin(0.5729 / 180. * pi)
NormFactor = 3600
Treshold=82
binsize=100
Master1=np.zeros(10001)
Master1p5=np.zeros(10001)
Master2=np.zeros(10001)
Master0p5=np.zeros(10001)

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


        if float(thickness) == 1:
            if filename.find("CXB_gruber500_lines") == -1:
                Master1[PlaceHolder]=Master1[PlaceHolder]+writeout

        if float(thickness) == 1.5:
            if filename.find("CXB_gruber500_lines") == -1:
                Master1p5[PlaceHolder]=Master1p5[PlaceHolder]+writeout

        if float(thickness) == 2:
            if filename.find("CXB_gruber500_lines") == -1:
                Master2[PlaceHolder]=Master2[PlaceHolder]+writeout


        if float(thickness) == 0.5:
            if filename.find("CXB_gruber500_lines") == -1:
                Master0p5[PlaceHolder]=Master0p5[PlaceHolder]+writeout


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
    

    f_Out2 = open("latex_table_transients", 'w')
    f_Out2.write('\\begin{table}[h!]'+'\n')
    f_Out2.write("\\begin{center}"+"\n")
    f_Out2.write("\\begin{tabular}{|c|c|c|c|c|c|c|c|c|c|}"+"\n")
    f_Out2.write("\hline"+"\n")
    f_Out2.write("Al   & \\multicolumn{3}{c|}{sGRB peak spectrum} & \\multicolumn{3}{c|}{lGRB peak spectrum} & lGRB & \\multirow{2}{*}{TGF} & \\multirow{2}{*}{SGR} \\\\ \\cline{2-7}")
    f_Out2.write("(mm) & 64\\,ms & 256\\,ms & 1024\\,ms &    64\\,ms & 256\\,ms & 1024\\,ms & fln. sp. &      &  \\\\")
    f_Out2.write("\hline"+"\n")
#\\hline")




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
    for tckness in[0.5,1,1.5,2]:    
        f_Out2.write(str(tckness)+" mm &")


        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("typical_sgrb_spectrum_from_64ms_peak_comp") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 1

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                if Comm.find("typical_sgrb_spectrum_from_256ms_peak_comp") != -1:
                    print "itt", parsedentry[3]

                    Int=str(parsedentry[3])
                    print "itt", Int
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 2

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("typical_sgrb_spectrum_from_1024ms_peak_comp") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 3

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("typical_lgrb_spectrum_from_64ms_peak_comp") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 4
        
        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("typical_lgrb_spectrum_from_256ms_peak_comp") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 5



        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("typical_lgrb_spectrum_from_1024ms_peak_comp") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 6

        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("typical_lgrb_fluence_spectrum_comp") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 7



        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("TGF_AGILE_Marisaldi_et_al_2014") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' & ')
                    print "OKK", 8


        for parsedentry in ListOfLists:
            if float(parsedentry[0]) == tckness:
                Comm=parsedentry[2]
                TheRealFlux=float(parsedentry[3])
                Int=str(TheRealFlux)
                if Comm.find("example_sgr_spectrum") != -1:
                    f_Out2.write("{:.0f}".format(float(Int))+' \\\\ ')
                    print "OKK", 9

        f_Out2.write("\n")


          #  if Comment_Joined
        #    print parsedentry[2]
 #    for parsedentry in ListOfLists:
  #      if parsedentry[0] == 1.5:
   

       # if(Thickness == 1):
       #     print FullName
  #      if(Thickness == 1.5):

   #     if(Thickness == 2):



    f_Out2.write("\hline"+"\n")
    f_Out2.write("\end{tabular}"+"\n")
    f_Out2.write("\end{center}"+"\n")
    f_Out2.write("\caption{Simulated detection rate (in counts per second assuming a low-energy threshold of 20 keV) induced by the X-ray/$\gamma$-ray transient sources for different thicknesses of the aluminium support structure of the detector. For short and long GRBs the 64\,ms, 256\,ms and 1024\,ms peak spectra were used. For long GRB also the fluence spectrum (fln. sp.) was used.}"+"\n")
    f_Out2.write("\label{table:count_rates_transients}"+"\n")
    f_Out2.write("\end{table}"+"\n")
#############################################################
#           Now running for the files to be processed       #
#############################################################

SumAndFileNamePairList=[]
Checklist = []
for filename in os.listdir("../build/"):
    #print filename
    if filename.find("rate_") != -1:
        print filename
       # print str(filename.split("_")[2:])
        thickness=filename.split("_")[-2]
        DataFile=filename.split("_")[2:-2]
        DataFileName='_'.join(DataFile)
      #  print DataFileName
        f = open("../build/master.txt", 'r') # look for the original input spectrum file
        for line in f:
            print line
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
f_master4 = open("bck_0p5mm", 'w')

for i in Master1:
    f_master1.write(str(i)+'\n')


for i in Master1p5:
    f_master2.write(str(i)+'\n')


for i in Master2:
    f_master3.write(str(i)+'\n')    


for i in Master0p5:
    f_master4.write(str(i)+'\n')        
    #f = open(file, 'r')
    #for line in f: