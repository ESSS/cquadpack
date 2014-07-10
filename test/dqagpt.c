#include <math.h>
#include <stdio.h>
#include "cquadpak.h"

double f(double x)
{
    return pow(x,3.0)*log(fabs((x*x-1.0)*(x*x-2.0)));
}

void main()
{
	double a,b,epsabs,epsrel,abserr,points[4];
	double resabs,resasc,result;

	int neval,npts2,ier;
		
	a = 0.0;
	b = 3.0;
	npts2 = 4;
	points[0] = 1.0;	/* location of singularity #1 */
	points[1] = sqrt(2.0);	/* location of singularity #2 */
	epsabs = 0.0;
    epsrel = 1e-3;
	
	result = dqagp(f,a,b,npts2,points,epsabs,epsrel,&abserr,&neval,&ier);

	printf("dqagp integral = %.17lg\n",result);
	printf("abserr = %.17lg, neval = %d, ier = %d\n",
		abserr,neval,ier);
}
