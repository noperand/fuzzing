#!/bin/bash

honggfuzz -f samples -W honggfuzz -q -v -l honggfuzz.log -- ./dname_str_fuzz ___FILE___

