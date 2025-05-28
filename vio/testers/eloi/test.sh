#!/bin/bash

make
P=./push_swap
WHITE='\033[37m'
RED='\033[31m'
BLUE='\033[34m'
GREEN='\e[0;32m'

HTEST=1 2 5 3 4 6


#Prueba 1
echo -e "$BLUE Probando con ya ordenados$WHITE"
$P 1
$P 1 2
$P 1 2 3
$P 1 2 4 55
$P 1 2 5 56 65
$P 1 2 6 99 992 1000
$P -1 2 7 8 9 11 43 53
$P -11 -2 7 12 32 435 654 666

# Capture the exit status
status=$?

if [ $status -eq 0 ]; then
    echo -e "$GREEN Ya ordenados correcto"
else
    echo -e "$RED No ordenados, error: $status."
fi

echo -e "$BLUE Probando con orden invertido$WHITE"

$P 2 1
$P 3 2 1
$P 4 3 2 1
$P 5 4 3 2 1
$P 6 5 4 3 2 1
$P -1 -2 -3 -4 -5 -6 -7
$P 0 1 2 3 4 5 6 7 8

status=$?

if [ $status -eq 0 ]; then
    echo -e "$GREEN Invertido se ordena correcto"
else
    echo -e "$RED No ordenados, error: $status."
fi
