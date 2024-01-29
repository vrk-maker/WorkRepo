CC =gcc

all: main obj

main: app.c
	$(CC) $? -o $@
	mv $@ ./out

obj: app.c
	$(CC) $? -c
	mv *.o ./build

clean:
	rm -f  ./build/*.o ./out/main
