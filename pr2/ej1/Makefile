execute : main.out
	./main.out

main.out : main.c
	gcc -o $@ $^ -pthread

clean :
	rm -f main main.out