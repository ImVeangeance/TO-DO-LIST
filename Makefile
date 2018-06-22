main: bin/main

bin/main: build/main.o build/function.o
	gcc -Wall -Werror build/main.o build/function.o -o bin/main -lncurses

build/main.o: src/main.c
	gcc -std=c99 -I includes -Wall -lncurses -ltinfo -Werror -c src/main.c -o build/main.o

build/function.o: src/function.c
	gcc -std=c99 -Wall -Werror -c src/function.c -o build/function.o

.PHONY : clean
clean:
	rm -rf build/*.o
