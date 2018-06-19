/**
 * Student.h
 *
 * Programacion II
 * Proyecto Final
 *
 * Definicion de la clase Student, la cual representa un estudiante
 * y la informacion que lo identifica
 *
 */

// evita que el archivo sea incluido mas de una sola vez
#ifndef STUDENT_H
#define STUDENT_H

#include <string> // clase que contiene tipo de dato string

// definicion de la clase Student
class Student
{
    public:
        Student(const int = 0, const std::string & = "", const std::string & = "",
            const std::string & = "", const double = 0.0, const std::string & = "",
            const std::string & = "", const std::string & = "", const std::string & = ""); // constructor con valores opcionales
        void setID(const int); // fija el valor del ID del estudiante
        int getID() const; // devuelve el valor del ID del estudiante
        void setFirstName(const std::string &); // fija el nombre del estudiante
        std::string getFirstName() const; // devuelve el nombre del estudiante
        void setLastName(const std::string &); // fija el apellido del estudiante
        std::string getLastName() const; // devuelve el apellido del estudiante
        void setCareer(const std::string &); // fija la carrera del estudiante
        std::string getCareer() const; // devuelve la carrera del estudiante
        void setGPA(const double); // fija el valor del gpa del estudiante
        double getGPA() const; // devuelve el valor del gpa del estudiante
        void setAcademicDegree(const std::string &); // fija el nivel academico del estudiante
        std::string getAcademicDegree() const; // devuelve el nivel academico del estudiante
        void setEmail(const std::string &); // fija el correo electronico del estudiante
        std::string getEmail() const; // devuelve el correo electronico del estudiante
        void setCitizenship(const std::string &); // fija la ciudadania del estudiante
        std::string getCitizenship() const; // devuelve la ciudadania del estudiante
        void setResidence(const std::string &); // fija la residencia del estudiante
        std::string getResidence() const; // devuelve la residencia del estudiante

    private: // miembros dato que guardan la informacion de cada alumno
        int id; // numero de identificacion
        char firstName[15]; // nombre
        char lastName[15]; // apellido
        char career[30]; // carrera
        double gpa; // promedio acumulado
        char aDegree[15]; // nivel academico
        char email[30]; // correo electronico
        char citizenship[15]; // ciudadania
        char residence[15]; // residencia
};

#endif // STUDENT_H
