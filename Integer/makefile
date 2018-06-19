integer: Integer_Driver.o Integer.o
	g++ Integer_Driver.o Integer.o -o integer

Integer_Driver.o: Integer_Driver.cpp
	g++ -c Integer_Driver.cpp 
	
Integer.o: Integer.cpp Integer.h
	g++ -c Integer.cpp 

clean: 
	rm *.o date
	