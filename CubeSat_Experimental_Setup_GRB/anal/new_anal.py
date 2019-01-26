import numpy as np
import random
from matplotlib import pyplot as plt
import math
from scipy.optimize import curve_fit
import csv
import os

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
angle = []
counts = []
for filename in os.listdir(directory):
 if filename.endswith(".txt") and not filename.endswith("gamma.txt") and not filename.endswith("CMakeCache.txt"):
	print filename
	f = open(directory+filename, 'r')


#f = open('/home/galgoczi/hermes/hermes/GeantSimProtons/build/proton_0p2cm.txt', 'r')
	w, h = 0, 1000000
	energies_in_buff = []
	energies_in_evnums = []
	energies_out_buff = []
	energies_out_buff_evnums = []
	energies_in_buff_evnums = []
	sum_e = []
	sum_No = []
	bins_centers = []
	p = 0
	for line in f:
		EvNum = int(line.split()[0])
		if line.split()[5] == "In":
			energies_in_buff.append(float(line.split()[4]))
			energies_in_buff_evnums.append(EvNum)
		if line.split()[5] == "Out":
			energies_out_buff.append(float(line.split()[4]))
			energies_out_buff_evnums.append(EvNum)	
					
	energies_in_buff = np.array(energies_in_buff)
	energies_in_buff_evnums = np.array(energies_in_buff_evnums)
	energies_out_buff = np.array(energies_out_buff)
	energies_out_buff_evnums = np.array(energies_out_buff_evnums)

	counting = 0
	max_evnum = 0
	energies = []

	if len(energies_in_buff) > len(energies_out_buff):
		counting = len(energies_in_buff)
	else:
		counting = len(energies_out_buff)

	if max(energies_out_buff_evnums) > max(energies_in_buff_evnums):
		max_evnum = max(energies_out_buff_evnums)
	else:
		max_evnum = max(energies_in_buff_evnums) 	

	print("Started reading in data")

	unique_energies_in_buff_evnums = np.unique(energies_in_buff_evnums)

#for i in xrange(0,max_evnum+1):
	for j,i in np.ndenumerate(unique_energies_in_buff_evnums):
#	print(unique_energies_in_buff_evnums)
	#if issubclass(i, energies_out_buff_evnums) or issubclass(i, energies_in_buff_evnums):
		if np.isin(i,energies_out_buff_evnums):
			if np.isin(i,energies_in_buff_evnums):
			
			
	#		print("this")
	#		print(i)
	#		print(energies_out_buff)
	#		print(energies_out_buff_evnums)
	#		print((energies_out_buff_evnums == i).astype(int))
		#	print(energies_out_buff[(energies_out_buff_evnums == i).astype(bool)])
		#	print(sum(energies_out_buff[(energies_out_buff_evnums == i).astype(bool)]))
		#	exit()
			
			#print(i)
#			print(sum(energies_in_buff[(energies_in_buff_evnums == i).astype(int)]), sum(energies_out_buff[(energies_out_buff_evnums == i).astype(int)]))
		#	print((energies_in_buff_evnums == i).astype(int), (energies_out_buff_evnums == i).astype(int))
		#	print(energies_in_buff[(energies_in_buff_evnums == i).astype(int)])
		#	to_append = sum(energies_in_buff[(energies_in_buff_evnums == i).astype(int)]) - sum(energies_out_buff[(energies_out_buff_evnums == i).astype(int)])
				to_append = sum(energies_in_buff[(energies_in_buff_evnums == i).astype(bool)]) - sum(energies_out_buff[(energies_out_buff_evnums == i).astype(bool)])
				energies.append(to_append)
			else:
				print("Energy went out but not in!!!")
				exit(-1)		
		elif np.isin(i,energies_in_buff_evnums):
#		to_append = sum(energies_in_buff[(energies_in_buff_evnums == i).astype(int)])
		#print(len(energies_in_buff),len(energies_in_buff_evnums))
		#print(type(energies_in_buff),type(energies_in_buff_evnums))
			to_append = sum(energies_in_buff[(energies_in_buff_evnums == i).astype(bool)])
			energies.append(to_append)
		
	
	
	# or np.isin(i,energies_in_buff_evnums):
#		print((energies_in_buff_evnums == i).astype(int))	

#		lol = np.isin(i,list(energies_in_buff_evnums))
		
		
	#	B = ind[energies_out_buff_evnums[ind]==i]
	#	idx = np.isin(i,energies_in_buff_evnums)
	#	print(lol)
		
		
		#item = np.where(energies_out_buff_evnums==i)
		#print(item)
	energies[:] = [x / 1000 for x in energies]
	bins_2 = np.arange(0, max(energies)+1, max(energies)/1000) # fixed bin size
	
	print("Started histogramming")

	values, edges = np.histogram(energies, bins=bins_2)
	values[0] = 0
	for i in xrange(len(edges)-1):    
		bins_centers.append((edges[i] + edges[i+1])/2)
	bins_centers = np.array(bins_centers)


	print("Detected photons:")
	Detected = sum(values[np.where(bins_centers>20)])
	print(Detected)

#plt.hist(sum_No, bins=bins_2, alpha=0.5)
	plt.plot(bins_centers, values)
	plt.title('')
	plt.ylabel('Number of events')
	plt.xlabel('Energies depleted [keV]')
	plt.xlim([1, max(energies)])
	plt.ylim([0, max(values)])


	ang = float(filename[:-4])*10

	angle.append(ang)
	counts.append(Detected)
	with open('res.txt', 'a') as the_file:
		the_file.write(str(ang)+" "+str(Detected)+'\n')
	
#	plt.show()


plt.errorbar(angle,counts,yerr=np.sqrt(counts), linestyle="None")
#plt.scatter(angle, counts, alpha=0.5)
plt.title('')
plt.xlabel('Angle')
plt.ylabel('Number of particles detected')
plt.ylim([1, max(counts)+1])
plt.xlim([0, 370])



exit()

##########
# Plot Gaussian
cut_1 = 70
cut_2 = 300
bin_fit = bins_centers[(np.where((bins_centers >= cut_1) & (bins_centers <= cut_2)))]
values_fit = values[(np.where((bins_centers >= cut_1) & (bins_centers <= cut_2)))]

## print data to files
#with open('file.txt', 'a') as file:
#    for s in bin_fit:
#        file.write(str(s) +" ")
#        file.write("\n")
#print(os.path.splitext(f)[0])

filename = '1'
s  = filename
s += '.histo'      
with open(s, 'w') as f2:        
	writer = csv.writer(f2, delimiter='\t')
	writer.writerows(zip(bin_fit,values_fit))


#   file.write(values_fit)

exit()

x = bin_fit
y = values_fit
n = len(x)                          #the number of data
mean = sum(x*y)/n                   #note this correction
sigma = sum(y*(x-mean)**2)/n        #note this correction

def gaus(x,a,x0,sigma):
    return a*np.exp(-(x-x0)**2/(2*sigma**2))

popt,pcov = curve_fit(gaus,x,y,p0=[1,mean,sigma])
print popt[1]


plt.plot(x,y,'b+:',label='data')
plt.plot(x,gaus(x,*popt),'ro:',label='fit')
plt.legend()
#plt.title('Fig. 3 - Fit for Time Constant')
#plt.xlabel('Time (s)')
#plt.ylabel('Voltage (V)')
plt.show()

