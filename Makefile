DIR = Teori/linked_list
# DIR = Praktikum/Pertemuan_3/tabint
# DIR = Nyoba/linked_list

CC = g++
# CC = gcc

# CFLAGS dasar
CFLAGS = -I"$(DIR)" -Wall -Wextra -std=c++17 -O2
# CFLAGS = -I"$(DIR)" -Wall -Wextra -std=c11 -O2

# Flag khusus untuk debug mode
DEBUG_FLAGS = -g -O0

# Flag Linker (Math library & Portabilitas UCRT)
LDFLAGS = -lm -static-libgcc

# Mengambil semua file .c dari folder yang ditentukan
# SRC = $(wildcard $(DIR)/*.c)
SRC = $(wildcard $(DIR)/*.cpp)

# Nama file eksekusi (output)
TARGET = program.exe

all:
	@echo "Menyusun file rilis dengan optimasi UCRT dari: $(DIR)"
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "Selesai! Program siap dijalankan dengan cepat."

debug_build:
	@echo "Menyusun file mode DEBUG..."
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "Selesai! Siap untuk debugging."

clean:
	@if exist $(TARGET) del $(TARGET)
	@echo "File eksekusi berhasil dihapus."