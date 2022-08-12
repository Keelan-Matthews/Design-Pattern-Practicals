main:
	g++ -c *.cpp
	g++ -o Main *.o
run: main
	./main

clean:
	rm *.o main

reset:
	make clean
	make
	make run