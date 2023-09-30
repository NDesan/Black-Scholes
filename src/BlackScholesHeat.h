#ifndef BLACKSCHOLESHEAT_H
#define BLACKSCHOLESHEAT_H

#include "Blackscholes.h"

/**
* @class BlackscholesHeat
* @brief Classe abstraite BlackscholesHeat, héritant de la classe abstraite Blackscholes, concernant les méthodes de résolution de l'équation réduite de Black et Scholes
*
*
*/
class BlackscholesHeat : public Blackscholes
{   
    using Blackscholes::Blackscholes;
    
    public:
        /**
        * @fn Matrix bs_explicit() const override
        * @brief Fonction renvoyant la résolution de l'équation de BS réduite par la méthode des différences finies explicite
        *
        */
        Matrix bs_explicit() const override;


        /**
        * @fn Matrix bs_implicit() const override
        * @brief Fonction renvoyant la résolution de l'équation de BS réduite par la méthode des différences finies implicite
        *
        */
        Matrix bs_implicit() const override;

        /**
        * @fn Matrix bs_crni() const override
        * @brief Fonction renvoyant la résolution de l'équation de BS réduite par la méthode de Cranck-Nicholson
        *
        */
        Matrix bs_crni() const override;


        /**
        * @fn Matrix error(Matrix& C, Matrix C_tilde)
        * @brief Fonction renvoyant la matrice des erreurs absolues entre C et C_tilde
        *
        */
        Matrix error(Matrix& C, Matrix C_tilde);
        
};

#endif
