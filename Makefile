# Makefile para Detective Quest (C)
# Uso:
#   make        -> compila
#   make run    -> compila e executa
#   make clean  -> remove binários

CC      := gcc
CFLAGS  := -std=c99 -O2 -Wall -Wextra -Wshadow -Wconversion
LDFLAGS :=
TARGET  := detective_quest
SRC     := main.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)
