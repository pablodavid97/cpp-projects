// Pablo Llanes 00133203 
// Deber 3
// 29/03/2016 

#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 

// crea una clase llamada Registro que incluye funciones que guardan e imprimen las notas de una lista de estudiantes 
class Registro 
{
	// establece que las variables y funciones declaradas pueden ser utilizadas por funciones que estan fuera de la clase 
	public: 
	
	int i,j; 
	
	// permite al usuario ingresar los datos de los estudiantes y sus notas en un curso de estudio 
	void DataInput()
	{
		cout << "Ingrese el nombre del Curso: " << endl; 
		getline (cin, cmp231.CourseName);
		
		for (i = 0; i < 10; i++)
		{
			cout << "Ingrese el nombre del estudiante " << i + 1 << ": "; 
			getline (cin,cmp231.name[i]); 
		}  
		
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 3; j++)
			{
				do 
				{
					cout << "Ingrese la nota " << j + 1 << " del alumno " << i + 1 << " sobre 100: " << endl; 
					cin >> cmp231.notas[i][j]; 
				}
				while (cmp231.notas[i][j] < 0 || cmp231.notas[i][j] > 100);
				
			}
		}
	}
	
	// convierte el promedio de las notas de los estudiantes en notas literales 
	void SetData()
	{
		for (i = 0; i < 10; i++)
		{	
			cmp231.suma[i] = 0; 
			
			for (j = 0; j < 3; j++)
			{
				cmp231.suma[i] += cmp231.notas[i][j]; 
			}
			cmp231.promedio[i][j] = cmp231.suma[i] / 3; 
			
			if (cmp231.promedio[i][j] >= 91 && cmp231.promedio[i][j] <= 100)
				{
					cmp231.promedio[i][j] = 'A'; 
				}
				else if (cmp231.promedio[i][j] >= 81 && cmp231.promedio[i][j] < 91)
				{
					cmp231.promedio[i][j] = 'B';
				}
				else if (cmp231.promedio[i][j] >= 71 && cmp231.promedio[i][j] < 81)
				{
					cmp231.promedio[i][j] = 'C';
				}
				else if (cmp231.promedio[i][j] >= 61 && cmp231.promedio[i][j] < 71)
				{
					cmp231.promedio[i][j] = 'D';
				}
				else 
				{
					cmp231.promedio[i][j] = 'F';
				}
		}
	}
		
	// imprime los datos ingresados por el usuario a la pantalla organizados dentro de una tabla de datos 
	void DataDisplay()
		{			
			char separator    = ' ';
    		int nameWidth     = 22;
    		int numWidth      = 8;
    				
			cout << "Alumnos registrados en el curso " << cmp231.CourseName << endl;
			
			cout << "Nombre del Alumno     Nota1   Nota2   Nota3  NotaPromedio " << endl; 
			 
			for (i = 0; i < 10; i++)
			{
				cout << left << setw(nameWidth) << setfill(separator) << cmp231.name[i] << "\t"; 
				
				for (j = 0; j < 3; j++)
				{
					cout << left << setw(numWidth) << setfill(separator) << cmp231.notas[i][j]; 
				}
				cout << "  " << left << setw(numWidth) << setfill(separator) << (char) cmp231.promedio[i][j] << endl; 
			}	
		}
	
	// crea una estructura que contiene los datos de los estudiantes del curso 
	struct CourseData
	{
		string CourseName; 
		string name[10]; 
		int notas[10][3];
		float suma[10]; 
		float promedio[10][3];  
		char final[10]; 
	}cmp231;

};

int main()
{
	
	// declara un objeto tipo Registro 
	Registro Datacmp231;
	
	// utiliza las funciones que estan dentro de la clase Registro a traves del objeto declarado inicialmente
	Datacmp231.DataInput();
	Datacmp231.SetData();
	Datacmp231.DataDisplay(); 
	
	// indica que el programa se ejecuto exitosamente 
	return 0; 
}


