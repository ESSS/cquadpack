#include <math.h>
#include <stdio.h>
#include "cquadpak.h"

double f(double x)
{
	return log(x)/(1.0 + 100.0*x*x);
}
double f2(double x)
{
    return exp(-x*x);
}
void main()
{
	double bound,epsabs,epsrel,abserr;
	double resabs,resasc;
	double result;
	int inf,neval,ier;
		
	bound = 0.0;
    inf = 1;
	epsabs = 0.0;
	epsrel = 1e-8;
	
    result=dqagi(f,bound,inf,epsabs,epsrel,&abserr,&neval,&ier);

	printf("dqagi integral approximation = %.17lg\n",result);
	printf("estimate of absolute error = %.17lg\n",abserr);
	printf("number of function evaluations = %d\n",neval);
	printf("error code = %d\n",ier);
}
