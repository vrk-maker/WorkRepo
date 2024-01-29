CC=gcc
 
all:main obj

main: strnindex.c mgetline.c itoa.c reverse.c getntop.c
	$(CC) $? -o $@ -lm
	mv $@ ./out
   
obj: strnindex.c mgetline.c itoa.c reverse.c getntop.c
	$(CC) $? -c -lm
	mv *.o ./build
  
clean:
	rm -f  ./build/*.o  ./out/main

