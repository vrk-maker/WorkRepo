CC=gcc

all:main obj

main:app.c
	$(CC) $? -o $@ -lm
	mv $@ ./out

obj:app.c
	$(CC) $? -c -lm
	mv *.o ./build

clean:
	rm -f  ./build/*.o  ./out/main


