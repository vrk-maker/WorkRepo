CC=gcc
SRC=$(wildcard ./*.c)  # Use wildcard to find all .c files in the current directory

all: main obj

main: $(SRC)
	$(CC) $^ -o $@ -I.
	mv $@ ./out

obj: $(SRC:.c=.o)  # Generate object files from source files
	$(CC) -c $^
	mv *.o ./build

clean:
	rm -f build/*.o out/main
