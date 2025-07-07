CC = gcc -Wall -Werror -Wextra -std=c11
OS := $(shell uname -s)

ifeq ($(OS),Linux)
    Flags = -lcheck  -lm -lrt -lpthread -lsubunit
else
    Flags = -lcheck -lm -lpthread
endif


all: clean s21_matrix.a
 
s21_matrix.a:
	$(CC) -c *.c $(Flags)
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a
	rm *.o

test: clean
	$(CC) --coverage *.c tests/*.c -o test $(Flags)
	./test

gcov_report: test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html

clang:
	clang-format -style=Google -n *.c *.h

clean:
	rm -rf test s21_matrix.a *.gcno *.info *.gcda report *.dSYM
