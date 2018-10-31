


import numpy as np
import random
import os
from matplotlib import pyplot as plt
import math
from scipy.optimize import curve_fit

def poisson_probability(actual, mean):
    # naive:   math.exp(-mean) * mean**actual / factorial(actual)

    # iterative, to keep the components from getting too large or small:
    p = math.exp(-mean)
    for i in xrange(actual):
        p *= mean
        p /= i+1
    return p


# fixed bin size
#bins = np.arange(0, 4000, 5) # fixed bin size



bins_2 = np.arange(0, 20000, 20) # fixed bin size
directory = '../build/'
angle = []
counts = []
for filename in os.listdir(directory):
 if filename.endswith(".txt") and not filename.endswith("scint.txt"):
	print filename

	f = open(directory+filename, 'r')

	w, h = 0, 11000000;
	energies = [[0 for x in range(w)] for y in range(h)] 
	sum_e = []
	sum_No = []
	bins_centers = []
	p = 0
	for line in f:
		EvNum = int(line.split()[0])
		energies[EvNum].append(float(line.split()[4]))

	for W in xrange(0,h-1):
		sum_No.append(len(energies[W]))

	values, edges = np.histogram(sum_No, bins=bins_2)
	for i in xrange(len(edges)-1):    
		bins_centers.append((edges[i] + edges[i+1])/2)
	bins_centers = np.array(bins_centers)
	print filename,  np.count_nonzero(sum_No)
	angle.append(float(filename[:-4])*10)
	counts.append(np.count_nonzero(sum_No))
	
	
	
	y, bin_edges = np.histogram(sum_No, bins_2)
	bin_centers = 0.5*(bin_edges[1:] + bin_edges[:-1])
	
	if filename == "0.txt" or filename == "17.txt":
		plt.errorbar(
		bin_centers,
		y,
		yerr = y**0.5,
		marker = '.',
		drawstyle = 'steps-mid-'
		)
		plt.title('')
		plt.xlabel('Number of scint photons detected')
		plt.ylabel('Number of events')
		plt.xlim([10, 16000])
		plt.ylim([0, 70])
		plt.show()	
		
#	if filename == "8.txt":
#		plt.errorbar( bin_centers,	y,	yerr = y**0.5,	marker = '.',	drawstyle = 'steps-mid-'	)		
#		plt.title('')
#		plt.xlabel('Number of events')
#		plt.ylabel('Number of scint photons detected')
#		plt.xlim([10, 16000])
#		plt.ylim([0, 40])
#		plt.show()		
	
	
	
	

plt.scatter(angle, counts, alpha=0.5)
plt.title('')
plt.xlabel('Angle')
plt.ylabel('Number of particles detected')
plt.ylim([1, 15000])
plt.xlim([0, 370])

plt.show()	
	
	
#	print(sum_No)








