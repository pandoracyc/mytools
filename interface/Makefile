all: server logout
clean:
	rm -f test.log *.o *.exe
server: server.c
	gcc server.c -o server
logout: debug.o debug_tcp.o
	rm -f test.log
	touch test.log
	gcc -o logout.exe debug.o debug_tcp.o
	./logout.exe

debug.o: debug.c debug.h
	gcc -c debug.c -DDEBUG_MAIN_TEST

debug_tcp.o: debug_tcp.c debug_tcp.h
	gcc -c debug_tcp.c
