#!/bin/bash
UNBOUND_DIR=$HOME/workspace/unbound/unbound-1.5.4

cd $UNBOUND_DIR
make clean && CC='afl-clang -m32' ./configure --enable-static --enable-static-exe && AFL_USE_ASAN=1 AFL_HARDEN=1 make -j6
