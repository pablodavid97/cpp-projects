// Pablo Llanes 00133203
// 05/05/2016
// Proyecto Final: Calculadora Cintifica
// Las operaciones incluyen: suma, resta, multiplicacion, division,
// media aritmetica de n numeros ingresados por teclado o por un archivo de texto,
// y desviacion estandar de n numeros ingresados por el teclado o por un archivo de texto

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

// crea una clase llamada operaciones en la cual existen funciones que realizan operaciones matematicas
class Operaciones
{
    public:

        // recibe 2 numeros ingresados por el usuario
        void setNumbers(int x, int y)
		{
			num1 = x;
			num2 = y;
		}

        // devuelve los numeros ingresados por el usuario
        int getNumbers()
		{
			return num1, num2;
		}

        // suma 2 numers
        int Suma()
		{
			suma = 0;
			suma = num1 + num2;
			return suma;
		}

        // imprime la suma de 2 numeros a la pantalla
		void sumaDisplay()
		{
		    cout << "La suma de " << num1 << " y " << num2 << " es " << Suma() << endl;
		}

        // resta 2 numeros
		int Resta()
		{
			resta = 0;
			resta = num1 - num2;
			return resta;
		}

        // imprime la resta de 2 numeros a la pantalla
		void restaDisplay()
		{
            {
                cout << "La resta de " << num1 << " y " << num2 << " es " << Resta() << endl;
            }
		}

		// multiplica 2 numeros
        int Multiplicacion()
		{
			multiplicacion = 0;
			multiplicacion = num1 * num2;
			return multiplicacion;
		}

        // imprime la multiplicacion de 2 numeros a la pantalla
        void multiplicacionDisplay()
		{
            cout << num1 << " multiplicado por " << num2 << " es " << Multiplicacion() << endl;
		}

		// divide 2 numeros
        float Division()
		{
			division = 0;
			division = (float) num1 / (float) num2;
			return division;
		}

		// imprime la division de 2 numeros a la pantalla
        void divisionDisplay()
		{
            cout << num1 << " dividido para " << num2 << " es " << setprecision(3) << Division() << endl;
		}

        // lee una serie de numeros de un archivo te texto y calcula su media aritmetica
        float mediaAritmeticaFile()
        {
            ifstream file ("numeros.txt");
            int i = 0;
            media = 0;

            if (file.is_open())
            {
                while (!file.eof())
                {
                    file >> x[i];

                    i++;
                }

                int length = i;

                for(i = 0; i < length; i++)
                {
                    media = media + x[i];
                }
                media = media/length;

                return media;

            file.close(); // cierra el archivo asociado con el programa y lo desasocia despues
            }

            // si esque el archivo no esta asociado el programa imprime un mensaje en la pantalla que lo indica
            else
            {
                cout << "El archivo no pudo ser encontrado " << endl;
            }
        }

        // saca la media aritmetica de una serie de numeros ingresados por el teclado
        float mediaAritmetica()
        {
            cout << "Ingrese el numero de datos " << endl;
            cin >> n;
            cout << endl;

            x[n];

            media = 0;

            for (int i = 0; i < n; i++)
            {
                cout << "Numero " << i + 1 << ": ";
                cin >> x[i];
            }
            cout << endl;

            for(int i = 0; i < n; i++)
            {
                media = media + x[i];
            }
            media = media/n;

            return media;
        }

        // imprime opciones para sacar la media aritmetica de una serie de numeros a la pantalla
        void mediaDisplay()
        {
            int option;
            cout << "Presione 0 para ingresar los datos por el teclado " << endl;
            cout << "Presione 1 para ingresar los datos por medio de un archivo " << endl;
            cin >> option;

            if (option == 0)
            {
                mediaAritmetica();
                cout << "La media aritmetica de los numeros ingresados es " << setprecision(3) << media << endl;
            }
            if (option == 1)
            {
                mediaAritmeticaFile();
                cout << "La media aritmetica de los numeros ingresados es " << setprecision(3) << media << endl;
            }
        }

        // lee una serie de numeros dentro de un archivo de texto y saca su desviacion estandar
        float desviacionFile()
        {
            ifstream file ("numeros.txt");
            int i = 0;
            media = 0;
            desviacion = 0;
            suma = 0;
            varianza = 0;

            if (file.is_open())
            {
                while (!file.eof())
                {
                    file >> x[i];

                    i++;
                }

                int length = i;

                for(i = 0; i < length; i++)
                {
                    media = media + x[i];
                }
                media = media/length;

                for(int i = 0; i < length; i++)
                {
                    suma = suma + ((x[i] - media) * (x[i] - media));
                }

                varianza = (float) suma / length;

                desviacion = sqrt(varianza);

                return desviacion;

            file.close(); // cierra el archivo asociado con el programa y lo desasocia despues
            }

            // si esque el archivo no esta asociado el programa imprime un mensaje en la pantalla que lo indica
            else
            {
                cout << "El archivo no pudo ser encontrado " << endl;
            }
        }

