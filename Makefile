CC = gcc
CFLAGS = -Wall
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

mygame: scr/main.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f mygame

run: mygame
	./mygame