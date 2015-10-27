#!/bin/bash

TIMEOUT=10000
INPUT_DIR=compress_samples
FINDINGS_DIR=compress_findings

MEM_LIMIT=4096 afl-fuzz -m 4096 -t $TIMEOUT -i $INPUT_DIR -o $FINDINGS_DIR \
    ./brotli_compress_fuzz @@
