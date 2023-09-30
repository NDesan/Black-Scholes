
#include "BlackscholesHeatPut.h"

Matrix BlackscholesHeatPut::bs_init() const
{
    double L = get_L();
    double r = get_r();
    
    double K = get_K();
    double sigma = get_sigma();

    double beta = -0.5*(2*r/(pow(sigma,2))-1);
    
    double delta_x = log(L/N);

    Matrix U(N + 1,M + 1);

    for(int n = 0; n < N+1; n++){
        U(n,0) = std::fmax(0, exp(-beta*delta_x)*(exp(n*delta_x)-K));
    }
   
    return U;

}