#ifndef BLACKSCHOLESFULL_H
#define BLACKSCHOLESFULL_H

#include "Blackscholes.h"

/**
* @class BlackscholesFull
* @brief Classe abstraite BlackscholesFull, héritant de la classe abstraite Blackscholes, concernant les méthodes de résolution de l'équation aux dérivées partielles de Black et Scholes
*
*
*/
class BlackscholesFull : public Blackscholes{   
    using Blackscholes::Blackscholes;

    public:
        /**
        * @fn Matrix bs_explicit() const override
        * @brief Fonction renvoyant la résolution de l'EDP de BS par la méthode des différences finies explicites
        *
        */
        Matrix bs_explicit() const override;


        /**
        * @fn Matrix bs_implicit() const override
        * @brief Fonction renvoyant la résolution de l'EDP de BS par la méthode des différences finies implicites
        *
        */
        Matrix bs_implicit() const override;


        /**
        * @fn Matrix bs_crni() const override
        * @brief Fonction renvoyant la résolution de l'EDP de BS par la méthode de Cranck-Nicholson
        *
        */
        Matrix bs_crni() const override;


        
};

#endif
