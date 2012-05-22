Chain:main.o Biologic.o Chain.o
	g++ -o Chain main.o Biologic.o Chain.o
main.o:main.cpp Chain.h
	g++ -c main.cpp
Chain.o:Chain.cpp Chain.h Biologic.h
	g++ -c Chain.cpp
Biologic.o:Biologic.cpp Biologic.h
	g++ -c Biologic.cpp
clean:
	rm *.o
