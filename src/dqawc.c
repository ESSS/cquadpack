#include <stdio.h>
#include <math.h>
#include <float.h>
#include "cquadpak.h"

/*  DQAWC - Computation of Cauchy principal value
 *
 *  PARAMETERS:
 *
 *      f() -   double precision function defining the integrand.
 *
 *      a   -   lower limit of integration
 *
 *      b   -   upper limit of integration
 *
 *      c   -   parameter in the weight function
 *
 *      epsabs  -   absolute accuracy requested
 *
 *      epsrel  -   relative accuracy requested
 *
 *      abserr  -   estimate of the modulus of the absolute error
 *
 *      neval   -   number of function evaluations
 *
 *      ier     -   error code
 */
double dqawc(double f(),double a,double b,double c,double epsabs,
    double epsrel,double *abserr,int *neval,int *ier)
{
        double result;

        result = dqawce(f,a,b,c,epsabs,epsrel,abserr,neval,ier);
        return result;
}
        
