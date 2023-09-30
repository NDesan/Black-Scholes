#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H

#include <iostream>
#include <cmath>

#include "matrix.h"
#include "plot.h"

#define M 1000 // nombre d'intervalles réguliers pour la discrétisation de [0,T]
#define N 1000 // nombre d'intervalles réguliers pour la discrétisation de [0,L]

/**
* @class Blackscholes
* @brief Classe abstraite Blackscholes concernant les bases pour la résolution des différentes formes de l'équation de Black et Scholes
*
*
*/
class Blackscholes{   
    
    /**
    * @brief Temps terminal
    * 
    */
    double T_;

    /**
    * @brief Taux d'intérêt du marché
    * 
    */
    double r_;
    
    /**
    * @brief Volatilité de l'actif
    * 
    */
    double sigma_;

    /**
    * @brief Strike
    * 
    */
    double K_;

    /**
    * @brief Prix maximal
    * 
    */
    double L_;

    public:
        /**
        * @fn Blackscholes(double T, double r, double sigma, double K, double L)
        * @brief Constructeur de classe Blackscholes
        *
        * @param T Temps terminal
        * @param r Taux d'intérêt du marché
        * @param sigma Volatilité de l'actif
        * @param K Strike
        * @param L Prix maximal
        * 
        */
        Blackscholes(double T, double r, double sigma, double K, double L);

        /**
        * @fn double get_T() const
        * @brief Renvoie l'attribut T_ 
        *
        */
        double get_T() const;

        /**
        * @fn double get_r() const
        * @brief Renvoie l'attribut r_ 
        */
        double get_r() const;

        /**
        * @fn double get_sigma() const
        * @brief Renvoie l'attribut sigma_
        */
        double get_sigma() const;

        /**
        * @fn double get_K() const
        * @brief Renvoie l'attribut K_ 
        *
        */
        double get_K() const;

        /**
        * @fn double get_L() const
        * @brief Renvoie l'attribut L_ 
        *
        */
        double get_L() const;

        /**
        * @fn virtual Matrix bs_init() const
        * @brief Fonction virtuelle renvoyant la matrice initialisée avec les conditions initiales 
        *
        */
        virtual Matrix bs_init() const = 0;

        /**
        * @fn virtual Matrix bs_explicit() const
        * @brief Fonction virtuelle renvoyant la résolution de l'équation de BS concernée par la méthode des différences finies explicite
        *
        */
        virtual Matrix bs_explicit() const = 0;

        /**
        * @fn virtual Matrix bs_implicit() const
        * @brief Fonction virtuelle renvoyant la résolution de l'équation de BS concernée par la méthode des différences finies implicite
        *
        */
        virtual Matrix bs_implicit() const = 0;

        /**
        * @fn virtual Matrix bs_crni() const
        * @brief Fonction virtuelle renvoyant la résolution de l'équation de BS concernée par la méthode de Cranck-Nicholson
        *
        */
        virtual Matrix bs_crni() const = 0;
};

/**
* @fn Matrix extract(Matrix C)
* @brief Fonction renvoyant et affichant le vecteur C(N-1,S) (la dernière colonne de la matrice argument)
*
*/
Matrix extract(Matrix C);

/**
* @fn void plot(Matrix v)
* @brief Fonction affichant, dans une fenêtre SDL, 1 courbe de couleur rouge qui approche la matrice argument C(N-1,S)
*
*/
void plot(Matrix v);

/**
* @fn void plot(Matrix v1, Matrix v2)
* @brief Fonction affichant, dans une fenêtre SDL, 2 courbes de couleurs distinctes qui approchent les matrices arguments C(N-1,S) dans une fenêtre SDL
*
*/
void plot(Matrix v1, Matrix v2);

/**
* @fn void plot(Matrix v1, Matrix v2, Matrix v3)
* @brief Fonction affichant, dans une fenêtre SDL, 3 courbes de couleurs distinctes qui approchent les matrices arguments C(N-1,S) dans une fenêtre SDL
*
*/
void plot(Matrix v1, Matrix v2, Matrix v3);

#endif
