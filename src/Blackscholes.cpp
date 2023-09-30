#include "Blackscholes.h"
#include "plot.h"

Blackscholes::Blackscholes(double T, double r, double sigma, double K, double L) : T_(T), r_(r), sigma_(sigma), K_(K), L_(L) {

}

double Blackscholes::get_T() const{
    return T_;
}

double Blackscholes::get_r() const{
    return r_;
}

double Blackscholes::get_sigma() const{
    return sigma_;
}

double Blackscholes::get_K() const{
    return K_;
}

double Blackscholes::get_L() const{
    return L_;
}

Matrix extract(Matrix C){
   
    Matrix E(1,M+1);
    for(int i = 0; i < M+1; i++){
        E(i, 0) =  C(i, N-1); //On remplit E avec les valeurs de la N-1ème colonne de C
        std::cout << E(i,0) << std::endl;
    }
    return E;
}

void plot(Matrix v)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Erreur SDL_Init" << std::endl;
    }
    else{
        SDL_Window *window = SDL_CreateWindow("C(0,S)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            W, H, SDL_WINDOW_SHOWN);
        if(!window){
            std::cout << "Erreur SDL_CreateWindow" << std::endl;
        }
        else {
            SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(!rend)
            {
                std::cout << "Erreur SDL_CreateRenderer" << std::endl;
            }
            else
            {   
                display(rend, v);
                SDL_DestroyRenderer(rend);
            }
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }
}

void plot(Matrix v1, Matrix v2){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Erreur SDL_Init" << std::endl;
    }
    else{
        SDL_Window *window = SDL_CreateWindow("C(0,S), v1 = red, v2 = green", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            W, H, SDL_WINDOW_SHOWN);
        if(!window){
            std::cout << "Erreur SDL_CreateWindow" << std::endl;
        }
        else{
            SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(!rend){
                std::cout << "Erreur SDL_CreateRenderer" << std::endl;
            }
            else{   
                display(rend, v1, v2);
                SDL_DestroyRenderer(rend);
            }
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }
}

void plot(Matrix v1, Matrix v2, Matrix v3){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Erreur SDL_Init" << std::endl;
    }
    else{
        SDL_Window *window = SDL_CreateWindow("C(0,S), v1 = red, v2 = green, v3 = blue", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            W, H, SDL_WINDOW_SHOWN);
        if(!window){
            std::cout << "Erreur SDL_CreateWindow" << std::endl;
        }
        else{
            SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(!rend){
                std::cout << "Erreur SDL_CreateRenderer" << std::endl;
            }
            else{   
                display(rend, v1, v2, v3);
                SDL_DestroyRenderer(rend);
            }
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }
}


