#ifndef BLACKSCHOLESHEATCALL_H
#define BLACKSCHOLESHEATCALL_H

#include "BlackscholesHeat.h"

/**
* @class BlackscholesHeatCall
* @brief Classe BlackscholesHeatCall, héritant de la classe abstraite BBlackscholesHeat, concernant les conditions initiales call de l'équation réduite de Black et Scholes
*
*/
class BlackscholesHeatCall : public BlackscholesHeat
{   
    using BlackscholesHeat::BlackscholesHeat;
    
    public:
        /**
        * @fn Matrix bs_init() const override
        * @brief Fonction renvoyant la matrice initialisée avec les CI call, pour l'équation de BS réduite
        *
        */
        Matrix bs_init() const override;
};

#endif
