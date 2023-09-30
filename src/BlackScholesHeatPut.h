#ifndef BLACKSCHOLESHEATPUT_H
#define BLACKSCHOLESHEATPUT_H

#include "BlackscholesHeat.h"

/**
* @class BlackscholesHeatPut
* @brief Classe BlackscholesHeatPut, héritant de la classe abstraite BBlackscholesHeat, concernant les conditions initiales put de l'équation réduite de Black et Scholes
*
*/
class BlackscholesHeatPut : public BlackscholesHeat
{      

    using BlackscholesHeat::BlackscholesHeat;
    
    public:
        /**
        * @fn Matrix bs_init() const override
        * @brief Fonction renvoyant la matrice initialisée avec les CI put, pour l'équation de BS réduite
        *
        */
        Matrix bs_init() const override;
};

#endif
