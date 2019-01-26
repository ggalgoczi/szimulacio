#!/bin/bash

if [ "$#" -eq 0 ]; then
    inputfilename="masters.txt"
fi

if [ "$#" -eq 2 ]; then
	inputfilename=$1 # file listing all parts and their energy spectra sources
fi

inputfilename="master.txt"
if [ ! -f $inputfilename ]; then
  echo "File not found!"
  exit 0
fi


while IFS='' read -r line || [[ -n "$line" ]]; do
    #echo "Text read from file: $line"
    for word in $line
		do
		
		echo ${word##*/}  # cutting everything off before the backslashes
		done
done < $inputfilename


# a file listing the type of the particles and the corresponding energy spectra files



# atechozni a fileokba
#for f in ../macs/*.sh; do bash "$f"; done &> StdDump &

#python background_anal.py

# atcpzni olyan filenevvel ami a neve volt...
