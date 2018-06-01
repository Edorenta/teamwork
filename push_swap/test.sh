#!/bin/bash
make
cd _visualizer/c
echo "<!> compiling random unique number generator"
gcc rnd_int.c -o rnd_int.exe
cd ../../
touch tmp.txt

run()
{
	size=$1
	cd _visualizer/c
	./rnd_int.exe $size 1 $size > ../unsorted_list.txt
	cd ../..
	./push_swap -mo $(cat _visualizer/unsorted_list.txt)
	#CNT=$(<tmp.txt)
}

START=1
END=20

echo "Sorting ${1} integers $END times:" 
for (( c=$START; c<=$END; c++ ))
do
	run ${1}
	#echo $CNT
done

: <<'EOC'
for number in {$i..$max}
	do
	   run 5
	done
for number in {$i..$max}
	do
	   run 10
	done
for number in {$i..$max}
	do
	   run 50
	done
for number in {$i..$max}
	do
	   run 100
	done
for number in {$i..$max}
	do
	   run 200
	done
for number in {$i..$max}
	do
	   run 500
	done
EOC
