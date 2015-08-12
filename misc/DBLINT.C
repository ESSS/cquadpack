/* dblint.c -- example of double integrator.
 *
 *      Main routine calls the outer routine which points
 *      to a function which computes the upper and lower
 *		integration limits for the inner routine and
 *      returns the computed integral.
 */ 
 		
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "cquadpack.h"

double y_global;

double f(double x)
{
	return log(x * x * y_global * y_global);
}

double f1(double x)
{
    return x * x * y_global;
}

double g(double x)
{
	double y,a,b,abserr,resabs,resasc;

	a = 1.0;
	b = sqrt(2.0);
	y_global = x;
	y = G_K61(f,a,b,&abserr,&resabs,&resasc);
	return y;
}
double g1(double x)
{
    double y,a,b,abserr,resabs,resasc;

    a = 0.0;
    b = 1.0;
    y_global = x;   /* 'x' is provided by the outer integrator */
    y = G_K61(f1,a,b,&abserr,&resabs,&resasc);
    return y;
}

void main()
{
    double y,a1,b1,abserr,resabs,resasc;
	
    a1 = 0;
    b1 = 1;

    y = G_K61(g1,a1,b1,&abserr,&resabs,&resasc);
	
	printf("Integral = %.15lg\n",y);
	printf("abserr = %.15\lg\n",abserr);
}
