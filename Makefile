CFLAGS+=-Wall -Wextra -O2
LDFLAGS+=-lcrypto

PROG = bench.x
OBJS = hash.o clocks.o
SRCS = hash.c clocks.c

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(PROG)
