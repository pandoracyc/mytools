# The most simplistic Makefile

xxd: xxd.c
	$(CC) $(CFLAGS) $(LDFLAGS) -DUNIX -o xxd xxd.c ../debug.o ../debug_tcp.o

clean:
	rm -f xxd xxd.o
