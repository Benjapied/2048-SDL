#include "Window.h"

#include "GameObject.h"
#include "Case.h"

#include <iostream>
#include <conio.h>
#include <SDL.h>

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


    //Init console part
    this->iPoints = 0;
    

};

Window::~Window() {

    SDL_DestroyRenderer(this->renderer);

    SDL_DestroyWindow(this->window);

    SDL_Quit();

};

void Window::WindowGridInit(SDL_Texture** tArray) {
    this->gGameGrid.InitGrid(tArray, this->renderer);
};

void Window::Update() {
    SDL_RenderPresent(this->renderer);
};

void Window::Clear()
{
    SDL_SetRenderDrawColor(this->renderer, 0, 255, 255, 255);
    SDL_RenderClear(this->renderer);
}

void Window::GameLoop(GameObject* background, GameObject* gridBack, SDL_Texture** textureArray)
{
    int iScore = 0;
    bool bIsGame = true;
    bool isWin = false;

    SDL_Event event;
    SDL_bool quit = SDL_FALSE;

    this->gGameGrid.RandNumber();

    while (!quit)
    {
        //EVENT
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = SDL_TRUE;
                }
                if (event.key.keysym.sym == SDLK_DOWN)
                {
                    for (int i = 0; i < 4; i++) {
                        for (int j = 3; j >= 0; j--) {
                            CheckCases(i, j, 0, 1);
                        }
                    }
                    this->gGameGrid.RandNumber();
                }
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    //Left
                    for (int i = 0; i <= 3; i++) {
                        for (int j = 0; j < 4; j++) {
                            CheckCases(i, j, -1, 0);
                        }
                    }
                    this->gGameGrid.RandNumber();

                }
                if (event.key.keysym.sym == SDLK_UP)
                {
                    //Up
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            CheckCases(i, j, 0, -1);
                        }
                    }
                    this->gGameGrid.RandNumber();
                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    for (int i = 3; i >= 0; i--) {
                        for (int j = 0; j < 4; j++) {
                            CheckCases(i, j, 1, 0);
                        }
                    }
                    this->gGameGrid.RandNumber();
                }
            }
        }
        //UPDATE


        this->Clear();
        background->Draw();
        gridBack->Draw();

        for (int j = 0; j < 16; j++)
        {
            this->gGameGrid[j].Draw();
        }

        if (this->gGameGrid.Win() == true)
        {
            isWin = true;
            break;
        }

        this->gGameGrid.MergeFalse();

        this->Update();

    }
    if (isWin == false)
    {
        std::cout << "You loose";
    }
    else
    {
        std::cout << "You won !";
    }
};

void Window::CheckCases(int i, int j, int iDirectionX, int iDirectionY)
{
    int iNewIndex;
    int iTemp;
    if (this->gGameGrid.cGrid[this->gGameGrid.BiToMono(i, j)]->iValue != 0)
    {
        iNewIndex = this->gGameGrid.Move(i, j, i, j, iDirectionX, iDirectionY);
        iTemp = this->gGameGrid.BiToMono(i, j);
        SwapCases(iTemp, iNewIndex);
    }
};

void Window::SwapCases(int i, int j)
{
    Case* temp = this->gGameGrid.cGrid[i];
    this->gGameGrid.cGrid[i] = this->gGameGrid.cGrid[j];
    this->gGameGrid.cGrid[j] = temp;

    this->gGameGrid.cGrid[i]->UpdatePosition(i);
    this->gGameGrid.cGrid[i]->UpdateTexture();
    this->gGameGrid.cGrid[j]->UpdatePosition(j);
    this->gGameGrid.cGrid[j]->UpdateTexture();
};