all: application

application: application.o 
	g++ application.o -o application -lsfml-graphics -lsfml-window -lsfml-system

application.o: application.cpp application.hpp
	g++ -c application.cpp

clean:
	rm -rf *.o application
