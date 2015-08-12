#include <math.h>
#include <stdio.h>
#include "cquadpack.h"

double efunc(double x, void* user_data)
{
	return exp(-x*x)*log(1-x);
}
double efunc2(double x, void* user_data)
{
    return exp(-x);
}
double efunc3(double x, void* user_data)
{
    return cos(100.0*sin(x));
}
int main()
{
	double a,b,epsabs,epsrel,abserr;
	double resabs,resasc;
	double y;
	int irule,neval,ier;
	char buffer[40];
		
//    a = -1.0;
//    b = 1.0;
//    a = 0;
//    b = 1;
    a = 0.0;
    b = 3.14159265358979;
	epsabs = 0.0;
    epsrel = 1e-3;
	
    for (irule = 1; irule <= 6; ++irule) {
        y=dqag(efunc3,a,b,epsabs,epsrel,irule,&abserr,&neval,&ier,0);

        printf("G/K rule = %i\n", irule);
        printf("dqag integral = %.17lg\n",y);
        printf("abserr = %.17lg, neval = %d, ier = %d\n",
	        abserr,neval,ier);
        printf("\n");
    }
    return 0;
}
