BROTLI_DIR=$(PWD)/brotli
BROTLI_ENC=$(BROTLI_DIR)/enc
BROTLI_DEC=$(BROTLI_DIR)/dec

CC=afl-gcc
CXX=afl-g++

CXFLAGS=-m32 -Wall -I$(BROTLI_DIR)
CFLAGS=$(CXFLAGS)

ENC_FUZZER=brotli_compress_fuzz
DEC_FUZZER=brotli_decompress_fuzz

EVERYTHING=$(ENC_FUZZER) $(DEC_FUZZER)

all : $(EVERYTHING)

$(ENC_FUZZER) : $(ENC_FUZZER).cc
	$(CXX) $(CXFLAGS) -o $(ENC_FUZZER) $(ENC_FUZZER).cc $(BROTLI_ENC)/*.cc

$(DEC_FUZZER) : $(DEC_FUZZER).c
	$(CC) $(CFLAGS) -o $(DEC_FUZZER) $(DEC_FUZZER).c $(BROTLI_DEC)/*.c

clean :
	rm -f $(EVERYTHING)
