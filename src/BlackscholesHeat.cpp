#include "BlackscholesHeat.h"


Matrix BlackscholesHeat::bs_explicit() const
{
    double T = get_T();
    std::cout << "T : " << T << std::endl;

    double L = get_L();
    std::cout << "L : " << L << std::endl;

    double sigma = get_sigma();
    std::cout << "sigma : " << sigma << std::endl;

    double delta_t = T/M;
    std::cout << "delta_t : " << delta_t << std::endl;
    
    double delta_tau = -pow(sigma,2)/2*delta_t;
    std::cout << "delta_tau : " << delta_tau << std::endl;

    double delta_x = log(L/M);
    std::cout << "delta_x : " << delta_x << std::endl;

    double alpha = delta_tau/pow(delta_x,2);
    std::cout << "alpha : " << alpha << std::endl;
    

    double Ln, Mn, Nn = 0;
    
    Matrix U = bs_init();

    Matrix A(N+1, M+1);
    Matrix Y(1, N+1);
    Matrix X(1, N+1);

    //Matrice A
    for(int n = 0; n < N-1; n++){
        Ln = 1-2*alpha;
        A(n,n) = Ln; 
    }
    

    for(int n = 0; n < N-1; n++){
        Mn = alpha;
        Nn = alpha;

        if (Mn == -0){
            Mn = 0;
        }
        A(n+1,n) = Nn;
        A(n,n+1) =  Mn;
        
        
    }


    //Matrice Y
    for(int j = M/100; j >= 1 ; j--){
        for(int n = 0; n < N ; n++){
            X(n, 0) =  U(n,j);
        }
        
        tri(A, Y);

        X = gaussJordan(A,Y);
        
    }

    return U;
}


Matrix BlackscholesHeat::bs_implicit() const{   

    double T = get_T();
    double L = get_L();
    double r = get_r();
    double sigma = get_sigma();
    double delta_t = T/M;
    double delta_tau = -pow(sigma,2)/2*delta_t;
    double delta_x = log(L/M);
    double alpha = delta_tau/pow(delta_x,2);
    double beta =-0.5*(2*r/pow(sigma,2) - 1);
    double gamma = -0.25*pow(2*r/pow(sigma,2) + 1, 2.0);
    double Ln, Mn, Nn = 0;
    
    Matrix U = bs_init();
    

    Matrix A(N, M);
    Matrix Y(1,N);
    Matrix X(1,N);


    //Matrice A
    for(int n = 0; n < N-1; n++){
        Ln = 1+2*alpha;
        A(n,n) = Ln; 
    }
    

    for(int n = 0; n < N-1; n++){
        Mn = -alpha;
        Nn = -alpha;

        if (Mn == -0){
            Mn = 0;
        }
        A(n+1,n) = Nn;
        A(n,n+1) =  Mn;
        
    }

    for(int j = M; j >= 1  ; j--){
        for(int n = 0; n < N  ; n++){
            X(n,0) =  U(n, j);
        }
       
        Matrix Y = A*X;

        for(int n = 1; n < N; n++){
            U(n, j-1) = Y(n,0);
        }
        
        
        
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            U(i,j) = U(i,j)/exp(beta*delta_x*i + delta_tau*gamma*j);
        }
    }
    return U;
}


Matrix BlackscholesHeat::bs_crni() const{
    Matrix A = bs_implicit();
    Matrix B = bs_explicit();
    Matrix S = A + B;
    return 0.5*S;
}


