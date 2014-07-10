#include <math.h>
#include <stdio.h>
#include "cquadpak.h"

double efunc(double x)
{
	return log(x)/sqrt(x);
}

void main()
{
	double a,b,epsabs,epsrel,abserr;
	double resabs,resasc;
	double y;
	int neval,ier;
		
	a = 0.0;
	b = 1.0;
    epsabs = 0.0;
    epsrel = 1e-3;
	
    y=dqags(efunc,a,b,epsabs,epsrel,&abserr,&neval,&ier);

	printf("dqags integral = %.17lg\n",y);
	printf("abserr = %.17lg, neval = %d, ier = %d\n",
		abserr,neval,ier);
}
