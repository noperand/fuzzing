UNBOUND_DIR=$(HOME)/workspace/unbound/unbound-1.5.4
UNBOUND_LIBDIR=$(UNBOUND_DIR)/.libs

DAEMON_OBJ=$(UNBOUND_LIBDIR)/acl_list.o
DAEMON_SRC=$(UNBOUND_DIR)/daemon/daemon.c $(UNBOUND_DIR)/daemon/worker.c $(UNBOUND_DIR)/daemon/stats.c $(UNBOUND_DIR)/daemon/remote.c
# $(UNBOUND_LIBDIR)/acl_list.o $(UNBOUND_LIBDIR)/log.o $(UNBOUND_LIBDIR)/stats.o $(UNBOUND_LIBDIR)/remote.o $(UNBOUND_LIBDIR)/cachedump.o

CC=afl-clang
CFLAGS=-m32 -I$(UNBOUND_DIR) -pthread
#REQUEST_FUZZER=worker_handle_request_fuzz
DNAME_FUZZER=dname_str_fuzz

EDNS_FUZZER=parse_edns_from_pkt_fuzz

END_TO_END_FUZZER=end_to_end

# all : $(REQUEST_FUZZER) $(DNAME_FUZZER)
all : $(DNAME_FUZZER) $(EDNS_FUZZER) $(END_TO_END_FUZZER)

#$(MYLIBUNBOUND) : $(REQUEST_FUZZER).c
#	cp $(UNBOUND_LIBDIR)/libunbound.a $(MYLIBUNBOUND)
#	ar rcs $(MYLIBUNBOUND) $(UNBOUND_LIBDIR)/daemon.o $(UNBOUND_LIBDIR)/worker.o

#$(REQUEST_FUZZER) : $(REQUEST_FUZZER).c
#	$(CC) $(CFLAGS) -L$(UNBOUND_LIBDIR) -o $(REQUEST_FUZZER) $(DAEMON_SRC) $(REQUEST_FUZZER).c $(DAEMON_OBJ) -ldl -lssl -lcrypto -lunbound

$(DNAME_FUZZER) : $(DNAME_FUZZER).c
	$(CC) $(CFLAGS) -o $(DNAME_FUZZER) $(DNAME_FUZZER).c $(UNBOUND_DIR)/util/data/dname.c $(UNBOUND_DIR)/util/storage/lookup3.c $(UNBOUND_DIR)/util/log.c

$(EDNS_FUZZER) : $(EDNS_FUZZER).c
	$(CC) $(CFLAGS) -o $(EDNS_FUZZER) $(EDNS_FUZZER).c $(UNBOUND_DIR)/sldns/sbuffer.c $(UNBOUND_DIR)/util/data/msgparse.c $(UNBOUND_DIR)/util/storage/lookup3.c $(UNBOUND_DIR)/util/log.c $(UNBOUND_DIR)/util/data/dname.c $(UNBOUND_DIR)/util/regional.c $(UNBOUND_DIR)/sldns/rrdef.c $(UNBOUND_DIR)/sldns/parseutil.c

$(END_TO_END_FUZZER) : $(END_TO_END_FUZZER).c
	$(CC) $(CFLAGS) -L$(UNBOUND_LIBDIR) -o $(END_TO_END_FUZZER) $(END_TO_END_FUZZER).c $(UNBOUND_DIR)/sldns/sbuffer.c $(UNBOUND_DIR)/util/data/msgparse.c $(UNBOUND_DIR)/util/storage/lookup3.c $(UNBOUND_DIR)/util/log.c $(UNBOUND_DIR)/util/data/dname.c $(UNBOUND_DIR)/util/regional.c $(UNBOUND_DIR)/sldns/rrdef.c $(UNBOUND_DIR)/sldns/parseutil.c $(UNBOUND_DIR)/util/data/msgreply.c $(UNBOUND_DIR)/util/net_help.c -lssl -lcrypto -lunbound

clean :
	rm -f $(REQUEST_FUZZER) *~ $(DNAME_FUZZER)

