/* Using quadpack to compute elliptic integral. */
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "cquadpack.h"

double EllipticE(double x)
{
	return sqrt(1.0-0.5*sin(x)*sin(x));
}

void main()
{
	double y,a,b,abserr,resabs,resasc;
	
	a = 0.0;
	b = M_PI_2;
	y = G_K21(EllipticE,a,b,&abserr,&resabs,&resasc);
	printf("Integral = %.15lg\n",y);
	printf("abserr = %.15\lg\n",abserr);
}
