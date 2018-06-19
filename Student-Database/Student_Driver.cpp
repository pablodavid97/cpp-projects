/**
 * Student_Driver.cpp
 *
 * Programacion II
 * Proyecto Final
 *
 * Implementa una base de datos, en la cual se mantiene un registro
 * de los estudiantes, mostrando su informacion personal y academica
 *
 * El programa tiene un menu principal con 6 opciones: vista general,
 * informacion completa, insertar, actualizar, eliminar y salir.
 *
 * Temas utilizados: composicion de clases, punteros, manejo de excepciones,
 * y flujos de entrada y salida
 *
 * Referencias:
 * Aldo Cassola funcion clearScreen para preservar la portatibilidad del programa.
 * Deitel, H. y Deitel, P. (2014). File Processing. C++ : How to program (9th ed.). (pp.633-671). Upper Saddle River, NJ: Pearson/Prentice Hall.
 */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Database.h"
#include "Student.h"
using namespace std;

// listado de opciones para el ingreso a la base de datos
enum OPTIONS{VIEW = 1, SEARCH, NEW, UPDATE, DELETE, QUIT};

int main()
{
    // crea un nuevo archivo de bits solo si no se ha creado alguno todavia
    if (newFile("students.dat")) // archivo de estudiantes
    {
        ofstream studentsData( "students.dat", ios::out | ios::binary ); // crea el archivo

        // si el archivo no puede ser creado se lanza un error
        if (!studentsData)
        {
            cerr << "No fue posible abrir el archivo indicado!" << endl;
            return 1;
        }

        Student CollegeStudent;

        // escribe un registro de 50 estudiantes en blanco
        for (int i = 0; i < 50; i++)
            studentsData.write(reinterpret_cast< const char * >( &CollegeStudent ), sizeof( Student ));
    }

    // se abre el archivo de estudiantes
    Database myDatabase("students.dat");

    // si el archivo no puede ser abierto se lanza un error
    if (!myDatabase.getDataBaseFile())
    {
        cerr << "No fue posible abrir el archivo indicado!" << endl;
        return 1;
    }

    char option = 'y';
    int menuOption = 0;

    // programa corre hasta que el usuario decida salir, ya sea mediante la opcion principal
    // o mediante una segunda opcion al terminar cada ejecucion
    while (option == 'y')
    {
        clearScreen(); // se limpia la panatalla

        for (int i = 0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;

        cout << "\t\tRegistro de Estudiantes " << endl; // imprime el titulo del menu

        for (int i = 0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;

        // imprime un menu con 6 ocpiones a la pantalla para que el usuario pueda elegir
        cout << "\nPorfavor ingrese una de las siguientes opciones: \n" << endl
        << "\t1 - Vista general " << endl
        << "\t2 - Informacion de Alumno " << endl
        << "\t3 - Ingresar nuevos datos" << endl
        << "\t4 - Actualizar datos " << endl
        << "\t5 - Eliminar datos " << endl
        << "\t6 - Salir \n" << endl;

        // se ingresa la opcion del usuario y se limpia la pantalla
        cout << "Opcion: ";
        cin >> menuOption;
        clearScreen();

        // casos que representan las opciones del programa
        switch (menuOption)
		{
		    case VIEW:
		        myDatabase.displayRecord(); // ver datos generales
		        break;
		    case SEARCH:
		        myDatabase.searchStudentRecord(); // buscar datos particulares completos
		        break;
		    case NEW:
		        myDatabase.newStudentRecord(); // insertar un nuevo registro
		        break;
		    case UPDATE:
		        myDatabase.updateStudentRecord(); // actualizar datos ingresados
		        break;
		    case DELETE:
		        myDatabase.deleteStudentRecord(); // eliminar datos
		        break;
		    case QUIT:
		        option = 'q'; // salir del programa
                cout << "\nGracias por utilizar nuestros servicios" << endl;
		        break;
		    default: // si el usuario ingresa un valor desconocido se lanza un error
		        cerr << "Porfavor ingrese una opcion valida" << endl;
        }

        // opcion para regresar al menu principal o salir del programa
        if (option != 'q')
        {
            cout << "\nDesea volver al menu principal? " << endl
            << "Presione y para volver.\nPresione cualquier otra tecla para salir.\n" << endl;

            cout << "Opcion: ";
            cin >> option;

            cout << "\nGracias por utilizar nuestros servicios" << endl;
        }
    }
}
