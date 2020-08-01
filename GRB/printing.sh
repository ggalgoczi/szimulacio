
for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37
do
	fname="$i.mac"
	fname2="$i.sh"
	fname3="$i.res"
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
	echo "/run/beamOn 100000" >> $fname

	echo "./LXe ../macs/$fname" >> $fname2
	echo "mv PMT.dat $fname3" >> $fname2
	
 # your-unix-command-here
done
