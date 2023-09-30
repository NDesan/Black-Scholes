#include "matrix.h"
#include <iostream>
#include <exception>



/**
 * @brief Construct a new Matrix object, initialized to 0
 * 
 * @param width 
 * @param height 
 */
Matrix::Matrix(std::size_t width, std::size_t height) : data_(height, std::vector<double>(width, 0.0)) {}

/**
 * @brief Construct a new Matrix::Matrix object initialized to data
 * 
 * @param data 
 * @param w 
 * @param h 
 */
Matrix::Matrix(double** data, std::size_t width, std::size_t height): data_(height, std::vector<double>(width)){
    for (std::size_t i = 0; i < height; ++i) {
      for (std::size_t j = 0; j < width; ++j) {
        data_[i][j] = data[i][j];
      }
    }
  }
 // copy assignment operator


Matrix& Matrix::operator=(const Matrix& other){
        data_ = other.data_;
        return *this;
}

/**
 * @brief 
 * 
 * @param os 
 * @param m 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Matrix& m){
    double h = m.getHeight();
    double w = m.getWidth();
    os << "\n";
    for (std::size_t i = 0; i < h; i++){
        for (std::size_t j = 0; j < w; j++){

            os << m.data_[i][j] << " ";
        } 
    os << std::endl;
    }
    return os;
}

int Matrix::pivot(std::size_t a) {
    if (this->getHeight() != this->getWidth()) {
        throw std::domain_error("On doit avoir une matrice carrée");
    }

    if (a > getHeight()) {
        throw std::domain_error("Out of bounds");
    }

    int pivot = a ;
    int val = this->operator()(a,a) ;
    for(std::size_t i=a+1; i<this->getWidth(); i++) {
        if(val<this->operator()(i,a)) {
            val = this->operator()(i,a) ;
            pivot = i ;
        }
    }
    return pivot ;
};

Matrix& Matrix::line_switch(std::size_t l1, std::size_t l2) {
    if (l1 > this->getHeight() || l2 > this->getHeight() ) { throw std::domain_error("Les dimensions sont incorrectes");}

    
    double aux1, aux2;
    for(std::size_t i=0; i<this->getWidth(); i++) {
        aux1 = this->operator()(l1,i) ;
        aux2 = this->operator()(l2,i);
        
        this->operator()(l1, i) = aux2;

        this->operator()(l2, i) = aux1;
        
    }
    
    return *this;
};

Matrix& Matrix::line_subtract(int l1, int l2, double lambda) {
    double w = this->getWidth();
    double h = this->getHeight();
    if (l1 > h || l2 > h ) { throw std::domain_error("Les dimensions sont incorrectes");}
    

    for(int k=0; k<w; k++) {
        this->operator()(l2, k) =  lambda * this->operator()(l2,k) - this->operator()(l1,k);
    }


    return *this;
}

/**
 * @brief 
 * 
 * @param m1 
 * @param m2 
 * @return Matrix& 
 */
Matrix operator+(Matrix& m1, Matrix& m2){

    if ((m1.getHeight() != m2.getHeight() || m1.getWidth() != m2.getWidth())) throw std::length_error("Matrices do not have the same dimension");
    int i, j;
    int height= m1.getHeight();
    int width = m1.getWidth();
    Matrix resultat(height, width);
    for (i = 0; i < width; i++){
        for (j = 0; j < height; j++){
            double value = m1(i,j) + m2(i,j);
            resultat(i,j) = value;
        }
    }
    return resultat;
}


/**
 * @brief 
 * 
 * @param m1 
 * @param m2 
 * @return Matrix& 
 */
Matrix operator-(Matrix& m1, Matrix& m2){

    if ((m1.getHeight() != m2.getHeight() || m1.getWidth() != m2.getWidth())) throw std::length_error("Matrices do not have the same dimension");
    int i, j;
    int height= m1.getHeight();
    int width = m1.getWidth();
    Matrix resultat(height, width);
    for (i = 0; i < width; i++){
        for (j = 0; j < height; j++){
            double value = m1(i,j) - m2(i,j);
            resultat(i,j) = value;
        }
    }
    return resultat;
}

//
Matrix operator*(Matrix& M1, Matrix& M2) {
    if(M1.getWidth() != M2.getHeight()) throw std::length_error("Matrices do not have the same dimension");
    
    Matrix tmp(M1.getWidth(),M2.getHeight()) ;
    for(std::size_t i=0; i<M1.getHeight(); i++) {
        for(std::size_t j=0; j<M2.getWidth(); j++) {
            double value_temp = 0;
            
            tmp(i,j) = value_temp;

            
            for(std::size_t k=0; k<M1.getWidth(); k++) {
                value_temp += M1(i,k) * M2(k,j);
            }
            tmp(i,j) = value_temp;
        }
    }
    return tmp ;
}


Matrix operator*(const double k, Matrix& m){

    for (std::size_t i = 0; i < m.getHeight(); i++){
        for (std::size_t j = 0; j < m.getWidth(); j++){
            m(i,j) = k*m(i,j); 
        }
    }
    return m;
}


Matrix operator*(Matrix& m, const double k){
    return operator*(k, m);
}


void tri(Matrix& A, Matrix& Y) { 
    double h = A.getHeight();
    double w = A.getWidth();

    if (h != w) {
        throw std::domain_error("On doit avoir une matrice carrée");
    }
    int p ;
    double mu ;
    for(int i=0; i<h; i++) {
        p = A.pivot(i) ;
        A.line_switch(i, p);

        Y.line_switch(i, p);
        for(int j=i+1; j<h ; j++) {
            if(A(j,i) != 0) {
                mu = (A(i,i))/(A(j,i)) ;

                A.line_subtract(i, j, mu) ;
                Y.line_subtract(i, j, mu) ;
            }

        }
        for (int j = 0; j < w; j++){
            if (A(i,j) == -0){
                A(i,j) = 0;
            }
            if (Y(i,j) == -0){
                Y(i,j) = 0;
            }
        }
    }
};


Matrix gaussJordan(Matrix& A, Matrix& Y)
{
    int n = Y.getHeight();
    Matrix X(1, n);
    
    // Loop through each equation
    for (int i = 0; i < n; i++)
    {
        // Divide the equation by the coefficient of the unknown variable
        double div = A(i,i);
        for (int j = 0; j < n; j++)
        {
            A(i,j) /= div;
        }
        Y(i,0) /= div;

        // Eliminate the unknown variable from the other equations
        for (int k = 0; k < n; k++)
        {
            if (k == i) continue;
            double mul = A(k,i);
            for (int j = 0; j < n; j++)
            {
                A(k,j) -= mul * A(i,j);
            }
            Y(k, 0) -= mul * Y(i,0);
        }

        if (Y(i,0) == -0){
            Y(i,0) = 0;
        }
    }

    // The solution is now stored in the Y vector
    return Y;
}


Matrix error(Matrix C, Matrix C_tilde){
    
    if (C.getHeight() != C_tilde.getHeight() || C.getWidth() != C_tilde.getWidth()){
        throw std::length_error("Les dimensions des matrices ne sont pas les mêmes");
    }
    Matrix E(C.getHeight(), C.getWidth());

    for (std::size_t i = 0; i < C.getWidth(); i++){
        for (std::size_t j = 0; j < C.getHeight(); j++){
            E(i,j) = std::abs(C_tilde(i,j) - C(i,j));
        }
    }
    return E;
}