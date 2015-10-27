#!/bin/bash

TIMEOUT=10000
INPUT_DIR=decompress_samples
FINDINGS_DIR=decompress_findings

MEM_LIMIT=4096 afl-fuzz -m 4096 -t $TIMEOUT -i $INPUT_DIR -o $FINDINGS_DIR \
    ./brotli_decompress_fuzz @@
