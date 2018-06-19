#include <iostream>

using namespace std;

int fibonacci(int n)
{
	if (n < 2)
	{
		return n; 
	}
	else 
	{
		return fibonacci(n-1) + fibonacci(n-2);  
	}
}

int main ()
{
	int n = 0;
	
	cout << "Ingrese el numero de terminos de la serie de Fibonacci: " << endl;
	cin >> n;
	
	cout << "Los primeros " << n << " numeros de la serie de fibonacci son: " << endl; 
	
	for (int i = 0; i < n; i++)
	{
		cout << fibonacci(i) << " "; 
	}
	
	return 0; 
}
