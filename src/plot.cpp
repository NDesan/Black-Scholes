#include "plot.h"


void wait(void){
    SDL_Event event;
    while(event.type != SDL_QUIT && SDL_WaitEvent(&event));
}


void draw_axis(SDL_Renderer *rend){   
    SDL_Color black = {0, 0, 0, 255};
    SDL_SetRenderDrawColor(rend, black.r, black.g, black.b, black.a);

    SDL_RenderDrawLine(rend, -X_MIN * X_COEFF, 0, -X_MIN * X_COEFF, H);
    SDL_RenderDrawLine(rend, 0, Y_MAX * Y_COEFF, W, Y_MAX * Y_COEFF);
}


void draw_function(SDL_Renderer *rend, Matrix v){   
    double pas = (X_MAX - X_MIN) / PAS;
    double x_prec = X_MIN;
    double y_prec = v(X_MIN,0);

    for(size_t i = 0; i < PAS; i++){   
        double x = x_prec + pas; 
        double y = v(x,0);
        
        SDL_RenderDrawLine(rend, (x_prec - X_MIN) * X_COEFF, (Y_MAX - y_prec) * Y_COEFF, (x - X_MIN) * X_COEFF, (Y_MAX - y) * Y_COEFF);

        x_prec = x;
        y_prec = y;
    }
}

void set_window_color(SDL_Renderer *rend, SDL_Color col){
    SDL_SetRenderDrawColor(rend, col.r, col.g, col.b, col.a);
    SDL_RenderClear(rend);
}



void display(SDL_Renderer *rend, Matrix v)
{
    SDL_Color light_g = {220, 220, 220, 255}; 
    set_window_color(rend, light_g);

    draw_axis(rend);
    
    SDL_Color red = {255, 0, 0, 255};
    SDL_SetRenderDrawColor(rend, red.r, red.g, red.b, red.a);
    draw_function(rend, v);
    SDL_RenderPresent(rend);
    
    std::cout << std::endl;
    std::cout << "|| Courbe affichée sur fenêtre SDL. ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour quitter l'affichage. ||" << std::endl;
    std::cout << std::endl;
    
    wait();
    
}

void display(SDL_Renderer *rend, Matrix v1, Matrix v2)
{
    SDL_Color light_g = {220, 220, 220, 255}; 
    set_window_color(rend, light_g);

    draw_axis(rend);

    SDL_Color red = {255, 0, 0, 255};
    SDL_SetRenderDrawColor(rend, red.r, red.g, red.b, red.a);
    draw_function(rend, v1);

    SDL_Color green = {0, 128, 0, 255};
    SDL_SetRenderDrawColor(rend, green.r, green.g, green.b, green.a);
    draw_function(rend, v2);
    
    SDL_RenderPresent(rend);
    
    std::cout << std::endl;
    std::cout << "|| Courbes affichées sur fenêtre SDL. ||" << std::endl;
    std::cout << "|| vecteur 1 : courbe rouge ||" << std::endl;
    std::cout << "|| vecteur 2 : courbe verte ||" << std::endl;
    std::cout << "||                          ||" << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour quitter l'affichage. ||" << std::endl;
    std::cout << std::endl;

    wait();
    
}


void display(SDL_Renderer *rend, Matrix v1, Matrix v2, Matrix v3){
    SDL_Color light_g = {220, 220, 220, 255}; 
    set_window_color(rend, light_g);

    draw_axis(rend);


    SDL_Color red = {255, 0, 0, 255};
    SDL_SetRenderDrawColor(rend, red.r, red.g, red.b, red.a);
    draw_function(rend, v1);

    SDL_Color green = {0, 128, 0, 255};
    SDL_SetRenderDrawColor(rend, green.r, green.g, green.b, green.a);
    draw_function(rend, v2);

    SDL_Color blue = {0, 0, 255, 255};
    SDL_SetRenderDrawColor(rend, blue.r, blue.g, blue.b, blue.a);
    draw_function(rend, v3);


    SDL_RenderPresent(rend);
    
    std::cout << std::endl;
    std::cout << "Courbes affichées sur fenêtre SDL." << std::endl;
    std::cout << "|| vecteur 1 : courbe rouge" << std::endl;
    std::cout << "|| vecteur 2 : courbe verte" << std::endl;
    std::cout << "|| vecteur 3 : courbe bleue" << std::endl;
    std::cout << "||                         " << std::endl;
    std::cout << "|| Fermer la fenêtre SDL pour quitter l'affichage." << std::endl;
    std::cout << std::endl;

    wait();
    
}

