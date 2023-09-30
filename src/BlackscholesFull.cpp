#include "BlackscholesFull.h"

Matrix BlackscholesFull::bs_explicit() const{   
    double T = get_T();
    std::cout << "T : " << T << std::endl;
    double L = get_L();
    std::cout << "L : " << L << std::endl;
    double r = get_r();
    std::cout << "r : " << r << std::endl;
    double sigma = get_sigma();
    std::cout << "sigma : " << sigma << std::endl;
    double delta_t = T/M;
    std::cout << "delta_t : " << delta_t << std::endl;
    double delta_S = L/N;
    std::cout << "delta_S : " << delta_S << std::endl;


    double Ln, Mn, Nn = 0;

    Matrix C = bs_init();

    Matrix A(N, M);

    Matrix Y(1, N);
    Matrix X(1, N);

    //On remplit la matrice tridiagonale A avec les formules théoriques 
    for(int n = 0; n < N-1; n++){
        Ln = 1 - (pow(sigma,2)*pow(n,2) + r)*delta_t;
        A(n,n) = Ln; 
        
    }
    

    for(int n = 0; n < N-1; n++){

        Mn = 0.5*(pow(sigma,2)*pow(n,2) + r*n)*delta_t;
        Nn = 0.5*(pow(sigma,2)*pow(n,2)-r*n)*delta_t;

        if (Mn == -0){
            Mn = 0;
        }

        A(n+1,n) = Nn;
        A(n,n+1) =  Mn;
     
    }

    //Obligés de ne pas boucler sur toutes les valeurs sinon programme trop long
    for(int j = M/100; j >= 1  ; j--){
        for(int n = 0; n < N ; n++){
            
            Y(n, 0) =  C(n,N);
        }

        tri(A, Y);

        X = gaussJordan(A,Y);

        for(int n = 1; n < N; n++){
            C(n, j-1) = X(n,0);
        }
        
    }

    return C;
}

Matrix BlackscholesFull::bs_implicit() const{   
    
    double T = get_T();
    double r = get_r();
    double sigma = get_sigma();
    double delta_t = T/M;
    double Ln, Mn, Nn = 0;

    Matrix C = bs_init();
    
    Matrix A(N, M);
    Matrix Y(1,N);
    Matrix X(1,N);


    //On remplit la matrice tridiagonale A avec les formules théoriques

    for(int n = 0; n < N; n++){
        Ln = 1 + (pow(sigma,2)*pow(n,2) + r)*delta_t;
        A(n,n) =  Ln; 
    }
    

    for(int n = 0; n < N-1; n++){

        Mn = -0.5*(pow(sigma,2)*pow(n,2) + r*n)*delta_t;
        Nn = 0.5*(r*n - pow(sigma,2)*pow(n,2))*delta_t;

        if (Mn == -0){
            Mn = 0;
        }

        A(n+1,n) = Mn;
        A(n,n+1) =  Nn; 
        
    }


    //On résout Y = AX
    for(int j = M; j >= 1  ; j--){
    
        for(int n = 0; n < N  ; n++){
            X(n,0) =  C(n, j);
        }

        Matrix Y = A*X;

        for(int n = 1; n < N; n++){
            C(n, j-1) = Y(n,0);
        }
        
    }

    return C;
}

//Cranck-Nicholson est une moyenne de la méthode explicite et de la méthode implicite
Matrix BlackscholesFull::bs_crni() const{  
    Matrix E = bs_explicit();
    Matrix I = bs_implicit();
    Matrix C = I + E;
    return C*0.5;
}



