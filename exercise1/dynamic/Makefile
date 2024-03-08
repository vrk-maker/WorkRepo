CC=gcc
SRC=./*.c 
OBJ=$(SRC:.c=.o) 
LIB=libsample.so

all:library main

main: $(OBJ)
	$(CC) $^ -o $@ -L. -lsample
	mv $@ ./out
	mv *.o ./build

$(OBJ): $(SRC) 
	$(CC) -c $^

library: $(OBJ)
	$(CC) -shared -fPIC -o $(LIB) $(filter-out app.o, $^)
	

clean:
	rm -f build/*.o out/main