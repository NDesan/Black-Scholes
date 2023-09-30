#ifndef MATRIX
#define MATRIX

#include <cmath>
#include <iostream>
#include <cstddef>
#include <vector>

/**
 * @brief Class of matrices 
 * 
 */
class Matrix{


    std::vector<std::vector<double>> data_; 
    std::size_t width_;
    std::size_t height_;

    public:

        /**
         * @brief Construct a new Matrix object
         * 
         */
       Matrix() = default; // default constructor
        
        
        /**
         * @brief Declaration of an overloaded matrix, initialized to 0.
         * 
         * @param width 
         * @param height 
         */
        Matrix(std::size_t width, std::size_t height);
        
        /**
         * @brief Declaration of an overloaded constructor
         * 
         * @param data 
         * @param width 
         * @param height 
         */
        Matrix(double** data, std::size_t width, std::size_t height);

        /**
         * @brief Declaration of a copy constructor
         * 
         * @param mat 
         */
        Matrix(const Matrix& other) : data_(other.data_) {}


        /**
         * @brief Destroy the Matrix object
         * 
         */
        ~Matrix() = default; // destructor

        /**
         * @brief Get the Width of the matrix object
         * 
         * @return size_t 
         */
        std::size_t getWidth() const{return data_.empty() ? 0 : data_[0].size();};

        
        
        /**
         * @brief Get the Height of the matrix object
         * 
         * @return size_t 
         */
        std::size_t getHeight() const { return data_.size(); }

        /**
         * @brief Overload of the [] operator. Returns the element located at k 
         * 
         * @param k 
         * @return double 
         */
        // element accessor/modifier
        double& operator()(const std::size_t i, const std::size_t j) { return data_[i][j]; }
        
        Matrix& operator=(const Matrix& other);
        
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

        /**
        * \fn int pivot(int a);
        * \brief Méthode pour trouver le pivot d'une matrice au cours de la résolution de Gauss d'un système linéaire
        *
        * \param a Indice à partir duquel le pivot est recherché
        *
        * \return L'indice de la ligne qui possède le meilleur pivot pour la résolution de Gauss
        *
        * Le pivot n'est recherché que dans les lignes suivantes celle d'indice a.
        *
        * Cette fonction est à utiliser pour la résolution de Gauss d'un système linéaire.
        */
        int pivot(std::size_t a);

        /**
            * \fn void line_switch(int l1, int l2);
            * \brief Méthode réalisant l'échange de ligne dans la matrice
            *
            * \param l1 Indice de la 1ère ligne à échanger
            * \param l2 Indice de la 2ème ligne à échanger
            *
            * Les coefficients des lignes l1 et l2 sont intervertis.
            *
            * Les indices de lignes l1 et l2 doivent correspondre avec la taille de la matrice.
            */
        Matrix& line_switch(std::size_t l1, std::size_t l2);
    
        /**
            * \fn void line_subtract(int l1, int l2, double lambda);
            * \brief Méthode permettant de retirer de la ligne i la ligne j avec un coefficient multiplicateur
            *
            * \param l1 Indice de la ligne de la matrice qui va être origine de la modification
            * \param l2 Indice de la ligne de la matrice qui va être objet de la modification
            * \param lambda Coefficient multiplicateur sur la ligne d'indice l2
            *
            * Les indices de lignes l1 et l2 doivent correspondre avec la taille de la matrice.
            */
        Matrix& line_subtract(int l1, int l2, double lambda);
        
};


/**
 * @brief returns the sum of two matrices
 * 
 * @param m1 
 * @param m2 
 * @return Matrix
 */
Matrix operator+(Matrix& m1, Matrix& m2);



/**
 * @brief returns the difference of two matrices
 * 
 * @param m1 
 * @param m2 
 * @return Matrix
 */
Matrix operator-(Matrix& m1, Matrix& m2);

/**
 * @brief Returns the product of two matrices
 * 
 * @param m1 
 * @param m2 
 * @return Matrix
 */
Matrix operator*(Matrix& m1, Matrix& m2);

/**
 * @brief Returns k*m
 * 
 * @param m1 
 * @param k 
 * @return Matrix
 */
Matrix operator*(Matrix& m, const double k);

/**
 * @brief Returns k*m
 * 
 * @param k 
 * @param m
 * @return Matrix
 */
Matrix operator*(const double k, Matrix& m);

/**
 * @brief Upper-triangularizes A and Y
 * 
 * @param A 
 * @param Y 
 * @return Matrix&
 */
void tri(Matrix& A, Matrix& Y);

/**
 * @brief Performs the Gauss-Jordan elimination on A and Y
 * 
 * @param A
 * @param Y 
 * @return Matrix&
 */
Matrix gaussJordan(Matrix& A, Matrix& Y);

/**
 * @brief Performs the Gauss-Jordan elimination on A and Y
 * 
 * @param A
 * @param Y 
 * @return Matrix&
 */
Matrix error(Matrix C, Matrix C_tilde);

#endif
