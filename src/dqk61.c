#include <float.h>
#include <math.h>
#include "cquadpack.h"

double G_K61(dq_function_type f,double a,double b,double *abserr,
    double *resabs,double *resasc, void* user_data)
{
/* Gauss-Kronrod abscissae and weights for 61 - 30 rules */

    static double XGK61[31] = {
        0.99948441005049063757,
        0.99689348407464954027,
        0.99163099687040459486,
        0.98366812327974720997,
        0.97311632250112626837,
        0.96002186496830751222,
        0.94437444474855997942,
        0.92620004742927432588,
        0.90557330769990779855,
        0.88256053579205268154,
        0.85720523354606109896,
        0.82956576238276839744,
        0.79972783582183908301,
        0.76777743210482619492,
        0.73379006245322680473,
        0.69785049479331579693,
        0.66006106412662696137,
        0.62052618298924286114,
        0.57934523582636169176,
        0.53662414814201989926,
        0.49248046786177857499,
        0.44703376953808917678,
        0.40040125483039439254,
        0.35270472553087811347,
        0.30407320227362507737,
        0.25463692616788984644,
        0.20452511668230989144,
        0.15386991360858354696,
        0.10280693796673703015,
        0.05147184255531769583,
        0.00000000000000000000};
    static double WGK61[31] = {
        0.00138901369867700762,
        0.00389046112709988405,
        0.00663070391593129217,
        0.00927327965951776343,
        0.01182301525349634174,
        0.01436972950704580481,
        0.01692088918905327263,
        0.01941414119394238117,
        0.02182803582160919230,
        0.02419116207808060137,
        0.02650995488233310161,
        0.02875404876504129284,
        0.03090725756238776247,
        0.03298144705748372603,
        0.03497933802806002414,
        0.03688236465182122922,
        0.03867894562472759295,
        0.04037453895153595911,
        0.04196981021516424615,
        0.04345253970135606932,
        0.04481480013316266319,
        0.04605923827100698812,
        0.04718554656929915395,
        0.04818586175708712914,
        0.04905543455502977889,
        0.04979568342707420636,
        0.05040592140278234684,
        0.05088179589874960649,
        0.05122154784925877217,
        0.05142612853745902593,
        0.05149472942945156756};
    static double WG30[15] = {
        0.00796819249616660562,
        0.01846646831109095914,
        0.02878470788332336935,
        0.03879919256962704960,
        0.04840267283059405290,
        0.05749315621761906648,
        0.06597422988218049513,
        0.07375597473770520627,
        0.08075589522942021535,
        0.08689978720108297980,
        0.09212252223778612872,
        0.09636873717464425964,
        0.09959342058679526706,
        0.10176238974840550460,
        0.10285265289355884034};

    double fv1[30],fv2[30];
    double absc,centr,dhlgth,dmax1,dmin1;
    double fc,fsum,fval1,fval2,hlgth;
    double resg,resk,reskh,result;
    int j,jtw,jtwm1;

    centr = 0.5 * (a + b);
    hlgth = 0.5 * (b - a);
    dhlgth = fabs(hlgth);

    resg = 0.0;
    fc=(*f)(centr, user_data);
    resk = fc * WGK61[30];
    *resabs = fabs(resk);
    for (j = 0; j < 15; j++) {
        jtw = 2 * j + 1;
        absc = hlgth * XGK61[jtw];
        fval1 = (*f)(centr-absc, user_data);
        fval2 = (*f)(centr+absc, user_data);
        fv1[jtw] = fval1;
        fv2[jtw] = fval2;
        fsum = fval1 + fval2;
        resg += WG30[j] * fsum;
        resk += WGK61[jtw] * fsum;
        *resabs = *resabs + WGK61[jtw] * (fabs(fval1) + fabs(fval2));
    }
    for (j = 0; j < 15; j++) {
        jtwm1 = j * 2;
        absc = hlgth * XGK61[jtwm1];
        fval1 = (*f)(centr-absc, user_data);
        fval2 = (*f)(centr+absc, user_data);
        fv1[jtwm1] = fval1;
        fv2[jtwm1] = fval2;
        fsum = fval1 + fval2;
        resk += WGK61[jtwm1] * fsum;
        *resabs = *resabs + WGK61[jtwm1] * (fabs(fval1) + fabs(fval2));
    }
    reskh = resk * 0.5;
    *resasc = WGK61[30] * fabs(fc - reskh);
    for (j = 0; j < 30; j++ )
        *resasc = (*resasc) + WGK61[j] * (fabs(fv1[j] - reskh) +
            fabs(fv2[j] - reskh));
    result = resk * hlgth;
    *resabs = (*resabs) * dhlgth;
    *resasc = (*resasc) * dhlgth;
    *abserr = fabs((resk - resg) * hlgth);
    if ((*resasc != 0.0) && (*abserr != 0.0))
        *abserr = (*resasc) * min(1.0,pow((200.0 * (*abserr)/(*resasc)),1.5));
    if (*resabs > uflow/(50.0 * epmach))
        *abserr = max(epmach * 50.0 * (*resabs),(*abserr));
    return result;
}
