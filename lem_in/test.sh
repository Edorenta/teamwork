#!/bin/bash

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
BASE=$(tput sgr0)

printf ""
if [[ $(./lem-in < check/bad_maps/bad_map00 | grep "Error") ]]
then
    printf ">> ${GREEN}OK${BASE} <<\n"
else
    printf ">> ${RED}KO${BASE} <<\n"
fi
