execute : main.out
	./main.out

main.out : main.c
	gcc -Wpedantic -o $@ $^ -pthread 

clean :
	rm -f main main.out