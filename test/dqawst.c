#include <stdio.h>
#include <float.h>
#include <math.h>
#include "cquadpak.h"

double f(double x, void* user_data)
{
   double result;
   result = 0.0;
   if (x > 0.0) result = (1.0/pow(1.0+log(x)*log(x),2.0));
   return result;
}

int main()
{
    double a,b,alfa,beta,epsabs,epsrel,abserr,result;
    int wgtfunc,neval,ier;

/*  a and b are the integration limits */
    a = 0.0;
    b = 1.0;

/*  alfa, beta and wgtfunc determine the weight function */
    alfa = 0.0;
    beta = 0.0;
    wgtfunc = 2;

/*  epsabs and epsrel determine the accuracy requirement */
    epsabs = 0.0;
    epsrel = 1.0e-5;

    result = dqaws(f,a,b,alfa,beta,wgtfunc,epsabs,epsrel,&abserr,
            &neval,&ier,0);

    printf("Integral approximation = %.12lf\n",result);
    printf("Estimate of absolute error = %.12lf\n",abserr);
    printf("Number of function evaluations = %d\n",neval);
    printf("Error code = %d\n",ier);
    return 0;
}
