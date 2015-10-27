#!/bin/bash

MEM_LIMIT=4096 afl-fuzz -m 4096 -t 10000 -i samples/ -o dname_findings/ ./dname_str_fuzz @@
