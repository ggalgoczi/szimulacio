#!/bin/bash

rm "PMT1.txt"
rm "PMT2.txt"
rm "totalfluxes.txt"

inputfilename="master.txt"


if [ "$#" -eq 0 ]; then
    inputfilename="master.txt"
fi

if [ "$#" -eq 1 ]; then
	inputfilename=$1 # file listing all parts and their energy spectra sources
fi

if [ ! -f $inputfilename ]; then
  echo "File not found!"
  exit 0
fi


while IFS='' read -r line || [[ -n "$line" ]]; do
	rm "PMT1.txt"
	rm "PMT2.txt"
    #echo "Text read from file: $line"
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
# Print out details to sim
	echo $particle > "../build/particleforgun.txt"
	echo $res > "../build/thefileforgun.txt"
	echo $thickness > "../build/housingthickness.txt"
	echo "/run/initialize" > "../build/run.mac"
	echo "/run/beamOn ${sim_no}" >> "../build/run.mac"
	
	#for f in ../macs/*.sh; do  # or wget-*.sh instead of *.sh
	#	time bash "$f" -H  # || break # if needed 
	#	python ./anal.py
	#done

		
	time ./LXe run.mac > "output_${particle}${file}"
	outputfilename="rate_${particle}${file}1_pmt.txt"
	outputfilename2="rate_${particle}${file}2_pmt.txt"
	mv PMT1.txt outputfilename
	mv PMT2.txt outputfilename2
	#mv
done < $inputfilename


# a file listing the type of the particles and the corresponding energy spectra files



# atechozni a fileokba
#for f in ../macs/*.sh; do bash "$f"; done &> StdDump &

#python background_anal.py

# atcpzni olyan filenevvel ami a neve volt...
