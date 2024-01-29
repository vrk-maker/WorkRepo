CC=gcc
 
all:main obj

main: custtrcat.c custcpy.c custcmp.c
	$(CC) $? -o $@
	mv $@ ./out
   
obj: custtrcat.c custcpy.c custcmp.c
	$(CC) $? -c
	mv *.o ./build
  
clean:
	rm -f  ./build/*.o  ./out/main

