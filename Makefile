# 1. Ganti nama folder di sini sesuai keinginan

DIR = Teori/Searching
#DIR = Praktikum/Pertemuan_1/T_jam

CC = gcc
# CFLAGS dasar
CFLAGS = -I"$(DIR)" -Wall
# Flag khusus untuk debug mode
DEBUG_FLAGS = -g

# Mengambil semua file .c dari folder yang ditentukan
SRC = $(wildcard $(DIR)/*.c)

# Nama file eksekusi (output)
TARGET = program.exe

all:
	@echo "Menyusun file dari: $(DIR)"
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
	@echo "Selesai!"

# Target khusus debug agar lebih yakin -g disertakan
debug_build:
	@echo "Menyusun file mode DEBUG..."
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(TARGET)

clean:
	@if exist $(TARGET) del $(TARGET)