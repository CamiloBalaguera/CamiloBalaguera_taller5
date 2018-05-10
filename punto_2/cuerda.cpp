#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

const float tfin = 200.0;
const float c = 2.0;
const float dt = 0.04;
const float dx = 0.08;
const float L = 100.0;
const int nx = L/dx; // Numero de datos espaciales
const int nt = tfin/dt;
float x[nx];
float u[nx]; // Matriz de amplitudes. 
float upast[nx]; // Matriz de amplitudes. 
float ufut[nx]; // Matriz de amplitudes. 
float uini[nx]; // Matriz de amplitudes. 
float k = pow(c*(dt/dx), 2);
int dimension[nx];

int main()
{	
	dimension[1] = nx;
	dimension[2] = nt; 
	// Condiciones de frontera.
	uini[0] = 0.0;
	uini[nx-1] = 0.0;
	ufut[0] = 0.0;
	ufut[nx-1] = 0.0;
	x[0] = 0.0;
	x[nx-1] = L;
	
	// Condiciones iniciales.

	for (int i = 1; i < nx-1; i++)
	{
		cout << dimension[i] << " ";
		x[i] = x[i-1] + dx;

		if (x[i] <= 0.8*L)
		{
			uini[i] = 1.25*x[i]/L;
		}
		else
		{
			uini[i] = 5 - (5*x[i]/L);
		}
	}
	cout << endl;

	// Condiciones iniciales derivada
	for (int i = 1; i < nx-1; i++)
	{
		ufut[i] = uini[i] + (k/2)*(uini[i+1] - 2*uini[i] + uini[i-1]);
	}	
	
	// Mecanismo para realizar la evolución para la primera iteración.
	for (int i = 0; i < nx; i++)
	{
		upast[i] = uini[i];
		u[i] = ufut[i];
	}

	// Impresión y evolución del resto de iteraciones. 
	for (int j = 0; j < nt; j++)
	{
		for (int i = 1; i < nx-1; i++)
		{

			cout << u[i] << " " ;
			ufut[i] = (2*(1-k))*u[i] - upast[i] + (k)*(u[i+1] + u[i-1]);
		}

		for (int i = 0; i < nx; i++)
		{
			upast[i] = u[i];
			u[i] = ufut[i];
		}
		cout << endl;
	}

	return 0;
}
