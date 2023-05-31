MAJOR_VERSION = 0
MINOR_VERSION = 3
PATH_VERSION = 0
ARCH = amd64
PROJECT_NAME = icemoon

CC = gcc
HEADER_DIR = ./src/include/
SRC_DIR = ./src/
OBJ_DIR = ./obj/
BUILD_DIR = ./build
RESOURCES_DIR = ./resources

BIN_NAME = $(PROJECT_NAME).elf
TARGET_DIR = $(BUILD_DIR)/$(PROJECT_NAME)_$(MAJOR_VERSION).$(MINOR_VERSION).$(PATH_VERSION)_$(ARCH)
TARGET = $(TARGET_DIR)/$(BIN_NAME)

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CSTAND = gnu99

CFLAGS = -std=$(CSTAND) -D__PRJ_NAME__='"$(PROJECT_NAME)"' -D$(ARCH) -g -O0 -Wall
PKGLIBS = `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0`

# Use only this flags order : gcc <flags> <objs> < -l lib> -o <out>

$(TARGET) : $(OBJ)
	#
	# *** SETUP BUILD DIR ***
	mkdir -p $(TARGET_DIR)
	mkdir $(TARGET_DIR)/resources
	cp -nr $(RESOURCES_DIR)/* $(TARGET_DIR)/resources/
	# *** END SETUP BUILD DIR ***
	#
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(PKGLIBS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(PKGLIBS)

clean :
	rm -frfr $(BUILD_DIR)/*
	rm -frfr $(BUILD_DIR)/*
	rm -frfr $(OBJ_DIR)*

instreq:
	apt-get install libgtk-3-dev
	apt-get install libwebkit2gtk-4.0-dev

deb:
	# BUILD DEB PKG

install:
	mkdir -p /usr/share/$(PROJECT_NAME)
	cp -rf $(TARGET_DIR)/* /usr/share/$(PROJECT_NAME)/
	cp -rf debian/icemoon/usr/share/applications/icemoon.desktop /usr/share/applications/$(PROJECT_NAME).desktop
