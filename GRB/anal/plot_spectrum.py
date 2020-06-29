import os
import matplotlib.pyplot as plt
import numpy as np
import operator
import pandas as pd
import math
degree=[]
value=[]
Flux=2.25023 # particle / cm**2 / sec
AreaOfIrradiation=60*60 # in cm
ParticlesSimulated=100000
Norm=Flux*AreaOfIrradiation/ParticlesSimulated

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_xlabel('Energy [keV]')
ax.set_ylabel('Count rate [cps]')
ax.set_xlim([0,1500])
ax.set_ylim([0.01,100])
f = open("../build/5.res", 'r')
for line in f:
	value.append(float(line.split()[0]))	
print degree
print value	

# rebin the histogram

value_rebinned = []
binsize=100
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

value=value_rebinned

plt.errorbar(
            [x * binsize / 4.11 for x in np.arange(len(value))],
            [x * Norm for x in value],
            yerr=[math.sqrt(x)*Norm for x in value],
            marker=".",
            linestyle="None",
            label='Measured scintillation spectrum for 45$^{\circ}$'
            )



degree=[]
value=[]

f = open("../build/26.res", 'r')
for line in f:
	value.append(float(line.split()[0]))	
print degree
print value	

# rebin the histogram

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
value=value_rebinned
plt.yscale('log')

plt.errorbar(
            [x * binsize / 4.11 for x in np.arange(len(value))],
            [x * Norm for x in value],
            yerr=[math.sqrt(x)*Norm for x in value],
            marker=".",
            linestyle="None",
            label='Simulated scintillation spectrum for 260$^{\circ}$'
            )


plt.legend()
fig.savefig("grb_spectrum.png")
plt.show()