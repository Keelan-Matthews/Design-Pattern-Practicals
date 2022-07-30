t3.out: main.o Calculator.o
			g++ main.o Calculator.o -o t3.out

main.o: main.cpp
			g++ -c main.cpp

Calculator.o: Calculator.cpp
			g++ -c Calculator.cpp

run:
			./t3.out

clean:
			rm *.o t3