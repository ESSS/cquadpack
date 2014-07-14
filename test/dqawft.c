#include <stdio.h>
#include <float.h>
#include <math.h>
#include "cquadpak.h"

double f(double x, void* user_data)
{
    return ((x > 0.0) ? (1.0/sqrt(x)) : 0.0);
}
double fx(double x, void* user_data)
{
	return exp(-x);
}

int main()
{
	double a,b,omega,result,abserr,epsabs;
	int ier,neval;

	a = 0.0;
    omega = 0.5 * Pi;
    epsabs = 1.0e-8;
    result =dqawf(fx,a,omega,COSINE,epsabs,&abserr,
		&neval,&ier,0);
	printf("\nresult = %.17lg\n",result);
	printf("abserr = %.17lg\n",abserr);
	printf("neval = %d\n",neval);
    return 0;
}
