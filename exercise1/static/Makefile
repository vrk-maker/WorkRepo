CC=gcc
SRC=./*.c 
OBJ=$(SRC:.c=.o) 
AR =ar
LIB=libsample.a

all:library main

main: $(OBJ)
	$(CC) $^ -o $@ -L. -lsample
	mv $@ ./out
	mv *.o ./build

$(OBJ): $(SRC) 
	$(CC) -c $^

library: $(OBJ)
	$(AR) -rcs  $(LIB) $(filter-out app.o, $^)
	

clean:
	rm -f build/*.o out/main