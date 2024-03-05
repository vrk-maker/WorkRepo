CC=gcc
SRC=$(wildcard ./*.c) 
OBJ=$(SRC:.c=.o) 

all: main $(OBJ)

main: $(OBJ)
	$(CC) $^ -o $@ -I.
	mv $@ ./out
	mv *.o ./build

$(OBJ): $(SRC) 
	$(CC) -c $^ 
	

clean:
	rm -f build/*.o out/main
