all: file_manager timer main proyecto

file_manager: file_manager.cpp file_manager.h
	g++ -std=c++11 -Wall -c file_manager.cpp

timer: timer.cpp timer.h
	g++ -std=c++11 -Wall -c  timer.cpp

main: main.cpp gbj.h
	g++ -std=c++11 -Wall -c main.cpp

proyecto: main.o file_manager.o timer.o
	g++ -std=c++11 -Wall main.o file_manager.o timer.o -o ProyectoIA

clean:
	rm -f *.o
	rm -f ProyectoIA
