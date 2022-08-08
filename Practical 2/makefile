OBJS	= main.o SquadMember.o Soldier.o Snake.o Jaguar.o Gorilla.o Cannibal.o JaguarFactory.o GorillaFactory.o CannibalFactory.o EnemyFactory.o
SOURCE	= main.cpp SquadMember.cpp Soldier.cpp Snake.cpp Jaguar.cpp Gorilla.cpp Cannibal.cpp JaguarFactory.cpp GorillaFactory.cpp CannibalFactory.cpp EnemyFactory.cpp
HEADER	= Enemy.h SquadMember.h Soldier.h Snake.h Jaguar.h Gorilla.h Cannibal.h JaguarFactory.h GorillaFactory.h CannibalFactory.h EnemyFactory.h
OUT	= p2.out
CC	 = g++
FLAGS	 = -g

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++17

SquadMember.o: SquadMember.cpp
	$(CC) $(FLAGS) SquadMember.cpp -std=c++17

Soldier.o: Soldier.cpp
	$(CC) $(FLAGS) Soldier.cpp -std=c++17

Snake.o: Snake.cpp
	$(CC) $(FLAGS) Snake.cpp -std=c++17

Jaguar.o: Jaguar.cpp
	$(CC) $(FLAGS) Jaguar.cpp -std=c++17

Gorilla.o: Gorilla.cpp
	$(CC) $(FLAGS) Gorilla.cpp -std=c++17

Cannibal.o: Cannibal.cpp
	$(CC) $(FLAGS) Cannibal.cpp -std=c++17

JaguarFactory.o: JaguarFactory.cpp
	$(CC) $(FLAGS) JaguarFactory.cpp -std=c++17

GorillaFactory.o: GorillaFactory.cpp
	$(CC) $(FLAGS) GorillaFactory.cpp -std=c++17

CannibalFactory.o: CannibalFactory.cpp
	$(CC) $(FLAGS) CannibalFactory.cpp -std=c++17

EnemyFactory.o: EnemyFactory.cpp
	$(CC) $(FLAGS) enemyFactory.cpp -std=c++17


clean:
	rm -f $(OBJS) $(OUT)

run: main
			./main