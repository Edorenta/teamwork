#!/bin/bash

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
BASE=$(tput sgr0)
GOOD_MAPS=checker/good_maps/*
BAD_MAPS=checker/bad_maps/*
printf ">> ERROR MANAGEMENT\n"
printf ">> 1. bad maps\n"
for f in $BAD_MAPS
	do
		if [[ $(./lem-in < $f 2>&1 | grep "Error") ]]
		then
		    printf ">> ${f##*/} ${GREEN}OK${BASE} <<\n"
		else
		    printf ">> ${f##*/} ${RED}KO${BASE} <<\n"
		fi
	done
printf ">> 2. good maps\n"
for f in $GOOD_MAPS
	do
		if [[ $(./lem-in < $f 2>&1 | grep "Error") ]]
		then
		    printf ">> ${f##*/} ${RED}KO${BASE} <<\n"
		else
		    printf ">> ${f##*/} ${GREEN}OK${BASE} <<\n"
		fi
	done