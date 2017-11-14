execute : main.out
	./main.out

main.out : main.c
	make clean
	gcc -Wpedantic -o $@ $^ -pthread 

clean :
	rm -f main main.out