#!/bin/bash

CHAMPS=code/*.s
COR=code/*.cor
mv ../../srcs/asm/asm .
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
cd bin1
for f in *.cor
	do
		diff <(xxd $f) <(xxd ../bin2/$f)
	done
