CC=gcc
 
all:main obj

main: strnindex.c mgetline.c itoa.c reverse.c getntop.c
	$(CC) $? -o $@
	mv $@ ./out
   
obj: strnindex.c mgetline.c itoa.c reverse.c getntop.c
	$(CC) $? -c
	mv *.o ./build
  
clean:
	rm -f  ./build/*.o  ./out/main

