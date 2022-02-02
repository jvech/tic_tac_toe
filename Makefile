objects = src/main.o src/board.o src/game.o

compile: $(objects)
	gcc -o main $(objects)

debug: $(objects)
	gcc -g -o main $(objects)

main.o: src/main.c src/main.h

board.o: src/board.c src/board.h

game.o: src/game.c src/game.h

run: compile
	./main

clean:
	rm $(objects)
