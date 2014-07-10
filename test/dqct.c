#include <stdio.h>
#include <float.h>
#include <math.h>
#include <malloc.h>
#include "cquadpak.h"

double fx(double x)
{
	return exp(-x);
}

void main()
 {
	double a,b,omega,result,abserr,resabs,resasc;
	double **chebmo;
	int i,nrmom,ksave,n,neval,momcom;
	
	n = 21;
	chebmo = (double **)calloc(n,sizeof(double *));
	for (i = 0;i < n; i++)
		chebmo[i] = (double *)calloc(25,sizeof(double));

	a = 0.0;
	b = 11.0;
	omega = 20.0;
	nrmom = 0;
	ksave = 0;	
	momcom = 0;
	result = dqc25o(fx,a,b,omega,COSINE,nrmom,MAXP1,
		ksave,&abserr,&neval,&resabs,&resasc,
		&momcom,chebmo);
	printf("\nresult = %.14lg\n",result);
	printf("abserr = %lg\n",abserr);
	printf("neval = %d\n",neval);
	printf("momcom = %d\n",momcom);
	for (i=0; i < n; i++)
		free(chebmo[i]);
	free(chebmo);
}
