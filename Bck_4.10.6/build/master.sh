#!/bin/bash

rm "PMT.dat"

inputfilename="test.txt"


if [ "$#" -eq 0 ]; then
    inputfilename="test.txt"
fi

if [ "$#" -eq 1 ]; then
	inputfilename=$1 # file listing all parts and their energy spectra sources
fi

if [ ! -f $inputfilename ]; then
  echo "File not found!"
  exit 0
fi


while IFS='' read -r line || [[ -n "$line" ]]; do
	rm "PMT.dat"
    echo "Text read from file: $line"
    #for word in $line
		#do
		#tochecked=${word##*/}  # cutting everything off before the backslashes
		#echo ${tochecked*.##} 
		#done
	thickness="$(echo $line | cut -d' ' -f1)"
#	echo $line | cut -d' ' -f2	
	sim_no="$(echo $line | cut -d' ' -f2)"
	particle="$(echo $line | cut -d' ' -f3)"
	res="$(echo $line | cut -d' ' -f4)"
	file=${res##*/}
	echo $res
	echo $res
# Print out details to sim
	echo $particle > "../build/particleforgun.txt"
	echo $res > "../build/thefileforgun.txt"
	echo $thickness > "../build/housingthickness.txt"
	
	
	# Creating mac file with GPS containing spectrum
	rm "run.mac"

	echo '
	########################################################################
	#                 Albedo neutron spectrum in LEO        
	# - altitude = 600 km 
	# - inclination = 0 deg
	# - as obtained from QinetiQ for RC = 5 GV and solar minimum
	# - R. Campana (INAF/IASF Bologna)
	# - Ref: Campana et al. (2013) Exp. Astr. 36, 451
	# - Ref: Reference: ECSS-E-ST-10-04C figure I-7
	########################################################################
	/run/initialize

	#/run/verbose 1

	# Set General Particle Source options
/gps/pos/type Surface
/gps/pos/shape Sphere
/gps/pos/centre 0. 0. 0. cm
/gps/pos/radius 50 m
/gps/ang/type cos   
/gps/ang/mintheta    0.000E+00 deg
/gps/ang/maxtheta    0.5729 deg

# Input spectrum
/gps/particle '$particle' 
/gps/ene/type Arb
/gps/hist/type arb
' >> "run.mac"


	awk '{if($2 != 0) {print "/gps/hist/point",$1,$2}}' $res  >> "run.mac"
	echo '/gps/hist/inter Log'  >> "run.mac"
	echo '/run/beamOn' $sim_no  >> "run.mac"
	
	
	
	#for f in ../macs/*.sh; do  # or wget-*.sh instead of *.sh
	#	time bash "$f" -H  # || break # if needed 
	#	python ./anal.py
	#done

	time ./LXe run.mac # > "output_${particle}_${file}"
	echo "Particle was", $particle
	echo "Filenamee was", $outputfilename
	outputfilename="rate_${particle}_${file}_${thickness}_pmt.txt"
	mv PMT.dat $outputfilename
	#mv
done < $inputfilename


# a file listing the type of the particles and the corresponding energy spectra files



# atechozni a fileokba
#for f in ../macs/*.sh; do bash "$f"; done &> StdDump &

#python background_anal.py

# atcpzni olyan filenevvel ami a neve volt...
