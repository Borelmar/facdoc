TARGET = main_st

CC = gcc
SRC_DIR = ./src/
OBJ_DIR = ./obj/
BUILD_DIR = ./build

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CSTAND = gnu99

CFLAGS = -std=$(CSTAND) -O2 -Wall -Wno-unused -Wextra

# Use only this flags order : gcc <flags> <objs> < -l lib> -o <out>

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -frfr $(OBJ_DIR)*

