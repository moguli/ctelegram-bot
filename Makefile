OUTFILE=echobot

COMPILE_FLAGS = -c -ggdb
LINK_FLAGS = -lcurl 

all:
	gcc *.c $(COMPILE_FLAGS)
	gcc *.o -o $(OUTFILE) $(LINK_FLAGS)
	rm *.o
