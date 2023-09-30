/**
 *
 * \file plot.h
 * \brief Fichier concernant l'affichage de courbes 2D
 *
 * \author Mielle David
 * \version 1.0
 * \date Janvier 2023
 *
 */

#ifndef PLOT_H
#define PLOT_H

#include <iostream>

#include <SDL2/SDL.h>
#include <math.h>
#include "Matrix.h"

#define W 1400
#define H 600

#define X_MIN 0
#define X_MAX 500

#define Y_MIN -50
#define Y_MAX 250

#define X_COEFF W / (X_MAX - X_MIN)
#define Y_COEFF H / (Y_MAX - Y_MIN)

#define PAS 10



/**
* \fn void wait(void)
* \brief Fonction affichant la fenêtre SDL tant que l'utilisateur ne la ferme pas.
*
*/
void wait(void);


/**
* \fn void draw_axis(SDL_Renderer *rend)
* \brief Fonction dessinant les axes des abcisses et des ordonnées.
*
*/
void draw_axis(SDL_Renderer *rend);


/**
* \fn draw_function(SDL_Renderer *rend, Matrix v)
* \brief Fonction dessinant une courbe qui approche le veur argument.
*
*/
void draw_function(SDL_Renderer *rend, Matrix v);

/**
* \fn void set_window_color(SDL_Renderer *rend, SDL_Color col)
* \brief Fonction colorant la fenêtre SDL.
*
*/
void set_window_color(SDL_Renderer *rend, SDL_Color col);


/**
* \fn display(SDL_Renderer *rend, Matrix v)
* \brief Fonction affichant, dans une fenêtre SDL, 1 courbe de couleur rouge qui approche le veur argument.
*
*/
void display(SDL_Renderer *rend, Matrix v);

/**
* \fn void display(SDL_Renderer *rend, Matrix v1, Matrix v2)
* \brief Fonction affichant, dans une fenêtre SDL, 2 courbes de couleurs distinctes qui approchent les veurs arguments.
*
*/
void display(SDL_Renderer *rend, Matrix v1, Matrix v2);

/**
* \fn void display(SDL_Renderer *rend, Matrix v1, Matrix v2, Matrix v3)
* \brief Fonction affichant, dans une fenêtre SDL, 3 courbes de couleurs distinctes qui approchent les veurs arguments.
*
*/
void display(SDL_Renderer *rend, Matrix v1, Matrix v2, Matrix v3);


#endif
