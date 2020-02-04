for j in 10 30 70 150 250
do
echo $j > "energy.txt"
for i in 3 4 5 6 7 8 9 35 36 37 38 39 40 41 42 43 44 45 46 47 48
do
	fname="$i.$j.mac"
	fname2="$i.$j.sh"
	fname3="$i.$j.res"
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
	echo "/run/beamOn 10000" >> $fname

	echo "echo $j > energy.txt" >> $fname2
	echo "./LXe ../macs/$fname" >> $fname2
	echo "mv PMT.dat $fname3" >> $fname2

 # your-unix-command-here
done
done
