

#ifndef BLACKSCHOLESFULLPUT_H
#define BLACKSCHOLESFULLPUT_H

#include "BlackscholesFull.h"

/**
* @class BlackscholesFullPut
* @brief Classe BlackscholesFullPut, héritant de la classe abstraite BlackscholesFull, concernant les conditions initiales put de l'équation aux dérivées partielles de Black et Scholes
*
*/
class BlackscholesFullPut : public BlackscholesFull
{   
    using BlackscholesFull::BlackscholesFull;
    
    public:
        /**
        * @fn Matrix bs_init() const override
        * @brief Fonction renvoyant la matrice initialisée avec les CI put, pour l'EDP de BS
        *
        */
        Matrix bs_init() const override;
};

#endif
