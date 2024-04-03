CFLAGS = -Wall -Werror -Wextra -std=c11
CC = gcc
# DOP_LIB = -lm -lpthread -lcheck
FILES_FOLDERS = 
TEST_FOLDERS = 
OS = $(shell uname)

ifeq ($(OS),Linux)
    DOP_LIB = -lcheck -lm -lpthread -lsubunit #-lrt
else
    DOP_LIB = -lcheck -lm -lpthread
endif

all: clean s21_decimal.a test

s21_decimal.a: clean
	$(CC) $(CFLAGS) -c $(FILES_FOLDERS)
	ar rcs s21_decimal.a *.o
	ranlib s21_decimal.a
	
clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf build
	rm -rf report
	rm -rf decimal.info
	rm -rf testout
	rm -rf *.gcno
	rm -rf *.gcda

test: clean s21_decimal.a
	$(CC) $(CFLAGS) --coverage $(FILES_FOLDERS) tests/*.c -o testout $(DOP_LIB)
	./testout

gcov_report: test
	mkdir report
	gcovr -r. --html --html-details -o report/index.html -e tests 
	open report/index.html
	rm -rf *.gcno *gcda *.gcov

style:
	clang-format -style=google $(FILES_FOLDERS) tests/*.c tests/*.h *.h -i

clang:
	clang-format -style=google $(FILES_FOLDERS) tests/*.c tests/*.h *.h -n

check:
	cppcheck $(FILES_FOLDERS)
