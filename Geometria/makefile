geometria: geom_pruebas.o Recta.o Punto.o
	g++ geom_pruebas.o Recta.o Punto.o -o geometria 

geom_pruebas.o: geom_pruebas.cpp
	g++ -c geom_pruebas.cpp 
	
Recta.o: Geometria/Recta.cpp Geometria/Recta.h
	g++ -c Geometria/Recta.cpp 
	
Punto.o: Geometria/Punto.cpp Geometria/Punto.h
	g++ -c Geometria/Punto.cpp 

clean: 
	rm *.o geometria 
	