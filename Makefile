all: bin/a.out

bin/a.out: obj/lib/main.o obj/lib/lib.a
	gcc -Wall -MMD -I src -o bin/a.out obj/lib/quizz_create.o obj/lib/quizz_run.o obj/lib/quizz_data.o obj/lib/main.o

obj/lib/lib.a: obj/lib/quizz_create.o obj/lib/quizz_run.o obj/lib/quizz_data.o
	ar rcs $@ $^

obj/lib/main.o: src/app/main.c
	gcc -Wall -MMD -c -I src -o obj/lib/main.o src/app/main.c

obj/lib/quizz_create.o: src/lib/quizz_create.c
	gcc -Wall -MMD -c -I src -o obj/lib/quizz_create.o src/lib/quizz_create.c

obj/lib/quizz_run.o: src/lib/quizz_run.c
	gcc -Wall -MMD -c -I src -o obj/lib/quizz_run.o src/lib/quizz_run.c

obj/lib/quizz_data.o: src/lib/quizz_data.c
	gcc -Wall -MMD -c -I src -o obj/lib/quizz_data.o src/lib/quizz_data.c

bin/test.out: obj/test/quizz_create_test.o test/main.c obj/lib/lib.a
	gcc -Wall -MMD -I src -I thirdparty -o $@ $^

obj/test/quizz_create_test.o: test/quizz_create_test.c obj/lib/quizz_create.o 
	gcc -Wall -MMD -c -I src -I thirdparty -o $@ $^

.PHONY: run

run: bin/a.out
	./bin/a.out

.PHONY: clean

clean:
	rm bin/*.d
	rm bin/*.out
	rm obj/lib/*.o
	rm obj/test/*.o
	rm obj/test/*.d
	rm obj/lib/*.d
	rm obj/lib/*.a

.PHONY: test

test: bin/test.out
	./bin/test.out