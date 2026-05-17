# DIR = Teori/Tugas/mhslink
DIR = Praktikum/Pertemuan_6/alter_1
# DIR = Nyoba/monitoring

SRC_C   = $(wildcard $(DIR)/*.c)
SRC_CPP = $(wildcard $(DIR)/*.cpp)

# FLAGS = -I"$(DIR)" -lncursesw -lpthread -Wall -Wextra -Wshadow -std=c++17 -O2

ifeq ($(SRC_CPP),)

    COMPILER = gcc
    SRC      = $(SRC_C)

    FLAGS = -I"$(DIR)" -Wall -Wextra -Wshadow -std=c17 -O2

    DEBUG_FLAGS = -g -O0

else

    COMPILER = g++
    SRC      = $(SRC_C) $(SRC_CPP)

    FLAGS = -I"$(DIR)" -Wall -Wextra -Wshadow -std=c++17 -O2

    DEBUG_FLAGS = -g -O0

endif

ifeq ($(OS),Windows_NT)

    TARGET = program.exe
    LDFLAGS = -lm -static-libgcc

    RM = if exist $(TARGET) del $(TARGET)

    CLEAN_MSG = @echo Delete file program ...

else

    TARGET = program
    LDFLAGS = -lm

    RM = rm -f $(TARGET)

    CLEAN_MSG = @echo "Delete file program ..."

endif

all:
	@echo "Compiler : $(COMPILER)"
	@echo "Source   : $(SRC)"
	$(COMPILER) $(FLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

run: all
	@echo --------------------------------
	@echo .                              .
	@./$(TARGET)
	@echo .                              .
	@echo --------------------------------
	@$(RM)

debug_build:
	@echo "Creating DEBUG build..."
	$(COMPILER) $(FLAGS) $(DEBUG_FLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "Ready for debugging!"

clean:
	$(CLEAN_MSG)
	@$(RM)