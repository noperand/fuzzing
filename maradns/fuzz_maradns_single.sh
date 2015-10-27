#!/bin/bash

MEM_LIMIT=4096 afl-fuzz -m 4096 -t 10000 -i samples -o findings ./deadwood_udp_request_fuzz @@

