CC = gcc
CFLAGS = -Wall
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

OBJS = main.o map.o player.o

mygame: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

map.o: map.c game.h
	$(CC) $(CFLAGS) -c map.c

player.o: player.c game.h
	$(CC) $(CFLAGS) -c player.c

clean:
	rm -f mygame $(OBJS)

run: mygame
	./mygame