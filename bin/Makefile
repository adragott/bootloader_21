CC=gcc
CFLAGS=-c -I$(INC) -I$(SRC) -I$(CFG) -w -std=c99 -Wall 

INC=../src/
SRC=../inc/
CFG=../cfg/

LIBS=
OBJS=main.o i2c.o project.o

all: run

run: out
	./out

.PHONY: all run

out: $(OBJS)
	$(CC) $(OBJS) -o out $(LIBS)

main.o: $(SRC)main.c
	$(CC) $(CFLAGS) $(SRC)main.c

i2c.o: $(SRC)i2c.c $(INC)i2c.h
	$(CC) $(CFLAGS) $(SRC)i2c.c

project.o: $(SRC)project.c $(INC)project.h
	$(CC) $(CFLAGS) $(SRC)project.c

clean:
	@echo "Cleaning..."
	rm *.o out
