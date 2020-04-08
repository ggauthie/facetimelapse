CC=gcc
CFLAGS = -Wall -Wextra -pedantic-errors
LDFLAGS = -lSDL2 -lm
DEBUG=no
FILE =
ifeq ($(DEBUG),yes)
CFLAGS+= -g
endif

all : ex

ex : SDL_main.o SDL.o functions.o BMPFile.o  fichier.o
	$(CC) $^ $(LDFLAGS) -o $@

SDL_main.o : SDL_fonction.h BMPFile.h
SDL.o: SDL_fonction.h 
functions.o: functions.h structures.h
BMPFile.o: BMPFile.h fichier.h functions.h structures.h
fichier.o: fichier.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o *~
	rm -f ex
