# Linux

# DIR = Teori/d_link_list
DIR = Praktikum/Pertemuan_4/linkedlist
# DIR = Nyoba/linked_list

# CC = g++
CC = gcc

# CFLAGS dasar
# CFLAGS = -I "$(DIR)" -Wall -Wextra -std=c++17 -O2
CFLAGS = -I "$(DIR)" -Wall -Wextra -std=c11 -O2

# Flag khusus untuk debug mode
DEBUG_FLAGS = -g -O0

# Flag Linker (Math library)
LDFLAGS = -lm

# Mengambil semua file .c dari folder yang ditentukan
SRC = $(wildcard $(DIR)/*.c)
# SRC = $(wildcard $(DIR)/*.cpp)

# Nama file eksekusi (output)
TARGET = program

all:
	@echo "Creating file release : $(DIR)"
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "Done! Program ready to run..."

run: all
	@echo "--------------------------------"
	@echo "                                "
	@./$(TARGET)
	@echo "                                "
	@echo "--------------------------------"
	@echo "Delete file program..."
	@rm -f $(TARGET)


debug_build:
	@echo "Creating file DEBUG..."
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "Done! Ready to debugging..."

clean:
	@rm -f $(TARGET)
	@echo "Delete file program..."