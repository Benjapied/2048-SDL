#include "GameObject.h"
#include <SDL.h>
#include <iostream>

GameObject::GameObject(SDL_Surface* Surface, SDL_Renderer* Renderer, int w, int h, int x, int y)
{
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(Renderer, Surface);
    if (pTexture == NULL)
    {
        std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
        exit(1);
    }

    SDL_Rect rRect;
    rRect.x = x;
    rRect.y = y;
    rRect.w = w;
    rRect.h = h;

    this->rRenderer = Renderer;
    this->tTexture = pTexture;
    this->rRect = rRect;
}

GameObject::~GameObject() {
    SDL_DestroyTexture(this->tTexture);
}

void GameObject::SetPosition(int x, int y)
{
    this->rRect.x = x;
    this->rRect.y = y;
}

void GameObject::SetSize(int w, int h) 
{
    this->rRect.w = w;
    this->rRect.h = h;
}

void GameObject::Draw()
{
    SDL_RenderCopy(this->rRenderer, this->tTexture, NULL, &rRect);
}

void GameObject::SetTexture(SDL_Surface* Surface)
{
    this->tTexture = SDL_CreateTextureFromSurface(this->rRenderer, Surface);
}

