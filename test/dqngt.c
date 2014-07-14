#include <math.h>
#include <stdio.h>
#include "cquadpak.h"

double efunc(double x, void* user_data)
{
	if ((x == 0.0) || (x == 1.0)) return 0.0;
	return sqrt(x / (1.0-x)) * log(x);
}

double efunc2(double x, void* user_data)
{
    return sqrt(x)*log(x);
}

int main()
{
	double a,b,epsabs,epsrel,abserr;
	double resabs,resasc;
	double y;
	int neval,ier;
		
	a = 0.0;
	b = 1.0;
    epsabs = 0.0e-8;
	epsrel = 1e-12;
		
    y=dqng(efunc2,a,b,epsabs,epsrel,&abserr,&neval,&ier,0);

	printf("dqng integral = %.17lg\n",y);
	printf("abserr = %.17lg, neval = %d, ier = %d\n",
		abserr,neval,ier);
    return 0;
}
