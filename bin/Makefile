CC=gcc
CFLAGS=-c -I$(INC) -I$(CFG) -w -std=c99 -Wall

INC=../inc/
SRC=../src/
CFG=../cfg/

LIBS=
OBJS=main.o pi2c.o project.o

all: run

run: out
	@./out

.PHONY: all run

out: $(OBJS)
	$(CC) $(OBJS) -o out $(LIBS)

main.o: $(SRC)main.c
	$(CC) $(CFLAGS) $(SRC)main.c

pi2c.o: $(SRC)pi2c.c $(INC)pi2c.h
	$(CC) $(CFLAGS) $(SRC)pi2c.c

project.o: $(SRC)project.c $(INC)project.h
	$(CC) $(CFLAGS) $(SRC)project.c

d21.o: $(SRC)d21.c $(INC)d21.h
	$(CC) $(CFLAGS) $(SRC)d21.c
clean:
	@echo "Cleaning..."
	rm *.o out
