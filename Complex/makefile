complex: complex_driver.o Complex.o 
	g++ complex_driver.o Complex.o -o complex

complex_driver.o: complex_driver.cpp
	g++ -c complex_driver.cpp 
	
Complex.o: Complex.cpp Complex.h
	g++ -c Complex.cpp
	
clean: 
	rm *.o geometria 
	