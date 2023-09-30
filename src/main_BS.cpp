//#include "matrix.h"

#include "BlackscholesFullCall.h"
#include "BlackscholesFullPut.h"

#include "BlackscholesHeatCall.h"
#include "BlackscholesHeatPut.h"

#include "plot.h"
#include <SDL2/SDL.h>
#include <iostream>


int main(){

    //Réglage des paramètres
    double T = 1;
    double r = 0.1;
    double sigma = 0.1;
    double K = 100;
    double L = 300;

//-------------------------------------------------------------EQUATION REDUITE OK!!----------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------------CALL OK!!----------------------------------------------------------------------------
    //TEST : REDUITE CALL IMPLICITE
    //PAS OK!

    std::cout << "|| RESOLUTION: REDUITE CALL IMPLICITE ||" << std::endl;
    BlackscholesHeatCall BSHC(T, r,sigma, K, L);
    
    std::cout << "|| bs_implicit: calcul en cours... ||" << std::endl;
    Matrix BSHC_mat = BSHC.bs_implicit();
    std::cout << "|| On a finalement la matrice C d'un CALL IMPLICITE de l'équation REDUITE : ||" << std::endl << BSHC_mat;
    
    std::cout << "|| Extraction et affichage d'un vecteur j colonne de C, soit C(0, j) : ||" << std::endl;
    Matrix BSHC_vector = extract(BSHC_mat);
    
    std::cout << BSHC_vector << std::endl;
    //COURBE SDL: REDUITE CALL IMPLICITE
    std::cout << "|| On affiche C(0,j) d'un CALL IMPLICITE de l'équation REDUITE dans la fenêtre SDL : ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour passer à la prochaine résolution. ||" << std::endl;
    plot(BSHC_vector); // C(0,S) REDUITE CALL IMPLICITE



    // //TEST: REDUITE CALL EXPLICITE
    // //OK!
    // std::cout << "|| RESOLUTION: REDUITE CALL EXPLICITE ||" << std::endl;

    // BlackscholesHeatCall BSHC_explicite(T, r,sigma, K, L);


    // std::cout << "|| bs_explicite: calcul en cours... ||" << std::endl;
    // Matrix BSHC_explicite_mat = BSHC_explicite.bs_explicit();
    // std::cout << "|| On a finalement la matrice C d'un CALL EXPLICITE de l'équation REDUITE : ||" << std::endl << BSHC_explicite_mat;

    // std::cout << "|| Extraction et affichage d'un vecteur j colonne de C, soit C(0, j) : ||" << std::endl;
    // Matrix BSHC_explicit_vector = extract(BSHC_explicite_mat);
    
    // //COURBE SDL: FULL CALL EXPLICITE
    // std::cout << "|| On affiche C(0,j) d'un CALL EXPLICITE de l'équation REDUITE dans la fenêtre SDL : ||" << std::endl;
    // std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante. ||" << std::endl;
    // plot(BSHC_explicit_vector); // C(0,S) REDUITE CALL EXPLICITE

    // plot(BSHC_vector, BSHC_explicit_vector);


    // //TEST: REDUITE CRANCK NICHOLSON
    // //OK!
    // std::cout << "|| RESOLUTION: REDUITE CALL CRANCK-NICHOLSON ||" << std::endl;
    // BlackscholesHeatCall BSHCN(T, r, sigma, K, L);

    // std::cout << "|| bs_crni: calcul en cours... ||" << std::endl;
    // Matrix BSHCN_matrix = BSHCN.bs_crni();
    // std::cout << "|| On a finalement la matrice C d'un CALL avec CRANCK-NICHOLSON de l'équation REDUITE : ||" << std::endl << BSHCN_matrix;

    // std::cout << "|| Extraction et affichage d'un vecteur j colonne de C, soit C(0, j) : ||" << std::endl;
    // Matrix BSHCN_matrix_extract = extract(BSHCN_matrix);
    
    // //COURBE SDL: FULL PUT CRANK-NICHOLSON
    // std::cout << "|| On affiche C(0,j) d'un CALL avec CRANCK-NICHOLSON de l'équation REDUITE dans la fenêtre SDL : ||" << std::endl;
    // std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante. ||" << std::endl;   
    // plot(BSHCN_matrix_extract); // C(0,S) FULL PUT CRANK-NICHOLSON

    // plot(BSHC_vector, BSHC_explicit_vector, BSHCN_matrix_extract);

    

//-------------------------------------------------------------PUT OK!!----------------------------------------------------------------------------

    //TEST : REDUITE PUT IMPLICITE
    //OK !
    std::cout << "|| RESOLUTION: REDUITE PUT IMPLICITE ||" << std::endl;
    BlackscholesHeatPut BSHP(T, r,sigma, K, L);
    
    std::cout << "|| bs_implicit: calcul en cours... ||" << std::endl;
    Matrix BSHP_mat = BSHP.bs_implicit();
    std::cout << "|| On a finalement la matrice C d'un PUT IMPLICITE avec l'équation REDUITE : ||" << std::endl << BSHP_mat;
    
    std::cout << "|| Extraction et affichage d'un vecteur j colonne de C, soit C(0, j) : ||" << std::endl;
    Matrix BSHP_vector = extract(BSHP_mat);
    
    //COURBE SDL: REDUITE PUT IMPLICITE
    std::cout << "|| On affiche C(0,j) d'un PUT IMPLICITE de l'équation REDUITE dans la fenêtre SDL : ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante. ||" << std::endl; 
    plot(BSHP_vector); // C(0,S) REDUITE CALL IMPLICITE



    // //TEST: REDUITE PUT EXPLICITE
    // //OK!
    // std::cout << "|| RESOLUTION: REDUITE PUT EXPLICITE ||" << std::endl;
    // BlackscholesHeatPut BSHP_explicite(T, r,sigma, K, L);
    
    // std::cout << "|| bs_explicite: calcul en cours... ||" << std::endl;
    // Matrix BSHP_explicite_mat = BSHP_explicite.bs_explicit();
    // std::cout << "|| On a finalement la matrice C d'un PUT EXPLICITE avec l'équation REDUITE: ||" << std::endl << BSHP_explicite_mat;

    // std::cout << "|| On affiche C(0,j) d'un PUT IMPLICITE de l'équation REDUITE dans la fenêtre SDL : ||" << std::endl;
    // Matrix BSHP_explicit_vector = extract(BSHP_explicite_mat);
    
    // //COURBE SDL: REDUITE PUT EXPLICITE
    // std::cout << "|| On affiche C(0,j) d'un PUT EXPLICITE de l'équation REDUITE dans la fenêtre SDL : ||" << std::endl;
    // std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante. ||" << std::endl; 
    // plot(BSHP_explicit_vector); // C(0,S) REDUITE CALL EXPLICITE

    // std::cout << "|| Affichage des courbes des deux méthodes dans la fenêtre SDL : ||" << std::endl; 
    // //plot(BSHP_vector, BSHP_explicit_vector);

    // //TEST: REDUITE CRANCK NICHOLSON
    // //OK!
    // std::cout << "|| RESOLUTION: PUT REDUITE CRANK-NICHOLSON ||" << std::endl;
    // BlackscholesHeatPut BSHPCN(T, r, sigma, K, L);

    // std::cout << "|| bs_crni: calcul en cours... ||" << std::endl;
    // Matrix BSHPCN_matrix = BSHPCN.bs_crni();
    // std::cout << "|| On a finalement la matrice C d'un PUT avec CRANCK-NICHOLSON de l'équation REDUITE : ||" << std::endl << BSHPCN_matrix;


    // std::cout << "|| On affiche C(0,j) d'un PUT avec CRANCK-NICHOLSON de l'équation REDUITE dans la fenêtre SDL : ||" << std::endl;
    // Matrix BSHPCN_matrix_extract = extract(BSHPCN_matrix);
    
    // // COURBE SDL: REDUITE CRANK-NICHOLSON
    // std::cout << "|| On affiche C(0,j) d'un PUT avec CRANCK-NICHOLSON de l'équation REDUITE dans la fenêtre SDL : ||" << std::endl;
    // std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante. ||" << std::endl;     
    // plot(BSHPCN_matrix_extract); // C(0,S) HEAT PUT CRANK-NICHOLSON

    // plot(BSHP_vector, BSHP_explicit_vector, BSHPCN_matrix_extract);

//-------------------------------------------------------------FULL----------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------//


//-------------------------------------------------------------CALL----------------------------------------------------------------------------

    // TEST : FULL CALL EXPLICITE
    std::cout << "|| RESOLUTION: FULL CALL EXPLICITE ||" << std::endl;
    BlackscholesFullCall BSC(T, r, sigma, K, L);

    std::cout << "|| bs_explicit: calcul en cours... ||" << std::endl;
    Matrix BSC_mat = BSC.bs_explicit();
    std::cout << BSC_mat;
    std::cout << "|| On affiche C(0,j) d'un CALL EXPLICITE de l'équation COMPLETE ||" << std::endl;
    Matrix BSC_vector = extract(BSC_mat);

    // COURBE SDL: FULL PUT EXPLICITE
    std::cout << "|| FULL PUT EXPLICITE: affichage de la courbe C(0,S) dans fenêtre SDL ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante ||" << std::endl;
    plot(BSC_vector); // C(0,S) FULL PUT EXPLICITE

    // TEST: FULL CALL IMPLICITE
    std::cout << "|| RESOLUTION: COMPLETE CALL IMPLICITE ||" << std::endl;
    BlackscholesFullCall BSCI(T, r, sigma, K, L);

    std::cout << "|| bs_implicit: calcul en cours... ||" << std::endl;
    Matrix BSCI_mat = BSCI.bs_implicit();
    std::cout << BSCI_mat;
    std::cout << "|| Extraction et affichage d'un vecteur j colonne de C, soit C(0, j) : ||" << std::endl;
    Matrix BSCI_vector = extract(BSCI_mat);

    std::cout << "|| On affiche C(0,j) d'un CALL IMPLICITE de l'équation COMPLETE dans la fenêtre SDL : ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante. ||" << std::endl;
    plot(BSCI_vector);

    std::cout << "|| Calcul de la matrice des erreurs des solutions trouvées (RENVOIE DES VALEURS ABERRANTES) : ||" << std::endl;
    
    //Matrix Error = error(BSHCN_matrix, BSCI_mat);

    //std::cout << "La matrice des erreurs est : " << extract(Error) << std::endl;
    //std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante. ||" << std::endl;
    //plot(Error);

    //TEST: FULL CRANCK NICHOLSON
    std::cout << "RÉSOLUTION: FULL CALL CRANK-NICHOLSON" << std::endl;
    BlackscholesFullCall BSFCN(T, r, sigma, K, L);

    std::cout << "|| bs_crni: calcul en cours... ||" << std::endl;
    Matrix BSFCN_matrix = BSFCN.bs_crni();
    
    std::cout << "|| On affiche C(0,j) d'un CALL avec CRANCK-NICHOLSON de l'équation COMPLETE ||" << std::endl;
    Matrix BSFCN_matrix_extract = extract(BSFCN_matrix);
    
    // COURBE SDL: FULL CALL CRANK-NICHOLSON
    std::cout << "|| FULL CALL CRANK-NICHOLSON: affichage de la courbe C(0,S) dans fenêtre SDL ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante ||" << std::endl;    
    plot(BSFCN_matrix_extract); // C(0,S) FULL PUT CRANK-NICHOLSON

    plot(BSC_vector, BSCI_vector, BSFCN_matrix_extract);


//-------------------------------------------------------------PUT----------------------------------------------------------------------------


    //  TEST: FULL PUT IMPLICITE
    std::cout << "|| RESOLUTION: FULL PUT IMPLICITE ||" << std::endl;
    BlackscholesFullPut BSP(T, r, sigma, K, L);

    std::cout << "|| bs_implicit: calcul en cours... ||" << std::endl;
    Matrix BSP_mat = BSP.bs_implicit();
    std::cout << BSP_mat;
    std::cout << "|| On affiche C(0,j) d'un PUT IMPLICITE de l'équation COMPLETE ||" << std::endl;
    Matrix BSP_vector = extract(BSP_mat);

    plot(BSP_vector);



    // TEST : FULL PUT EXPLICITE
    std::cout << "|| RESOLUTION: FULL PUT EXPLICITE ||" << std::endl;
    BlackscholesFullPut BSP_explicite(T, r, sigma, K, L);

    std::cout << "|| bs_explicit: calcul en cours... ||" << std::endl;
    Matrix BSP_explicite_mat = BSP_explicite.bs_explicit();
    std::cout << BSP_explicite_mat;
    std::cout << "|| On affiche C(0,j) d'un PUT EXPLICITE de l'équation COMPLETE ||" << std::endl;
    Matrix BSP_explicite_vector = extract(BSP_explicite_mat);

    // COURBE SDL: FULL PUT EXPLICITE
    std::cout << "|| FULL PUT EXPLICITE: affichage de la courbe C(0,S) dans fenêtre SDL ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante ||" << std::endl;
    plot(BSP_explicite_vector); // C(0,S) FULL PUT EXPLICITE


    plot(BSP_vector, BSP_explicite_vector);

    //TEST: REDUITE CRANCK NICHOLSON
    std::cout << "RÉSOLUTION: FULL CALL CRANK-NICHOLSON" << std::endl;
    BlackscholesFullPut BSFPCN(T, r, sigma, K, L);

    std::cout << "|| bs_crni: calcul en cours... ||" << std::endl;
    Matrix BSFPCN_matrix = BSFPCN.bs_crni();
    
    std::cout << "|| On affiche C(0,j) d'un PUT avec CRANCK-NICHOLSON de l'équation COMPLETE ||" << std::endl;
    Matrix BSFPCN_matrix_extract = extract(BSFPCN_matrix);
    


    // COURBE SDL: FULL PUT CRANK-NICHOLSON
    std::cout << "|| FULL PUT CRANK-NICHOLSON: affichage de la courbe C(0,S) dans fenêtre SDL ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour passer à la résolution suivante ||" << std::endl;    
    plot(BSFPCN_matrix_extract); // C(0,S) FULL PUT CRANK-NICHOLSON

    plot(BSP_vector, BSP_explicite_vector, BSFPCN_matrix_extract);
    

    return 0;
}