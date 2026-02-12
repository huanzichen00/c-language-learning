CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
TARGET = dyn_int_array
SRC = ../day12/dyn_int_array.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	printf "5 3 8 -2 7 0\n" | ./$(TARGET)

clean:
	rm -f $(TARGET) *.o
