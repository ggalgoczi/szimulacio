
for j in -65 0 65 # X COORDINATE
do
for i in -27.5 0 27.5 # Y COORDINATE
do
	fname="$i.$j.mac"
	fname2="$i.$j.sh"
	fname3="$i.$j.res"

	echo "$j $i"
	echo "/run/initialize" > $fname
	echo "/gun/position $i 17.5 $j mm" >> $fname
	echo "/run/beamOn 10000" >> $fname
	echo "./LXe ../macs/$fname" >> $fname2
	echo "mv PMT1.dat $fname3" >> $fname2
	echo "mv PMT1.dat $fname3" >> $fname2"_2"

 # your-unix-command-here
done
done
