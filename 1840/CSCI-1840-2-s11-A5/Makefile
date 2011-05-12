# Client and Server compile.

all :	client server

client :	client.c portdefine.h srec.h linked_list.h
	gcc -g -Wall -ansi -pedantic -o client client.c

server : 	server.c portdefine.h srec.h linked_list.h
	gcc -g -Wall -ansi -pedantic -o server server.c

clean :
	rm server client 

