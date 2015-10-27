#!/bin/bash

MEM_LIMIT=4096 afl-fuzz -m 4096 -t 10000 -i samples/ -o end_findings/ -S end_to_end_$1 ./end_to_end @@

