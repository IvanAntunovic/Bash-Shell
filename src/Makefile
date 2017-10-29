# GBS Shell Makefile
# Author: Ivan A

CC = gcc
CFLAGS = -Wall -g
OBJ = gbsh.o

all: gbsh

gbsh: $(OBJ) MatrixCalculator.o ShellCommandManager.o ShellData.o ShellDataManager.o ShellView.o ShellViewController.o
	$(CC) $(OBJ) MatrixCalculator.o ShellCommandManager.o ShellData.o ShellDataManager.o ShellView.o ShellViewController.o -lpthread -o gbsh

gbsh.o: gbsh.c
	$(CC) -c gbsh.c

MatrixCalculator.o: MatrixCalculator.c MatrixCalculator.h
	$(CC) -c MatrixCalculator.c

ShellCommandManager.o: ShellCommandManager.c ShellCommandManager.h
	$(CC) -c ShellCommandManager.c

ShellData.o: ShellData.c ShellData.h
	$(CC) -c ShellData.c

ShellDataManager.o: ShellDataManager.c ShellDataManager.h
	$(CC) -c ShellDataManager.c

ShellView.o: ShellView.c ShellView.h
	$(CC) -c ShellView.c

ShellViewController.o: ShellViewController.c ShellViewController.h
	$(CC) -c ShellViewController.c

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o


