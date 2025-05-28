#!/bin/bash

make
P=./push_swap
WHITE='\033[37m'
RED='\033[31m'
BLUE='\033[34m'
GREEN='\e[0;32m'

HTEST=1 2 5 3 4 6

echo -e "$BLUE Probando con 0 y 1 args$WHITE"
$P
$P 1
$P +42
$P -42
status=$?
if [ $status -eq 0 ]; then
    echo -e "$GREEN Ya 0 y 1 args correcto"
else
    echo -e "$RED No ordenados, error: $status."
fi


echo -e "$BLUE Probando con 2 args$WHITE"
$P +42 -42
$P -42 +42
status=$?
if [ $status -eq 0 ]; then
    echo -e "$GREEN Ya 2 args correcto"
else
    echo -e "$RED No ordenados, error: $status."
fi

echo -e "$BLUE Probando con 3 args$WHITE"
$P 1 2 3
$P 1 3 2
$P 2 3 1
$P 2 1 3
$P 3 1 2
$P 3 2 1
status=$?
if [ $status -eq 0 ]; then
    echo -e "$GREEN Ya 3 args correcto"
else
    echo -e "$RED No ordenados, error: $status."
fi

