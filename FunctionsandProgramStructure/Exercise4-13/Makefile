CC =gcc
OBJS =app.c

all: main app.o
main: $(OBJS)
	$(CC) $? -o $@
	mv $@ ./out

%.o:%.c
	$(CC) $? -c 
	mv $@ ./build

