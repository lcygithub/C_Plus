love.exe:main.o Cat.o Dog.o
	g++ -o love.exe main.o Cat.o Dog.o
main.o:main.cpp Cat.h Dog.h
	g++ -c main.cpp
Cat.o:Cat.cpp Cat.h
	g++ -c Cat.cpp
Dog.o:Dog.cpp Dog.o
	g++ -c Dog.cpp
clean:
	rm love *.o 
