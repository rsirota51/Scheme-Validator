# OS identification from: https://stackoverflow.com/questions/714100/os-detecting-makefile
OS := $(shell uname -s)

ifeq ($(OS), Darwin) 
  CUNIT_PATH_PREFIX = /usr/local/Cellar/cunit/2.1-3/
  CUNIT_DIRECTORY = cunit
endif
ifeq ($(OS), Linux) 
  CUNIT_PATH_PREFIX = /util/CUnit/
  CUNIT_DIRECTORY = CUnit/
endif

OBJECTS = schemeValidator.o 
EXECUTABLE = schemeValidatorTests

CC = gcc
CFLAGS = -g -Wall -O0 -fprofile-arcs -ftest-coverage -std=c11

schemeValidator.o: schemeValidator.c
	$(CC) $(CFLAGS) -c schemeValidator.c

tests: $(OBJECTS) schemeValidatorTests.c
	$(CC) $(CFLAGS) -L $(CUNIT_PATH_PREFIX)lib  -I $(CUNIT_PATH_PREFIX)include/$(CUNIT_DIRECTORY) $(OBJECTS) schemeValidatorTests.c -o $(EXECUTABLE) -lcunit -lgcov 

.PHONY: clean
clean:
	rm -rf *~ *.o $(EXECUTABLE) *.xml *.gc?? *.dSYM 
