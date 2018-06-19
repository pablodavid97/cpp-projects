/**
 * Student.cpp
 *
 * Programacion II
 * Proyecto Final
 *
 * Archivo que implementa los prototipos definidos en Student.h
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Student.h" // include definicion de la clase Student
using namespace std;

// constructor de la clase que toma datos opcionales para llenar los campos del estudiante
Student::Student(const int sID, const string &fName, const string &lName, const string &c,
    const double g, const string &ad, const string &e, const string &ctnshp, const string &r)
    : id (sID)
{
    // cuerpo del cosntructor asigna los valores a los campos del estudiante
    setFirstName(fName);
    setLastName(lName);
    setCareer(c);
    setGPA(g);
    setAcademicDegree(ad);
    setEmail(e);
    setCitizenship(ctnshp);
    setResidence(r);
}

// asigna el valor del ID del estudiante
void Student::setID(const int sID)
{
    id = sID;
}

// devuelve el ID del estudiante
int Student::getID() const
{
    return id;
}

// fija el valor del nombre
void Student::setFirstName(const string &fName)
{
    // verifica la extension del nombre
    int length = fName.size();

    // procesa el nombre ingresado segun su longitud
    if (length < 15) // longiutd entre rango establecido
    {
        // copia el nombre ingresado completamente
        fName.copy(firstName, length);
        lastName[length] = '\0';
    }
    else
    {
        // copia los primeros caracteres y lanza una excecpcion
        fName.copy(firstName, 14);
        lastName[15] = '\0';
        throw invalid_argument("La extension del nombre ingresado sobrepasa los limites establecidos!\n");
    }
}

// devuelve el nombre de estudiante
string Student::getFirstName() const
{
    return firstName;
}

// fija el valor del apellido
void Student::setLastName(const string &lName)
{
    // verifica la extension del nombre
    int length = lName.size();

    // procesa el apellido ingresado segun su longitud
    if (length < 15) // si esta dentro del rango establecido
    {
        // copia el apellido completo
        lName.copy(lastName, length);
        lastName[length] = '\0';
    }
    else // de lo contrario
    {
        // copia la primera parte del apellido y lanza una excepcion
        lName.copy(lastName, 14);
        lastName[15] = '\0';
        throw invalid_argument("La extension del apellido ingresado sobrepasa los limites establecidos!\n");
    }
}

// devuelve el apellido
string Student::getLastName() const
{
    return lastName;
}

// fija la carrera del estudiante
void Student::setCareer(const string &c)
{
    // verifica la longitud de la carrera
    int length = c.size();

    // procesa la carrera segun su longitud
    if (length < 30) // si esta dentro de rango establecido
    {
        // copia el nombre de la carrera completo
        c.copy(career, length);
        career[length] = '\0';
    }
    else // de lo contrario
    {
        // copia solo una parte del nombre y lanza una excepcion
        c.copy(career, 29);
        career[30] = '\0';
        throw invalid_argument("La extension del nombre de la carrera ingresada sobrepasa los limites establecidos!\n");
    }
}

// devuelve la carrera del estudiante
string Student::getCareer() const
{
    return career;
}

// asigna el valor del gpa
void Student::setGPA(const double g)
{
    // asigna el valor del gpa solo si esta dentro de rango establecido
    if(g >= 0.0 && g <= 4.0)
        gpa = g;
    else // de lo contrario asigna el valor de 0 y lanza excepcion
    {
        gpa = 0.0;
        throw invalid_argument("El gpa ingresado debe estar entre 0 y 4");
    }
}

// devuelve el valor del gpa
double Student::getGPA() const
{
  return gpa;
}

// fija el nivel academico
void Student::setAcademicDegree(const string &ad)
{
    // determina la longitud
    int length = ad.size();

    // procesa el nivel academico segun la longitud
    if (length < 15) // si esta dentro de rango establecido
    {
        // copia completamente
        ad.copy(aDegree, length);
        aDegree[length] = '\0';
    }
    else // de lo contrario
    {
        // copia una parte y lanza excepcion
        ad.copy(aDegree, 14);
        aDegree[15] = '\0';
        throw invalid_argument("La extension del nivel ingresado sobrepasa los limites establecidos!\n");
    }
}

// devuelve nivel academico
string Student::getAcademicDegree() const
{
    return aDegree;
}

// fija el email de estudiante
void Student::setEmail(const string &e)
{
    // determina la longitud del email
    int length = e.size();

    // procesa email segun su longitud
    if (length < 30) // si esta dentro de rango establecido
    {
        // copia completo
        e.copy(email, length);
        email[length] = '\0';
    }
    else // de lo contrario
    {
        // copia una parte y lanza excepcion
        e.copy(email, 29);
        email[30] = '\0';
        throw invalid_argument("La extension del correo electronico sobrepasa los limites establecidos!\n");
    }
}

// devuelve email
string Student::getEmail() const
{
    return email;
}

// fija ciudadania
void Student::setCitizenship(const string &ctnshp)
{
    // determina la longitud de la ciudadania ingresada
    int length = ctnshp.size();

    // procesa este dato segun su longitud
    if (length < 15) // si esta dentro de la longitud establecida
    {
        // copiar todo
        ctnshp.copy(citizenship, length);
        citizenship[length] = '\0';
    }
    else // de lo contrario
    {
        // copiar solo una parte y lanzar excepcion
        ctnshp.copy(citizenship, 14);
        citizenship[15] = '\0';
        throw invalid_argument("La extension de la ciudadania ingresada sobrepasa los limites establecidos!\n");
    }
}

// devuelve ciudadania
string Student::getCitizenship() const
{
    return citizenship;
}

// fija residencia
void Student::setResidence(const string &r)
{
    // determina la longitud de la residencia
    int length = r.size();

    // procesa la residencia segun longitud
    if (length < 15) // si esta dentro de rango
    {
        // copiar todo
        r.copy(residence, length);
        residence[length] = '\0';
    }
    else // de lo contrario
    {
        // copiar una parte y lanzar excepcion
        r.copy(residence, 14);
        residence[15] = '\0';
        throw invalid_argument("La extension del lugar de residencia ingresado sobrepasa los limites establecidos!\n");
    }
}

// devuelve residencia
string Student::getResidence() const
{
    return residence;
}
