students: Student_Driver.o Database.o Student.o
	g++ Student_Driver.o Database.o Student.o -o students

Student_Driver.o: Student_Driver.cpp
	g++ -c Student_Driver.cpp 
	
Database.o: Database.cpp Database.h
	g++ -c Database.cpp
	
Student.o: Student.cpp Student.h
	g++ -c Student.cpp
	
clean: 
	rm *.o students
	
	