#!/bin/bash

CHAMPS=code/*.s
COR=code/*.cor

for f in $CHAMPS
	do
		valgrind --log-file="tmp" ./asm $f
		echo Compile $f :
		cat tmp | grep "definitely lost"
		cat tmp | grep "indirectly lost"
		rm tmp
		echo
	done
mv $COR ./bin1/

for f in $CHAMPS
	do
		./zaz_asm $f
	done
mv $COR ./bin2/

for f in ./bin1/*.cor
	do
		diff <(xxd ./bin1/$f) <(xxd ./bin2/$f)
	done
