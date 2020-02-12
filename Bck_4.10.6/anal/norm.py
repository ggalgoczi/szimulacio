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

value=value_rebinned

def NormHistogram(filename,IntegrapSpect,NumberOfPrimaries):
    print "../build/"+filename
    f_In = open("../build/"+filename, 'r')
    f_Out = open("normed/normed_"+filename, 'w')
    Values=[]
    for line_in in f_In:
        writeout=float(line_in)/float(NumberOfPrimaries)*float(IntegrapSpect)*float(NormFactor)
        Values.append(writeout)
       # print writeout
        f_Out.write(str(writeout)+"\n")
    print sum(Values[Treshold:])
   # exit()

for filename in os.listdir("../build/"):
    if "rate" in filename:
       # print filename
       # print str(filename.split("_")[2:])
        thickness=filename.split("_")[-2]
        DataFile=filename.split("_")[2:-2]
        DataFileName='_'.join(DataFile)
     #   print DataFileName
        f = open("../build/master.txt", 'r') # look for the original input spectrum file
        for line in f:
           # print line.split()[3]
            if DataFileName in line.split()[3]:
                TheRealNameofInputSpectrum=line.split()[3]
                NumberOfPrimaries=line.split()[1]
                try:
                    f2 = open(TheRealNameofInputSpectrum)
                    
                except:
                    print "ERROR" 
                    print "Could not open: ",TheRealNameofInputSpectrum
                lineIn=f2.readline() # Get integral spectrum
                IntegrapSpect=lineIn.split()[2]
                NormHistogram(filename,IntegrapSpect,NumberOfPrimaries) 
                print "OK"



    #f = open(file, 'r')
    #for line in f: