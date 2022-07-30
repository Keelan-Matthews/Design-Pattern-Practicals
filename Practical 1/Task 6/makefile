t6.out: main.o AuditableSnapshot.o Snapshot.o User.o UserManager.o
			g++ main.o AuditableSnapshot.o Snapshot.o User.o UserManager.o -o t6.out

main.o: main.cpp
			g++ -c main.cpp

AuditableSnapshot.o: AuditableSnapshot.cpp
			g++ -c AuditableSnapshot.cpp

Snapshot.o: Snapshot.cpp
			g++ -c Snapshot.cpp

User.o: User.cpp
			g++ -c User.cpp

UserManager.o: UserManager.cpp
			g++ -c UserManager.cpp

run:
			./t6.out

clean:
			rm *.o t6