MAJOR_VERSION = 0
MINOR_VERSION = 1
PATH_VERSION = 0
ARCH = amd64
PROJECT_NAME = facdoc

CC = gcc
SRC_DIR = ./src/
OBJ_DIR = ./obj/
BUILD_DIR = ./build

BIN_NAME = $(PROJECT_NAME).elf
TARGET_DIR = $(BUILD_DIR)/$(PROJECT_NAME)_$(MAJOR_VERSION).$(MINOR_VERSION).$(PATH_VERSION)_$(ARCH)
TARGET = $(TARGET_DIR)/$(BIN_NAME)

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CSTAND = gnu99

CFLAGS = -std=$(CSTAND) -D__PRJ_NAME__='"$(PROJECT_NAME)"' -D$(ARCH) -g -O0 -Wall

# Use only this flags order : gcc <flags> <objs> < -l lib> -o <out>

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -frfr $(BUILD_DIR)/*
	rm -frfr $(BUILD_DIR)/*
	rm -frfr $(OBJ_DIR)*

deb:
	# BUILD DEB PKG

install:
	cp $(TARGET) /bin/
