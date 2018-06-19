#include <iostream>
using namespace std; 

int collatz(int n)
{
	if (n == 1)
	{
		return 0; 
	}
	else if (n % 2 == 0)
	{
		return 1 + collatz(n/2); 
	}
	else 
	{
		return 1 + collatz(3*n + 1); 
	}
}


int main()
{
	int n; 
	
	cout << "Ingrese la cantidad de numeros en una serie: " << endl; 
	cin >> n; 
	
	collatz(n);
	
	cout << "La cantidad de pasos requeridos para volver a 1 son: " << collatz(n) << endl; 
	
	return 0; 
}
