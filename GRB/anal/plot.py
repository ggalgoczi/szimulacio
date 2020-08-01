import os
import matplotlib.pyplot as plt
import numpy as np
import operator
import pandas as pd
import math
degree=[]
value=[]
Flux=2.94113 # particle / cm**2 / sec
AreaOfIrradiation=60*60 # in cm
ParticlesSimulated=100000
Norm=Flux*AreaOfIrradiation/ParticlesSimulated

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_xlabel('Direction of the GRB [$^\circ$]')
ax.set_ylabel('Count rate [cps]')

f = open("ww", 'r')
for line in f:
	degree.append(float(line.split()[0]))		
	value.append(float(line.split()[1]))	
print degree
print value	

plt.errorbar(
            [x * 10 for x in degree],
            [x * Norm for x in value],
            yerr=[math.sqrt(x)*Norm for x in value],
           marker=".",
            linestyle="None",
 
            label='Count rate with threshold'
            )


degree=[]
value=[]
f = open("ww2", 'r')
for line in f:
	degree.append(float(line.split()[0]))		
	value.append(float(line.split()[1]))	
print degree
print value	

plt.errorbar(
            [x * 10 for x in degree],
            [x * Norm for x in value],
            yerr=[math.sqrt(x)*Norm for x in value],
            marker=".",
            linestyle="None",
            label='Count rate without threshold'
            )
plt.legend(  )
fig.savefig("grb_direction_detection.eps")
plt.show()