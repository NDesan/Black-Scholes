#include "BlackscholesFullPut.h"


Matrix BlackscholesFullPut::bs_init() const
{
    double T = get_T();
    double L = get_L();
    double K = get_K();
    double delta_t = T/M;
    double delta_S = L/N;
    double r = get_r(); 
    Matrix C = Matrix(N+1,M+1);

    for(int n = 0; n < N+1; n++){
        C(n,M) =  std::fmax(0, K-n*delta_S);
    }
    for(int j = 0; j < M+1; j++){
        C(0,j) = K * exp(-r*j*delta_t); 
    }
    return C;
}
