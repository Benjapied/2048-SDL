#include "Window.h"
#include <iostream>

Window::Window(const char* name, int width, int height) {

    //Initialisation of video 
    int iError = SDL_Init(SDL_INIT_VIDEO);
    if (iError != 0)
    {
        std::cout << "Error SDL_Init :" << SDL_GetError();
    }

    //Init of the window
    SDL_Window* pWindow = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (pWindow == NULL)
    {
        std::cout << "Erreur SDL_CreateWindow :" << SDL_GetError();
    }

    this->window = pWindow;

    //Init of the renderer
    SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (pRenderer == NULL)
    {
        std::cout << "Erreur SDL_CreateRenderer :" << SDL_GetError();
    }

    this->renderer = pRenderer;

};

Window::~Window() {

    SDL_DestroyRenderer(this->renderer);

    SDL_DestroyWindow(this->window);

    SDL_Quit();

};

void Window::Update() {
    SDL_RenderPresent(this->renderer);
};

void Window::Clear()
{
    SDL_SetRenderDrawColor(this->renderer, 0, 255, 255, 255);
    SDL_RenderClear(this->renderer);
}


