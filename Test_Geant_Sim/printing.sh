for i in {0..99}
do
	fname="$i.mac"
	fname2="$i.sh"
	fname3="$i.txt"
	alfa="$((10*$i))"
	pi=`echo "4*a(1)" | bc -l`
	rad=`echo "$alfa*($pi/180)" | bc -l`
	x=`echo "c($rad)" | bc -l`
	x=`echo "300*$x+0.00001" | bc -l`
	y=`echo "s($rad)" | bc -l`
	y=`echo "300*$y+0.00001" | bc -l`
	z=0

	echo "$x, $y"
	echo "/run/initialize" >> $fname
	echo "/gun/position $x $y $z" >> $fname
	echo "/run/beamOn 1000000" >> $fname

	echo "./LXe ../macs/$fname" >> $fname2
	echo "mv scint.txt $fname3" >> $fname2

 # your-unix-command-here

done
