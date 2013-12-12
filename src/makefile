all : ltareas

ltareas : tarea.o fecha.o listatareas.o utilidades.o ltareas.o
	g++ -Wall -g fecha.o tarea.o ltareas.o listatareas.o utilidades.o -o ltareas

fecha.o : fecha.cc fecha.h
	g++ -Wall -g -c fecha.cc
	
tarea.o : tarea.cc tarea.h
	g++ -Wall -g -c tarea.cc
	
listatareas.o: listatareas.cc listatareas.h
	g++ -Wall -g -c listatareas.cc
	
utilidades.o: utilidades.cc utilidades.h
	g++ -Wall -g -c utilidades.cc
	
ltareas.o : ltareas.cc fecha.h tarea.h listatareas.h utilidades.h
	g++ -Wall -g -c ltareas.cc

clean :
	rm ltareas.o