        // saca la desviacion estandar de una serie de numeros ingresados por el teclado
        float Desviacion()
        {
            media = 0;
            desviacion = 0;
            suma = 0;
            varianza = 0;

            cout << "Ingrese el numero de datos " << endl;
            cin >> n;
            cout << endl;

            x[n];

            for (int i = 0; i < n; i++)
            {
                cout << "Numero " << i + 1 << ": ";
                cin >> x[i];
            }
            cout << endl;

            for(int i = 0; i < n; i++)
            {
                media = media + x[i];
            }
            media = media/n;

            for(int i = 0; i < n; i++)
            {
                suma = suma + ((x[i] - media) * (x[i] - media));
            }
            varianza = (float ) suma / n;

            desviacion = sqrt(varianza);

            return desviacion;
        }

        // imprime opciones para calcular la desviacion estandar de una serie de numeros a la pantalla
        void desviacionDisplay()
        {
            int option;
            cout << "Presione 0 para ingresar los datos por el teclado " << endl;
            cout << "Presione 1 para ingresar los datos por medio de un archivo " << endl;
            cin >> option;

            if (option == 0)
            {
                Desviacion();
                cout << "La desviacion estandar de los numeros ingresados es " << setprecision(6) << desviacion << endl;
            }
            if (option == 1)
            {
                desviacionFile();
                cout << "La desviacion estandar de los numeros ingresados es " << setprecision(6) << desviacion << endl;
            }
        }

    private:
        // se declara variables para realizar operaciones matematicas
        int n, num1, num2, suma, resta, multiplicacion;
        float division, media, varianza, desviacion;
        float x[100];
};

int main ()
{
	int a, b, y = 0;

	int x;

	Operaciones MiOperacion;

    while (y == 0)
	{
	    // imprime un menu de opciones a la pantalla
	    system("clear");
        cout << "\n\t\t\tCalculadora Cientifica " << endl
        << "\nPorfavor ingrese el tipo de operacion: \n" << endl
        << "1 - Suma " << endl
        << "2 - Resta " << endl
        << "3 - Multiplicacion " << endl
        << "4 - Division " << endl
        << "5 - Media Aritmetica " << endl
        << "6 - Desviacion Estandar \n" << endl;

        // el usuario elige una de esas opciones
        cout << "Opcion: ";
        cin >> x;
        system("clear");

        cin.ignore();

		switch (x)
		{
		    // si el usuario elige 1 se suman dos numeros
			case 1:
                cout << "Ingrese los valores para 2 numeros enteros \n" << endl;
                cout << "Numero 1: ";
                cin >> a;
                cout << "Numero 2: ";
                cin >> b;
                cout << endl;
                MiOperacion.setNumbers(a, b);
                MiOperacion.getNumbers();
				MiOperacion.Suma();
				MiOperacion.sumaDisplay();
				break;

            // si el usuario elige 2 se restan 2 numeros
			case 2:
                cout << "Ingrese los valores para 2 numeros enteros \n" << endl;
                cout << "Numero 1: ";
                cin >> a;
                cout << "Numero 2: ";
                cin >> b;
                cout << endl;
                MiOperacion.setNumbers(a, b);
                MiOperacion.getNumbers();
				MiOperacion.Resta();
				MiOperacion.restaDisplay();
				break;

            // si el usuario elige 3 se multiplican 2 numeros
			case 3:
                cout << "Ingrese los valores para 2 numeros enteros \n" << endl;
                cout << "Numero 1: ";
                cin >> a;
                cout << "Numero 2: ";
                cin >> b;
                cout << endl;
                MiOperacion.setNumbers(a, b);
                MiOperacion.getNumbers();
                MiOperacion.Multiplicacion();
                MiOperacion.multiplicacionDisplay();
				break;

            // si el usuario elige 4 se dividen 2 numeros
			case 4:
                cout << "Ingrese los valores para 2 numeros enteros \n" << endl;
                cout << "Numero 1: ";
                cin >> a;
                cout << "Numero 2: ";
                cin >> b;
                cout << endl;
                MiOperacion.setNumbers(a, b);
                MiOperacion.getNumbers();
                MiOperacion.Division();
                MiOperacion.divisionDisplay();
				break;

            // si el usuario elige 5 se saca la media aritmetica de una serie de numeros
			case 5:
			    MiOperacion.mediaDisplay();
				break;

            // si el usuario elige 6 se saca la desviacion estandar de una serie de numeros
			case 6:
			    MiOperacion.desviacionDisplay();
				break;

            // de lo contrario el programa imprime un mensaje para alertar al usuario
			default:
				cout << "valor desconocido ";
		}

        // opcion para terminar o continuar el programa
		cout << "0 para continuar 1 para salir " << endl;
		cin >> y;
	}

    // exito
	return 0;
}
