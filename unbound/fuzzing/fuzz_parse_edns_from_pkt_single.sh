#!/bin/bash

MEM_LIMIT=4096 afl-fuzz -m 4096 -t 10000 -i edns_samples/ -o edns_findings/ ./parse_edns_from_pkt_fuzz @@
