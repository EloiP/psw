#!/bin/bash
P=./push_swap
ARG=1 3 2 4 5
C=./checker_linux

$P $ARG | $C $ARG
