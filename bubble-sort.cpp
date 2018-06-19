#include <iostream>

using namespace std; 

int main()
{
	int N, temp = 0; 
	
	cout<<"Ingrese el tamano del vector"<<endl;
	cin >> N;
	
	int A[N]; 
	
	for (int i = 0; i < N; i++)
	{
		cout << "Ingrese el elemento " << i + 1 << endl; 
		cin >> A[i]; 
	}
	
	for (int i = 0; i < N; i++)
	{ 
	    for(int j = 0; j < N - 1; j++)
	    {
            if (A[j] > A[j+1])
            {
               temp = A[j];
               A[j] = A[j+1];
               A[j+1] = temp;
            }
	    }
	}
	
	cout<< "El vector ordenado es" << endl;
   	
	for (int i = 0; i < N; i++)
    {
       	cout << A[i] <<"   ";
    }
	cout << endl;
     
	return 0;
}
