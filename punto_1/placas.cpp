#include <iostream>
#include <math.h>
using namespace std;

const float L = 5;
float l = 2;
float d = 1;
const float h = 0.009765625; // 5/512
float Vo = 100;
int N = 2*pow(L/h, 2);
//int N =10000;
const int nx = L/h;
const int ny = L/h;
float U[nx][ny];
float Uold[nx][ny];
float x[nx];
float y[ny];
float w = 1.0;
float Ex[nx][ny];
float Ey[nx][ny];
int main()
{
	// Condiciones de frontera fijas.
	for (int i = 0; i < ny ; i++)
	{
		Uold[0][i] = 0.0;
		Uold[ny-1][i] = 0.0;
		Uold[i][0] = 0.0;
		Uold[i][nx-1] = 0.0;
		U[0][i] = 0.0;
		U[ny-1][i] = 0.0;
		U[i][0] = 0.0;
		U[i][nx-1] = 0.0;
	}

	x[0] = 0.0;
	y[0] = 0.0;
	x[nx-1] = L;
	y[ny-1] = L;


	// Condiciones iniciales.
	for (int i = 1; i < nx-1; i ++)
	{
		x[i] = x[i-1] + h;
		for (int j = 1; j < ny-1; j++)
		{
			y[j] = y[j-1] + h;
			if ((x[i] > 1.5) && (x[i]<3.5) && (y[j]<3.0+(h/2)) && (y[j] > 3.0-(h/2)))
			{ 
				Uold[i][j] = Vo/2;
			}
			else if ((x[i] > 1.5) && (x[i]<3.5) && (y[j]<2.0+(h/2)) && (y[j] > 2.0-(h/2)))
			{
				Uold[i][j] = -1*Vo/2;
				U[i][j] = -1*Vo/2;
			}
		}
	}

	// Hallar solución del potencial.

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < nx; i ++)
		{
			for (int j = 0; j < ny; j++)
			{
				Uold[i][j] = U[i][j];
			}
		}

		for (int i = 1; i < nx-1; i ++)
		{
			for (int j = 1; j < ny-1; j++)
			{
				if ((x[i] > 1.5) && (x[i]<3.5) && (y[j]<3.0+(h/2)) && (y[j] > 3.0-(h/2)))
				{ 
					U[i][j] = Vo/2;
				}

				else if ((x[i] > 1.5) && (x[i]<3.5) && (y[j]<2.0+(h/2)) && (y[j] > 2.0-(h/2)))
				{
					U[i][j] = -1*Vo/2;
				}

				else
				{
					U[i][j] = Uold[i][j] + w*((0.25*(Uold[i+1][j]+Uold[i][j+1]+U[i-1][j]+U[i][j-1])) - Uold[i][j]);
				}
			}	
		}
	}

	// Hallar Campo eléctrico.

	for(int i=0;i<nx-1;i++)
	{
		for(int j=0;j<ny-1;j++)
		{
			Ex[i][j]=-(U[i+1][j]-U[i][j])/(h);
			Ey[i][j]=-(U[i][j+1]-U[i][j])/(h);
		}
		
	} 

	// Imprimir

	for (int i = 0; i < nx; i++)
	{
		cout << x[i]<< " " ;
	}
	cout << endl;

	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny ; j++)
		{ 
			cout << U[i][j] << " " ;
		}
		cout << endl;
	}

	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny ; j++)
		{ 
			cout << Ex[i][j] << " " ;
		}
		cout << endl;
	}

	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny ; j++)
		{ 
			cout << Ey[i][j] << " " ;
		}
		cout << endl;
	}

	return 0;
}
