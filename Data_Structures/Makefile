CFLAGS= -Wall -fpic -coverage -lm -std=c99

# array: array.c
# 	gcc -o array.c -g  $(CFLAGS)

array: array.c
	gcc -g -o array array.c $(CFLAGS)
	./array


clean:
	rm -f *.o  *.gcov *.gcda *.gcno *.so *.out array
