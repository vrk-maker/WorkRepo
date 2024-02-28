CC=gcc
SRC=$(wildcard ./*.c) 

all: main obj

main: $(SRC)
	$(CC) $^ -o $@ 
	mv $@ ./out

obj: $(SRC:.c=.o) 
	$(CC) -c $^
	mv *.o ./build

clean:
	rm -f build/*.o out/main