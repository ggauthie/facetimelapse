CC=gcc
CFLAGS = -Wall -Wextra -pedantic-errors
LDFLAGS = -lm -lSDL2
DEBUG=no
FILE =
ifeq ($(DEBUG),yes)
CFLAGS+= -g
endif

all : ex

ex : SDL_main.o SDL.o
	$(CC) $^ $(LDFLAGS) -o $@

SDL_main.o : SDL_fonction.h
SDL.o: SDL_fonction.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o *~
	rm -f ex

