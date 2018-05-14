#include <iostream>
#include <cmath>
using namespace std;
const float dt = 0.006;
const float tfin = 3000.0;
const int n = tfin/dt;
float q1[n];
float q2[n];
float p1[n];
float p2[n];
float a = 1/(2*sqrt(2)) ;
float eps = 0.001;
float p1punto(float f1, float f2);
float p2punto(float f1, float f2);
float q1punto(float f1, float f2);
float q2punto(float f1, float f2);
float t[n];
void RK(int i, float (*func)(float, float), float *f, float *y1, float *y2);

int main()
{
	// Condiciones iniciales.
	t[0] = 0.0;
	q1[0] = a;
	q2[0] = -a;
	p1[0] = 0.0;
	p2[0] = 0.0;

	// Iteraciones resolviendo la ecuacion diferencial.
	for(int i = 1; i < n; i++)
	{
		t[i] = t[i-1] + dt;
		RK(i, q1punto, q1, p1, p2);
		RK(i, p1punto, p1, q1, q2);
		RK(i, q2punto, q2, p1, p2);
		RK(i, p2punto, p2, q1, q2);
	}

	// Se imprimen q2 y p2 en caso de que haya un cambio de signo en q1
	for (int i = 0; i <n; i++ )
	{	
		if ((q1[i-1] < 0 && q1[i] > 0) || (q1[i-1] > 0 && q1[i] < 0))
		{
			cout << q2[i] << " " << p2[i] << " " << q1[i] << " " << p1[i] << " " << t[i] <<endl;
		}
		if (i%100 == 0)
		{
			//cout << q2[i] << " " << p2[i] << " " << q1[i] << " " << p1[i] << " " << t[i] <<endl;  
		}
	}
	return 0;
}

float p1punto(float f1, float f2)
{
	return (-2*f1)/(pow(4*pow(f1,2) + pow(eps,2),1.5));
}
float p2punto(float f1, float f2)
{
	return (f1 - f2)/(pow(pow(f1 - f2,2) + pow(eps,2)/4, 1.5)) - (f1 + f2)/(pow(pow(f1 + f2,2) + pow(eps,2)/4,1.5));
}
float q1punto(float f1, float f2)
{
	return f1;
}
float q2punto(float f1, float f2)
{
	return f2;
}

void RK(int i, float (*func)(float, float), float *f, float *y1, float *y2)
{
	float k1 = dt * (func(y1[i-1], 			y2[i-1]));
	float k2 = dt * (func(y1[i-1] + (0.5 * k1), 	y2[i-1] + (0.5 * k1)));
	float k3 = dt * (func(y1[i-1] + (0.5 * k2), 	y2[i-1] + (0.5 * k2)));
	float k4 = dt * (func(y1[i-1] + k3, 		y2[i-1] + k3));	   
	float k = (1.0/6.0)*(k1 + (2.0*k2) + (2.0*k3) + k4);
	f[i] = f[i-1] + k;
}
