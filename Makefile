main: bin/main

bin/main: build/main.o build/function.o build/menu.o
	gcc -Wall -Werror build/main.o build/function.o build/menu.o -o bin/main -lncurses

build/main.o: src/main.c
	gcc -std=c99 -I includes -Wall -lncurses -ltinfo -Werror -c src/main.c -o build/main.o

build/function.o: src/function.c
	gcc -std=c99 -Wall -Werror -c src/function.c -o build/function.o

build/menu.o: src/menu.c
	gcc -std=c99 -Wall -Werror -c src/menu.c -o build/menu.o

.PHONY : clean
clean:
	rm -rf build/*.o
