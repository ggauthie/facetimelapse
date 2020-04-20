CC=gcc
CFLAGS=-Wall -pedantic-errors -MMD
LDFLAGS= -lm -lcmocka

DEBUG=no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif

all: main test

MYTEST=no
ifeq ($(MYTEST),yes)
all: UTest_functions run_test
endif

main: main.o functions.o BMPFile.o fichier.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c BMPFile.h
	$(CC) $(CFLAGS) -c $< -o $@

BMPFile.o: BMPFile.c BMPFile.h fichier.h functions.h structures.h
	$(CC) $(CFLAGS) -c $< -o $@

fichier.o: fichier.c fichier.h
	$(CC) $(CFLAGS) -c $< -o $@

functions.o: functions.c functions.h structures.h
	$(CC) -o $@ -c $< $(CFLAGS)

test: test.o functions.o
	$(CC) -o $@ $^ $(LDFLAGS)

test.o : test.c
	$(CC) -o $@ -c $< $(CFLAGS)

UTest_functions: LDFLAGS+= -Wl, --wrap=rand -lcmocka -coverage
UTest_functions: CFLAGS+= -coverage
UTest_functions: UTest_functions.o functions_gcov.o
	$(CC) $^ $(LDFLAGS) -o $@

run_test: main UTest_functions
	./UTest_functions; \
	lcov -- capture --directory . --output-file coverage.info ; \
	genhtml coverage.info -output-directory out ; \
	valgrind ./$<

functions_gcov.o: functions.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm -f *.o *~ main UTest_functions *.d *.gcno *gcda *.gcov \
	*.info *.log -r out -f

#handle header dependencies with -MMD option
include $(wildcard .d)
