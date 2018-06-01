#!/bin/bash
make
cd _visualizer/c
echo "<!> compiling random unique number generator"
gcc rnd_int.c -o rnd_int.exe
cd ../../
touch tmp.txt

START=1
END=${2:-20}
SUM=0
MAX=0
MIN=10000000
MEAN=0
CNT=0
STATUS="OK"

run()
{
	size=$1
	cd _visualizer/c
	./rnd_int.exe $size 1 $size > ../unsorted_list.txt
	cd ../..
	./push_swap -mto $(cat _visualizer/unsorted_list.txt) > tmp.txt
	#typeset -i CNT=$(cat tmp.txt)
	let "CNT=$(cat tmp.txt)"
	#$SUM=$(( SUM + CNT ))
	let "SUM+=$CNT"
	if [ "$CNT" -lt "$MIN" ]
	then
		let "MIN=$CNT"
	elif [ "$CNT" -gt "$MAX" ]
	then
		let "MAX=$CNT"
	fi
}

printf "Sorting ${1:-5} integers $END times:\n"
printf "\n | TEST\t| MOVES\t| STATE\t|\n"
for (( c=$START; c<=$END; c++ ))
do
	run ${1:-5}
	printf " | %d\t| %d\t| %s\t|" $c $CNT $STATUS
	echo
done

rm tmp.txt
let "MEAN = $SUM / $END"
printf " |----------------------|\n"
printf " | MIN\t| MEAN\t| MAX\t|\n"
printf ">| %d\t| %d\t| %d\t|<\n" $MIN $MEAN $MAX

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
