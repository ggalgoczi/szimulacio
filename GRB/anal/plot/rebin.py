import os, sys, math
import numpy as np

# list of numbers
a=[]
f = open("5.res", 'r')
for line in f:
    a.append(int(line))
    
a=a[1:]
print a    
exit()
# number of entries
L = int(len(a))

# desired bin width
W = 3

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
print a_rebin