#!/bin/bash

CHAMPS=code/*.s

for f in $CHAMPS
	do
		./asm $f
	done
