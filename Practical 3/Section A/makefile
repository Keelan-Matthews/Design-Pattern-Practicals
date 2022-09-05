main:
	g++ -c *.cpp
	g++ -o Main *.o
run: main
	./main

clean:
	rm *.o Main

reset:
	make clean
	make
	make run