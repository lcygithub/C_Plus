polygon:main.o Polygon.o Test.o
	g++ -o polygon main.o Polygon.o Test.o
main.o:main.cpp Polygon.h Test.h
	g++ -c main.cpp
Polygon.o:Polygon.cpp Polygon.h
	g++ -c Polygon.cpp
Test.o:Test.cpp Test.h Polygon.h
	g++ -c Test.cpp
clean:
	rm polygon *.o
