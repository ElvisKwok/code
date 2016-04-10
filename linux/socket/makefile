CC=g++

echoServer: echoServer.o
	$(CC) echoServer.o -o echoServer

echoServer.o:
	$(CC) -c echoServer.cc -o echoServer.o

clean:
	rm -f *.o echoServer
