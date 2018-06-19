#include <iostream>

using namespace std; 

int main ()
{
	// declara una matriz 3 x 3 de tipo entero (int)
	int C[3][3]; 

	// declara tres variables de tipo entero (int) y les asigna un valor inicial de 0 
	int j, i, suma, contador = 0;


	cout << "Programa para el calculo del determinante de un cuadrado magico = 3x3" << endl;
	cout << endl; 
	
	cout << "Ingrese las dimensiones del cuadrado utilizando numeros del 1 al 9" << endl; 
	cout << endl; 
			
	for (i= 0; i < 3; i++)
	{
   		for (j = 0; j < 3; j++)
   		{
      		do
      		{ 
				cout << "Ingrese el elemento " << i << ", " << j << endl;
 				cin>> C[i][j];
       		}
       		while (C[i][j] < 1 || C[i][j] > 9);
		}	
	}
	cout << endl; 		 
		
	for (i = 0; i < 3; i++)
	{
		
		for (j = 0; j < 3; j++)
		{
			cout << C[i][j];
			cout << "\t";
		}
					
		cout << endl;
	}

	cout << endl;
	
 
//Suma las filas
	suma = 0;
   
	suma = C[0][0] + C[0][1] + C[0][2];
    
	if(suma == 15)
     { 
	 	contador++;
     }
     
    suma = 0;
   
	suma = C[1][0] + C[1][1] + C[1][2];
    
	if(suma == 15)
     { 
	 	contador++;
     }
     
    suma = 0;
   
	suma = C[2][0] + C[2][1] + C[2][2];
    
	if(suma == 15)
     { 
	 	contador++;
     }
     
//Suma las columnas 
	suma = 0;
   
	suma = C[0][0] + C[1][0] + C[2][0];
    
	if(suma == 15)
     { 
	 	contador++;
     }
     
    suma = 0;
   
	suma = C[0][1] + C[1][1] + C[2][1];
    
	if(suma == 15)
     { 
	 	contador++;
     }
     
    suma = 0;
   
	suma = C[0][2] + C[1][2] + C[2][2];
    
	if(suma == 15)
     { 
	 	contador++;
     }
     
//Suma las diagonales

	suma = 0;
   
	suma = C[0][0] + C[1][1] + C[2][2];
    
	if(suma == 15)
     { 
	 	contador++;
     }
     
	suma=0;
     
	suma = C[0][2] + C[1][1] + C[2][0];

	if(suma == 15)
    {
    	contador++;
    }
	
	
	if (contador == 8)
	{
		cout<< "Es un cuadrado magico!" << endl;
	}
 	
	else
 	{ 
 		cout<< "No es un cuadrado magico!" << endl;
 	}
 	
	return 0; 
}

