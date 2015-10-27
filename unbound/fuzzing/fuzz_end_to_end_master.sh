#!/bin/bash

MEM_LIMIT=4096 afl-fuzz -m 4096 -t 10000 -i samples/ -o end_findings/ -M end_to_end_master ./end_to_end @@

