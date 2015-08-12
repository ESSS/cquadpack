/*  dblint2 -- double integration routine
 *  (C) 1999, C. Bond. All rights reserved.
 *
 *  Uses Gauss-Kronrod integrator
 */
#include <stdio.h>
#include "cquadpack.h"

double x_global;

double g(x)
{
    return x;
}
double h(x)
{
    return x*x;
}

double z(double f(),double x,double g(),double h(),
    double *abserr,double *resabs,double *resasc)
{
    double c,d,result;
    c = g(x);
    d = h(x);
    x_global = x;
    result = G_K61(f,c,d,abserr,resabs,resasc);

}
double f(double y)
{
    return x_global * x_global * y;
}

double dblint(double f(),double a,double b,double g(),double h(),
    double *abserr,double *resabs,double *resasc)
{
    double result;

    result = G_K61(z,a,b,abserr,resabs,resask);
   
    
}
void main()
{
    double a,b;

    a = 0.0;
    b = 1.0;
    result = dblint(f,a,b,g,h,&abserr);
    printf ("Result = %.12lg\n",result);
}
