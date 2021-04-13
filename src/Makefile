all:
	gcc -g -c main.c
	gcc -g -c functions.c
	gcc -g -c dictionary.c
	gcc -g -c merge_sort.c
	gcc -g -c binary_search.c
	gcc -o main main.o merge_sort.o binary_search.o functions.o dictionary.o
	del *.o
	./main teste br.txt
	del *.exe


