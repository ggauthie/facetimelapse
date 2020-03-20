CC=gcc
CFLAGS=-Wall -pedantic-errors
LDFLAGS=

DEBUG=no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif


main: main.o test.o functions.o
    $(CC) -o $@ $? $(LDFLAGS)

main.o: main.c functions.h structures.h test.h
	$(CC) -o $@ -c $< $(CFLAGS)
	
test.o : test.c test .h functions.h structures.h
    $(CC) -o $@ -c $< $(CFLAGS)
    
functions.o: functions.c functions.h structures.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o *~
	rm -f main