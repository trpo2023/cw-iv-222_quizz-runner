all: bin/a.out

bin/a.out: obj/lib/quizz_create.o obj/lib/quizz_run.o obj/lib/quizz_data.o obj/lib/main.o
	gcc -Wall -I src -O0 -g -o bin/a.out obj/lib/quizz_create.o obj/lib/quizz_run.o obj/lib/quizz_data.o obj/lib/main.o

obj/lib/main.o: src/app/main.c
	gcc -Wall -c -I src -O0 -g -o obj/lib/main.o src/app/main.c

obj/lib/quizz_create.o: src/lib/quizz_create.c
	gcc -Wall -c -I src -O0 -g -o obj/lib/quizz_create.o src/lib/quizz_create.c

obj/lib/quizz_run.o: src/lib/quizz_run.c
	gcc -Wall -c -I src -O0 -g -o obj/lib/quizz_run.o src/lib/quizz_run.c

obj/lib/quizz_data.o: src/lib/quizz_data.c
	gcc -Wall -c -I src -O0 -g -o obj/lib/quizz_data.o src/lib/quizz_data.c

.PHONY: run

run: bin/a.out
	./bin/a.out

.PHONY: clean

clean: bin/a.out obj/lib/*.o
	rm bin/a.out
	rm obj/lib/*.o
