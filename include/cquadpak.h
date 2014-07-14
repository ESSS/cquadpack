#define _USE_MATH_DEFINES
#include <math.h>
#include <float.h>

#define uflow     DBL_MIN
#define oflow     DBL_MAX
#define epmach     DBL_EPSILON
#define LIMIT     500
#define MAXP1     21
#define Pi      M_PI
#define COSINE     1
#define SINE    2

#ifndef FALSE
#define FALSE   0
#endif
#ifndef TRUE
#define TRUE    1
#endif
#ifndef min
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif
#ifndef max
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef double(*dq_function_type)(double, void*);

/* Integration routines */
/* Gauss-Kronrod for integration over finite range. */
double G_K15(dq_function_type f,double a,double b,double *abserr,
    double *resabs, double *resasc, void* user_data);
double G_K21(dq_function_type f,double a,double b,double *abserr,
    double *resabs, double *resasc, void* user_data);
double G_K31(dq_function_type f,double a,double b,double *abserr,
    double *resabs, double *resasc, void* user_data);
double G_K41(dq_function_type f,double a,double b,double *abserr,
    double *resabs, double *resasc, void* user_data);
double G_K51(dq_function_type f,double a,double b,double *abserr,
    double *resabs, double *resasc, void* user_data);
double G_K61(dq_function_type f,double a,double b,double *abserr,
    double *resabs, double *resasc, void* user_data);

/* Gauss-Kronrod for integration over infinite range. */
double G_K15I(dq_function_type f,double boun,int inf,double a,double b,
    double *abserr,double *resabs, double *resasc, void* user_data);

/* Gauss-Kronrod for integration of weighted function. */
double G_K15W(dq_function_type f,double w(),double p1,double p2,double p3,
    double p4,int kp,double a,double b,double *abserr,
    double *resabs, double *resasc, void* user_data);
double dqext(int *n,double epstab[],double *abserr,
    double res3la[],int *nres);
void dqsort(int limit,int last,int *maxerr,double *ermax,
    double elist[],int iord[],int *nrmax);
double dqagi(dq_function_type f,double bound,int inf,double epsabs,
    double epsrel,double *abserr,int *neval,int *ier, void* user_data);
double dqags(dq_function_type f,double a,double b,double epsabs,
    double epsrel,double *abserr,int *neval,int *ier, void* user_data);
double dqagp(dq_function_type f,double a,double b,int npts2,double *points,
    double epsabs,double epsrel,double *abserr,int *neval,int *ier, void* user_data);
double dqng(dq_function_type f,double a,double b,double epsabs,double epsrel,
    double *abserr,int *neval,int *ier, void* user_data);
double dqag(dq_function_type f,double a,double b,double epsabs,double epsrel,
    int irule,double *abserr,int *neval,int *ier, void* user_data);
double dqage(dq_function_type f,double a,double b,double epsabs,double epsrel,
    int irule,double *abserr,int *neval,int *ier,int *last, void* user_data);
double dqwgtc(double x,double c,double p2,double p3,double p4,
    int kp);
double dqwgto(double x,double omega,double p2,double p3,double p4,
    int integr);
double dqwgts(double x,double a,double b,double alpha,double beta,
    int integr);
void dqcheb(double *x,double *fval,double *cheb12,double *cheb24);
double dqc25o(dq_function_type f,double a,double b,double omega,int integr,
    int nrmom,int maxp1,int ksave,double *abserr,int *neval,
    double *resabs,double *resasc,int *momcom,double **chebmo, void* user_data);
double dqfour(dq_function_type f,double a,double b,double omega,int integr,
    double epsabs,double epsrel,int icall,int maxp1,
    double *abserr,int *neval,int *ier,int *momcom,
    double **chebmo, void* user_data);
double dqawfe(dq_function_type f,double a,double omega,int integr,double epsabs,
    int limlst,int maxp1,double *abserr,int *neval,int *ier,
    double *rslst,double *erlist,int *ierlst,double **chebmo, void* user_data);
double dqawf(dq_function_type f,double a,double omega,int integr,double epsabs,
    double *abserr,int *neval,int *ier, void* user_data);
double dqawo(dq_function_type f,double a,double b,double omega,int integr,double epsabs,
    double epsrel,double *abserr,int *neval,int *ier, void* user_data);
double dqaws(dq_function_type f,double a,double b,double alfa,double beta,int wgtfunc,
    double epsabs,double epsrel,double *abserr,int *neval,int *ier, void* user_data);
double dqawse(dq_function_type f,double a,double b,double alfa,double beta,
    int wgtfunc,double epsabs,double epsrel,double *abserr,
    int *neval,int *ier, void* user_data);
void dqmomo(double alfa,double beta,double ri[],double rj[],double rg[],
    double rh[],int wgtfunc);
double dqc25s(dq_function_type f,double a,double b,double bl,double br,double alfa,
    double beta,double ri[],double rj[],double rg[],double rh[],
    double *abserr,double *resasc,int wgtfunc,int *nev, void* user_data);
double dqc25c(dq_function_type f,double a,double b,double c,double *abserr,
    int *krul,int *neval, void* user_data);
double dqawc(dq_function_type f,double a,double b,double c,double epsabs,
    double epsrel,double *abserr,int *neval,int *ier, void* user_data);
double dqawce(dq_function_type f,double a,double b,double c,double epsabs,
    double epsrel,double *abserr,int *neval,int *ier, void* user_data);

double G_B15(dq_function_type f,double a,double b,double *abserr,
    double *resabs, double *resasc, void* user_data);

#ifdef __cplusplus
}
#endif /* __cplusplus */