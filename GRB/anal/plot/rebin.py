import os, sys, math
import numpy as np
from matplotlib import pyplot as plt

# list of numbers
a=[]
f = open("5.res", 'r')
for line in f:
    a.append(int(line))
    
a=a[1:] # Cutting entry for zeros
#print a    
# number of entries
L = int(len(a))

# desired bin width
W = 30

# number of bins with width W
N = int(L/W)

# definition of new empty array
a_rebin = np.zeros((N, 2))

# cycles to populate the new rebinned array
for n in range(0,N):
    k = 0
    for i in range(0,L):
        if a[i] >= (W*n) and a[i] < (W+W*n):
            k = k+1
    a_rebin[n]=[W*n,k]

# print
plt.plot(a)
plt.plot(a_rebin)
plt.show()
print a_rebin