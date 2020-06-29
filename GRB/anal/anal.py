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


directory = '../build/'
NoFound = 0
for filename in os.listdir(directory):
	if ".res" in filename:
	#	print filename
		f = open(directory+filename, 'r')
		Histogram = []
		for line in f:
			HistogramEntry = float(line.split()[0])
			Histogram.append(HistogramEntry)
		print filename.split(".")[0],sum(Histogram[84:])

		
	#	print "run"
#		with open('../build/res.txt', 'a') as the_file:
		#for i in xrange(len(sum_No)-1):
#			the_file.write(str(len(sum_No))+'\n')
#if NoFound == 0:
#	with open('../build/res.txt', 'a') as the_file:
#		the_file.write(str(0)+'\n')
	
exit(-1)		
	#print "len",len(sum_No)

#	values, edges = np.histogram(sum_No, bins=bins_2)
	#for i in xrange(len(edges)-1):    
	#	bins_centers.append((edges[i] + edges[i+1])/2)
	#bins_centers = np.array(bins_centers)
	#print filename,  np.count_nonzero(sum_No)
	#angle.append(float(filename[:-4])*10)
	#counts.append(np.count_nonzero(sum_No))
	
	
	
	#y, bin_edges = np.histogram(sum_No, bins_2)
	#bin_centers = 0.5*(bin_edges[1:] + bin_edges[:-1])
	
	#if filename == "00.txt" or filename == "017.txt":
	#	plt.errorbar(
#		bin_centers,
#		y,
#		yerr = y**0.5,
#		marker = '.',
#		drawstyle = 'steps-mid-'
#		)
#		plt.title('')
#		plt.xlabel('Number of scint photons detected')
#		plt.ylabel('Number of events')
#		plt.xlim([10, 16000])
#		plt.ylim([0, 70])
#		plt.show()	
#		
##	if filename == "8.txt":
#		plt.errorbar( bin_centers,	y,	yerr = y**0.5,	marker = '.',	drawstyle = 'steps-mid-'	)		
#		plt.title('')
#		plt.xlabel('Number of events')
#		plt.ylabel('Number of scint photons detected')
#		plt.xlim([10, 16000])
#		plt.ylim([0, 40])
#		plt.show()		
	
	
	
fig,axes = plt.subplots()	
plt.errorbar(angle,counts,yerr=np.sqrt(counts), linestyle="None")
#plt.scatter(angle, counts, alpha=0.5)
plt.title('')
plt.xlabel('Angle')
plt.ylabel('Number of particles detected')
plt.ylim([1, 300])
plt.xlim([0, 370])
fig.savefig('reees.png', bbox_inches='tight')

#plt.show()	
	
	
#	print(sum_No)








