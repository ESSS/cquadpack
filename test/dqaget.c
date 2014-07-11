#include <math.h>
#include <stdio.h>
#include "cquadpak.h"

double efunc(double x)
{
    return 1.0/sqrt(fabs(x*x+2.0*x-2.0));
}
void main()
{
	double a,b,epsabs,epsrel,abserr;
	double resabs,resasc;
	double y;
    int irule,neval,ier,last,i;
	char buffer[40];
		
    a = 0.0;
    b = 1.0;
	epsabs = 0.0;
	epsrel = 1e-8;
	
    for (irule = 1; irule <= 6; ++irule) {
        y=dqage(efunc,a,b,epsabs,epsrel,irule,&abserr,&neval,&ier,&last,0);

        printf("G/K rule = %i\n", irule);
        printf("dqage integral = %.17lg\n",y);
	    printf("abserr = %.17lg, neval = %d, ier = %d\n",
		    abserr,neval,ier);
        printf("\n");
    }
}
