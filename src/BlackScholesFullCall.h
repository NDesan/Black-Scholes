
#ifndef BLACKSCHOLESFULLCALL_H
#define BLACKSCHOLESFULLCALL_H

#include "BlackscholesFull.h"
#include "matrix.h"
/**
* @class BlackscholesFullCall
* @brief Classe BlackscholesFullCall, héritant de la classe abstraite BlackscholesFull, concernant les conditions initiales call de l'équation aux dérivées partielles de Black et Scholes
*
*/
class BlackscholesFullCall : public BlackscholesFull{   
    using BlackscholesFull::BlackscholesFull;
    
    public:
        /**
        * @fn Matrix bs_init() const override
        * @brief Fonction renvoyant la matrice initialisée avec les CI call, pour l'EDP de BS
        *
        */
        Matrix bs_init() const override;
};

#endif
