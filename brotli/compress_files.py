#!/usr/bin/env python
import sys
import os
import brotli

if __name__ == "__main__":
    for item in os.listdir(os.sep.join([os.getcwd(), 'compress_samples'])):
        input_file = os.sep.join([ os.getcwd(),
                                   'compress_samples',
                                   item ])
        output_file = os.sep.join([ os.getcwd(), 
                                    'decompress_samples', 
                                    item + '.brotli' ])
        data = open(input_file, "rb").read()
        compressed = brotli.compress(data)
        open(output_file, "wb").write(compressed)

