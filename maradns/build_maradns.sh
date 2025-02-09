#!/bin/bash
ORIG_DIR=$PWD
MARADNS_DIR=$PWD/maradns-2.0.13

cd $MARADNS_DIR
./configure # must be run first, no options supported really

CC='afl-gcc -m32' AFL_HARDEN=1 AFL_USE_ASAN=1 make

cd $ORIG_DIR
make clean && AFL_HARDEN=1 AFL_USE_ASAN=1 make
