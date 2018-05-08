#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
const float tini = 0.0; // Valor inicial
const float tfin = 200.0; // Valor final
const float T = 40.0;
const float rho = 10.0;
const float c = sqrt(T/rho); // VElocidad
const float dt = 0.0005; // Diferencial de tiempo
const float dx = 0.001; // Diferencial de espacio
const float L = 100.0;
const int nx = L/dx; // Numero de datos espaciales
const int nt = (tfin-tini)/dt;
float x[nx]; // Lista de posiciones
float u[nx][nt]; // Matriz de amplitudes. Primera dimension espacial. Segunda dimension temporal
float k = pow(c*dt/dx, 2);
void evolucion(void); // Funcion que evoluciona

int main()
{
	cout << nx << " " << nt << endl; // Se imprime el numero de datos espaciales y temporales para utilizar en el .py
	// Condiciones de frontera	
	for (int i = 0; i < nt ; i++)
	{
		u[0][i] = 0.0;
		u[nx-1][i] = 0.0;
	}
	// Valor inicial de posicion
	x[0] = 0.0;

	//Condiciones iniciales.
	for (int i = 1; i < nx-1; i++)
	{
		x[i] = x[i-1] + dx;
		u[i][1] = u[i][0] + k/2*(u[i+1][0] - 2*u[i][0] + u[i-1][0]);
		if (x[i] <= 0.8*L)
		{ 
			u[i][0] = 1.25*x[i]/L;
		}
		else if (x[i] > 0.8*L)
		{
			u[i][0] = 5-(5*x[i]/L);
		}
	}
	
	// Evolucion de la amplitud
	evolucion();
	return 0;
}

// Funcion que evoluciona la funcion amplitud(x, t)
void evolucion(void)
{
	for (int j = 2; j < nt; j++)
	{
		for(int i = 1; i < nx-1; i++)
		{
			u[i][j] = 2*(1-k)*u[i][j-1] - u[i][j-2] + k*(u[i+1][j-1]+u[i-1][j-1]); // Evolución.
		}
	}
	for (int k = 0; k < nt; k+=nt/5)
	{
		for (int i = 0; i < nx; i++)
		{
			cout << x[i] << " " << u[i][k] << endl; // Se imprimen todas las posiciones para 5 tiempos particulares.
		}
	}
}
