all: bin/a.out

bin/a.out: src/lib/quizz_create.c src/lib/quizz_run.c src/lib/quizz_data.c src/app/main.c
	gcc -Wall -I src -g -O0 -o bin/a.out src/lib/quizz_create.c src/lib/quizz_run.c src/lib/quizz_data.c src/app/main.c

.PHONY: run

run: bin/a.out
	./bin/a.out