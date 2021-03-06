import matplotlib.pyplot as plt
import numpy as np
import os 

from scipy.ndimage.filters import gaussian_filter1d

def gaussian( x , s):
    return 1./np.sqrt( 2. * np.pi * s**2 ) * np.exp( -x**2 / ( 2. * s**2 ) )


for filename in os.listdir("./"):
    if filename.startswith("position"):
        print filename


        simulated_spectrum = np.loadtxt(filename)
        simulated_spectrum=np.delete(simulated_spectrum, 0) # to remove the first element containing zeros

        filterdData = gaussian_filter1d( simulated_spectrum, 15 )

        #myFilteredData = np.convolve( myData, myGaussian, mode='same' )
        fig = plt.figure(1)
        ax = fig.add_subplot( 1, 1, 1 )
        ax.plot( simulated_spectrum, marker='x', label='peak' )
        ax.plot( filterdData, marker='^',label='filter1D smeared peak' )
        ax.legend( bbox_to_anchor=( 1.05, 1 ), loc=2 )
        plt.tight_layout()
        #plt.show()

        np.savetxt("smeared_"+filename, filterdData, delimiter=',')   # X is an array
