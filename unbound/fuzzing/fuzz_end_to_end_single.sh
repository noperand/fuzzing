#!/bin/bash

MEM_LIMIT=4096 afl-fuzz -m 4096 -t 10000 -i ramdisk/samples/ -o ramdisk/end_findings/ ./end_to_end @@

