/**
 * Database.cpp
 *
 * Programacion II
 * Proyecto Final
 *
 * Archivo que implementa los prototipos definidos en Database.h
 *
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include "Database.h" // incluye archivo de difincion
using namespace std;

// constructor de la clase que recibe el nombre del archivo de datos creado
Database::Database(const char fname[])
    : dBaseFile (fname, ios::in | ios::out | ios::binary)
{

}

// devuelve el archivo de datos
fstream &Database::getDataBaseFile()
{
    return dBaseFile;
}

// devuelve los datos del estudiante a traves del ID
int Database::getStudentData(const char prompt[]) const
{
    int ID;

    // asegura que el usuario ingrese valores de acuerdo al rango establecido
    cout << prompt << endl;
    do
    {
        cout << "El ID debe estar dentro del rango seleccionado (1-50):" << endl;
        cin >> ID;
    }
    while (ID < 1 || ID > 50);

    // devuelve el ID de estudiante
    return ID;
}

// fija los campos requeridos por estudiante
void Database::setStudentInfo(Student &stdnt, int ID)
{
    // variables que van a guardar la informacion del estudiante por cada campo
    int sID = ID;
    string fName, lName, c, ad, e_mail, ctznshp, r;
    double grades;

    // pide al usuario ingresar los datos necesarios
    cout << "Ingrese los siguientes datos del estudiante " << endl;
    cout << "Nombre: ";
    cin >> fName;
    cout << "Apellido: ";
    cin >> lName;
    cin.ignore();
    cout << "Carrera: ";
    getline(cin, c);
    cout << "Promedio Acumulado (0-4): ";
    cin >> grades;
    cin.ignore();
    cout << "Nivel de Estudios: ";
    getline(cin, ad);
    cout << "Correo electronico: ";
    cin >> e_mail;
    cout << "Ciudadania: ";
    cin >> ctznshp;
    cout << "Residencia: ";
    cin >> r;

    stdnt.setID(sID);

    // menejor de excepciones, si el usuario ingreso datos erroneos se busca la manera
    // de que el programa siga corriendo lanzando excepciones y asignando valores particulares
    try
    {
        stdnt.setFirstName(fName);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        stdnt.setLastName(lName);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        stdnt.setCareer(c);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        stdnt.setGPA(grades);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        stdnt.setAcademicDegree(ad);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        stdnt.setEmail(e_mail);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        stdnt.setCitizenship(ctznshp);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        stdnt.setResidence(r);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

// imprime a la pantalla los datos generales
void Database::displayRecord()
{
    // imprime el titulo de cada campo
    cout << left << setw(10) << "ID " << setw(16) <<  "Apellido" << setw(16) << "Nombre" << setw(30) << "Carrera " << setw(10) << "GPA" << setw(16) << endl;

    // asigna al cursor la posicion inicial del archivo
    dBaseFile.seekg(0);

    Student myStudent;

    // lee los datos de cada estudiante
    dBaseFile.read(reinterpret_cast<char *>(&myStudent), sizeof(Student));

    // lee los datos hasta el fin del archivo
    while(!dBaseFile.eof())
    {
        // se salta aquellos estudiantes sin ningun dato registrado
        if (myStudent.getID() != 0)
        {
            // imprime los datos generales del estudiante a la pantalla
            cout << left << setw(10) << myStudent.getID() << setw(16) <<  myStudent.getLastName() << setw(16) << myStudent.getFirstName() << setw(30)
            << myStudent.getCareer() << setw(10) << setprecision(2) << fixed << myStudent.getGPA() << endl;
        }

        // lee el siguiente estudiante del archivo
        dBaseFile.read(reinterpret_cast<char *>(&myStudent), sizeof(Student));
    }

    // asegura el funcionamiento de la primera opcion del menu de datos
    dBaseFile.clear();
}

// imprime a la pantalla informacion completa de un estudiante particular siguiendo el formato establecido
void Database::displayFullStudentData(const Student &stdnt)
{
    cout << "\nID: " << left << setw(2) << stdnt.getID() << endl;
    cout <<  "Apellido: "  << left << setw(16) <<  stdnt.getLastName() << endl;
    cout << "Nombre: " << left << setw(16) <<  stdnt.getFirstName() << endl;
    cout << "Carrera: " << left << setw(30) << stdnt.getCareer() << endl;
    cout << "GPA: " << left << setw(2) << stdnt.getGPA() << endl;
    cout << "Nivel Academico: " << left << setw(16) << stdnt.getAcademicDegree() << endl;
    cout << "Correo Electronico: " << left << setw(30) << stdnt.getEmail() << endl;
    cout << "Ciudadania: " << left << setw(16) << stdnt.getCitizenship() << endl;
    cout << "Residencia: " << left << setw(16) << stdnt.getResidence() << endl;
    cout << endl;
}

// busca la informacion de un estudiante particular
void Database::searchStudentRecord()
{
    Student myStudent;

    // busca a un estudiante en particular segun el ID ingresado por el usuario
    int ID = getStudentData("Ingrese el numero de identificacion del estudiante que desea buscar");

    // mueve el cursor hacia la posicion del estudiante deseado
    dBaseFile.seekg((ID - 1) * sizeof(Student));

    // lee los datos del estudiante buscado
    dBaseFile.read(reinterpret_cast<char *>(&myStudent), sizeof(Student));

    // si existen los datos del estudiante
    if (myStudent.getID() != 0)
    {
        dBaseFile.seekp((ID - 1) * sizeof(Student)); // busca la posicion correcta del estudiante

        displayFullStudentData(myStudent); // imprime los datos del estudiante a la pantalla
    }
    else // si no existen datos del estudiante se lanza un error
    {
        cerr << " No se ha encontrado un registro del estudiante con el # de identificacion ingresado" << endl;
    }
}

// inserta un nuevo registro de estudiante
void Database::newStudentRecord()
{
    // obtiene el id Ingresado por el usuario
    int ID = getStudentData("Ingrese el numero de identificacion del estudiante que desea agregar");

    // mueve el cursor hacia la posicion del estudiante deseado
    dBaseFile.seekg((ID - 1) * sizeof(Student));

    Student newStudent;

    // lee los datos del estudiante buscado
    dBaseFile.read(reinterpret_cast<char *>(&newStudent), sizeof(Student));

    // solo si no hay datos de estudiante con el ID ingresado
    if (newStudent.getID() == 0)
    {
        // fija los campos del estudiante
        setStudentInfo(newStudent, ID);

        // muebe el cursor a la posicion correcta
        dBaseFile.seekp((ID - 1) * sizeof(Student));

        // escribe los datos del estudiante en el archivo de datos
        dBaseFile.write(reinterpret_cast<const char *>(&newStudent), sizeof(Student));
    }
    else // de lo contrario se lanza un error
    {
        cerr << " El estudiante con # de identificacion ingresado" << ID << "ya existe!" << endl;
    }
}

// actualiza los datos de un estudiante
void Database::updateStudentRecord()
{
    Student myStudent;

    // obtiene el ID del estudiante que se desea actualizar
    int ID = getStudentData("Ingrese el numero de identificacion del estudiante que desea buscar");

    // mueve el cursor hacia la posicion del estudiante deseado
    dBaseFile.seekg((ID - 1) * sizeof(Student));

    // lee los datos del estudiante del archivo de datos
    dBaseFile.read(reinterpret_cast<char *>(&myStudent), sizeof(Student));

    // solo si existen datos
    if (myStudent.getID() != 0)
    {
        // mueve el cursor a la posicion correcta
        dBaseFile.seekp((ID - 1) * sizeof(Student));

        // imprime los datos completos del estudiante
        displayFullStudentData(myStudent);

        // variables para contener la informacion del estudiante por cada campo
        int optn;
        string fName, lName, c, ad, e_mail, ctznshp, r;
        double grades;

        // imprime un menu para que el estudiante modifique un campo de estudiante particular
        cout << "Ingrese el valor del campo del estudiante que desea actualizar" << endl
        << "\t1 - Nombre " << endl
        << "\t2 - Apellido " << endl
        << "\t3 - Carrera " << endl
        << "\t4 - GPA " << endl
        << "\t5 - Nivel Academico " << endl
        << "\t6 - Correo Electronico " << endl
        << "\t7 - Ciudadania " << endl
        << "\t8 - Residencia \n" << endl;

        // usuario ingresa su opcion
        cout << "Opcion: ";
        cin >> optn;
        clearScreen(); // se limpia la pantalla

        // casos que permiten al usuario modificar un campo del estudiante en particular
        switch (optn)
		{
		    case 1:
		        cout << "Ingrese el nuevo nombre del estudiante " << endl;
                cout << "Nombre: ";
                cin >> fName;
                try
                {
                    myStudent.setFirstName(fName);
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
		        break;
		    case 2:
		        cout << "Ingrese el nuevo apellido del estudiante " << endl;
		        cout << "Apellido: ";
                cin >> lName;
                try
                {
                    myStudent.setLastName(lName);
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
		        break;
		    case 3:
		        cout << "Ingrese la nueva carrera del estudiante " << endl;
                cout << "Carrera: ";
                getline(cin, c);
                try
                {
                    myStudent.setCareer(c);
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
		        break;
		    case 4:
		        cout << "Ingrese el nuevo GPA del estudiante " << endl;
		        cout << "Promedio Acumulado (0-4): ";
                cin >> grades;
                try
                {
                    myStudent.setGPA(grades);
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
		        break;
		    case 5:
		        cout << "Ingrese el nuevo nivel de estudios del estudiante " << endl;
                cout << "Nivel de Estudios: ";
                getline(cin, ad);
                try
                {
                    myStudent.setAcademicDegree(ad);
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
		        break;
		    case 6:
		        cout << "Ingrese el nuevo correo electronico del estudiante " << endl;
		        cout << "Correo electronico: ";
                cin >> e_mail;
                try
                {
                    myStudent.setEmail(e_mail);
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
		        break;
            case 7:
                cout << "Ingrese la nueva ciudadania del estudiante " << endl;
		        cout << "Ciudadania: ";
                cin >> ctznshp;
                try
                {
                    myStudent.setCitizenship(ctznshp);
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
		        break;
            case 8:
                cout << "Ingrese la nueva residencia del estudiante " << endl;
                cout << "Residencia: ";
                cin >> r;
                try
                {
                    myStudent.setResidence(r);
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
		        break;
		    default:
		        cerr << "Porfavor ingrese una opcion valida" << endl;
        }

        // ajusta el cursor a la posicion correcta
        dBaseFile.seekp((ID - 1) * sizeof(Student));

        // escribe los nuevos datos de estudiante en archivo
        dBaseFile.write(reinterpret_cast<const char *>(&myStudent), sizeof(Student));
    }
    else // si no hay datos del estudiante se lanza un error
    {
        cerr << " No se ha encontrado un registro del estudiante con el # de identificacion ingresado" << endl;
    }
}

// elimina los datos de un estudiante
void Database::deleteStudentRecord()
{
    // se obtiene el id del estudiante que se desea eliminar
    int ID = getStudentData("Ingrese el numero de identificacion del estudiante que desea borrar");

    // mueve el cursor hacia la posicion del estudiante deseado
    dBaseFile.seekg((ID - 1) * sizeof(Student));

    Student myStudent;

    // lee los datos del estudiante deseado
    dBaseFile.read(reinterpret_cast<char *>(&myStudent), sizeof(Student));

    // solo si existen datos
    if (myStudent.getID() != 0)
    {
        // estudiante con datos en blanco
        Student blankStudent;

        // mueve el cursor a la posicion correcta
        dBaseFile.seekp((ID - 1) * sizeof(Student));

        // remplaza los datos del estudiante por los datos del estudiante en blanco
        dBaseFile.write(reinterpret_cast<const char *>(&blankStudent), sizeof(Student));

        // informa al usuario de operacion exitosa
        cout << "Registro #" << ID << " ha sido borrado" << endl;
    }
    else // de lo contrario se lanza un error a la pantalla
    {
        cerr << " No se ha encontrado un registro del estudiante con el # de identificacion ingresado " << endl;
    }
}

// funcion que determina si un archivo de datos debe ser creado o no
bool newFile(const char name[])
{
    ifstream file(name);

    if(file.is_open())
    {
        return false;
        file.close();
    }
    else
        return true;
}

// limpia la pantalla de acuerdo al sistema operativo
void clearScreen()
{
    #ifdef _WIN32
        system("CLS");
    #elif __unix__
        system("clear");
    #endif
}
