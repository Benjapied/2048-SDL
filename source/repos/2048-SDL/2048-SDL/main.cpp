#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "GameObject.h"

// You shouldn't really use this statement, but it's fine for small programs
using namespace std;

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {

    //-------------------
    //Initialisation SDL
    //-------------------

    SDL_Init(SDL_INIT_EVERYTHING);

    const char* title = "2048";
    Window window(title, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Surface* lantern2 = SDL_LoadBMP("img/lantern2.bmp");
    GameObject objet(lantern2, window.renderer, 200, 200);

    SDL_Surface* sakura = SDL_LoadBMP("img/background.bmp");
    GameObject background(sakura, window.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Event event;
    SDL_bool quit = SDL_FALSE;

    //-------------------
    //Initialisation 2048
    //-------------------

    //Initialisation 
    while (!quit)
    {
        //EVENT
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                quit = SDL_TRUE;

        //UPDATE


        window.Clear();
        background.Draw();
        objet.Draw();

        window.Update();
        
    }
    
    SDL_FreeSurface(lantern2);

    window.~Window();

    objet.~GameObject();

    return 0;
}