execute : main.out
	./main.out 1 2 3

execute_empty : main.out
	./main.out

main.out : main.c
	make clean
	gcc -Wpedantic -o $@ $^ -pthread 

clean :
	rm -f main main.out