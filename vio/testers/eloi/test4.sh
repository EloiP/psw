#!/bin/bash

make
P=./push_swap
WHITE='\033[37m'
RED='\033[31m'
BLUE='\033[34m'
GREEN='\e[0;32m'

HTEST=1 2 5 3 4 6

echo -e "$BLUE Probando con 4 args$WHITE"
$P 1 2 3 4
$P 1 2 4 3
$P 1 3 2 4
$P 1 3 4 2
$P 1 4 2 3
$P 1 4 3 2
$P 2 1 3 4
$P 2 1 4 3
$P 2 3 1 4
$P 2 3 4 1
$P 2 4 1 3
$P 2 4 3 1
$P 3 1 2 4
$P 3 1 4 2
$P 3 2 1 4
$P 3 2 4 1
$P 3 4 1 2
$P 3 4 2 1
$P 4 1 2 3
$P 4 1 3 2
$P 4 2 1 3
$P 4 2 3 1
$P 4 3 1 2
$P 4 3 2 1
status=$?
if [ $status -eq 0 ]; then
    echo -e "$GREEN Ya 4 args correcto"
else
    echo -e "$RED No ordenados  error: $status."
fi

