DIR = Teori/Tugas/mhslink
# DIR = Praktikum/Pertemuan_5/adtStack
# DIR = Nyoba/linked_list

CC = g++
# CC = gcc

CFLAGS = -I"$(DIR)" -Wall -Wextra -Wshadow -std=c++17 -O2
# CFLAGS = -I"$(DIR)" -Wall -Wextra -Wshadow -std=c17 -O2

DEBUG_FLAGS = -g -O0

# SRC = $(wildcard $(DIR)/*.c)
SRC = $(wildcard $(DIR)/*.cpp)

ifeq ($(OS),Windows_NT)
    # Pengaturan Windows

    TARGET = program.exe
    LDFLAGS = -lm -static-libgcc
    RM = if exist $(TARGET) del $(TARGET)
    FIX_PATH = $(subst /,\,$1)
    CLEAN_MSG = @echo Delete file program (Windows)...
else
    # Pengaturan Linux/macOS
	
    TARGET = program
    LDFLAGS = -lm
    RM = rm -f $(TARGET)
    FIX_PATH = $1
    CLEAN_MSG = @echo "Delete file program (Linux)..."
endif

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: all
	@echo --------------------------------
	@echo .                              .
	@./$(TARGET)
	@echo .                              .
	@echo --------------------------------
	@$(RM)

debug_build:
	@echo "Creating DEBUG build..."
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "Ready for debugging!"

clean:
	$(CLEAN_MSG)
	@$(RM)