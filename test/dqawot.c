#include <stdio.h>
#include <float.h>
#include <math.h>
#include "cquadpak.h"

double f(double x, void* user_data)
{
	if (x > 0.0) return log(x);
	return 0.0;
}
double f2(double x, void* user_data)
{
    return log(x)*sin(10.0*x);
}

void main()
{
	double a,b,omega,result,abserr,epsabs,epsrel;
	int ier,neval;

	a = 0.0;
	b = 1.0;
	omega = 10.0 * Pi;
	epsabs = 0.0;
    epsrel = 1e-6;
	result = dqawo(f,a,b,omega,SINE,epsabs,epsrel,&abserr,&neval,&ier,0);
	printf("\nresult = %.18lg\n",result);
	printf("abserr = %.18lg\n",abserr);
	printf("neval = %d\n",neval);
	printf("ier = %d\n",ier);
}
