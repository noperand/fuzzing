#!/bin/bash

BROTLI_DIR=$PWD/brotli
BROTLI_ENC=$BROTLI_DIR/enc
BROTLI_DEC=$BROTLI_DIR/dec

cd $BROTLI_ENC
make clean && CXX='afl-g++ -m32' AFL_HARDEN=1 AFL_USE_ASAN=1 make

cd $BROTLI_DEC
make clean && CC='afl-gcc -m32' AFL_HARDEN=1 AFL_USE_ASAN=1 make
