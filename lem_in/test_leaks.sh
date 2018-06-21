#!/bin/bash

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
BASE=$(tput sgr0)
GOOD_MAPS=checker/good_maps/*
BAD_MAPS=checker/bad_maps/*

printf ">> LEAK MANAGEMENT\n"
WHAT="bytes"
WHERE="$(valgrind --tool=memcheck --leak-check=full ./lem-in 2>&1 < checker/bad_maps/ant_max_int | grep "lost")"
#res=${WHERE%$WHAT*}
res=$(echo "$WHERE" | grep -E '= [0-9]+ bytes')
echo "${res}"