polynomial: Polynomial_Driver.o Polynomial.o
	g++ Polynomial_Driver.o Polynomial.o -o polynomial

Polynomial_Driver.o: Polynomial_Driver.cpp
	g++ -c Polynomial_Driver.cpp 
	
Polynomial.o: Polynomial.cpp Polynomial.h
	g++ -c Polynomial.cpp 

clean: 
	rm *.o polynomial
	