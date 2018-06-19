/**
 * Database.h
 *
 * Programacion II
 * Proyecto Final
 *
 * Definicion de la clase Database, la cual representa una base de datos
 * que contiene informacion de los estudiantes
 *
 */

// evita que el archivo sea incluido mas de una sola vez
#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h" // incluye la clase Student

// definicion de la clase Database
class Database
{
    public:
        Database(const char []); // constructor de la clase
        std::fstream &getDataBaseFile(); // devuelve el archivo de datos
        int getStudentData(const char []) const; // devuelve los datos del estudiante a traves del ID
        void setStudentInfo(Student &, int); // fija los campos requeridos por estudiante
        void displayRecord(); // imprime a la pantalla los datos generales
        void displayFullStudentData(const Student &); // imprime a la pantalla informacion completa de un estudiante particular
        void searchStudentRecord(); // busca la informacion de un estudiante particular
        void newStudentRecord(); // inserta un nuevo registro de estudiante
        void updateStudentRecord(); // actualiza los datos de un estudiante
        void deleteStudentRecord(); // elimina los datos de un estudiante

    private:
        std::fstream dBaseFile; // archivo de datos de los estudiantes
};

bool newFile(const char []); // funcion no miembro que determina si se debe crear un archivo de datos
void clearScreen(); // funcion no miembro que limpia la pantalla

#endif // DATABASE_H
