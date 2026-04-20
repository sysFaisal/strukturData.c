# Windows

# DIR = Teori/d_linked_list
DIR = Praktikum/Pertemuan_5/stacklinked
# DIR = Nyoba/linked_list

# CC = g++
CC = gcc

# CFLAGS dasar
# CFLAGS = -I"$(DIR)" -Wall -Wextra -Wshadow -std=c++17 -O2
CFLAGS = -I"$(DIR)" -Wall -Wextra -Wshadow -std=c17 -O2

# Flag khusus untuk debug mode
DEBUG_FLAGS = -g -O0

# Flag Linker (Math library & Portabilitas UCRT)
LDFLAGS = -lm -static-libgcc

# Mengambil semua file .c dari folder yang ditentukan
SRC = $(wildcard $(DIR)/*.c)
# SRC = $(wildcard $(DIR)/*.cpp)

# Nama file eksekusi (output)
TARGET = program.exe

all:
	@echo Creating file release : $(DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo Done! Program ready to run...

run: all
	@echo --------------------------------
	@echo .                              .
	@echo .                              . 
	@./$(TARGET)
	@echo .                              .
	@echo .                              . 
	@echo --------------------------------
	@echo Delete file program...
	@if exist $(TARGET) del $(TARGET)

debug_build:
	@echo Creating file DEBUG...
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo Done! Ready to debugging...

clean:
	@if exist $(TARGET) del $(TARGET)
	@echo Delete file program...