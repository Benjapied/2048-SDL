#pragma once

#include "GameObject.h"

struct SDL_Texture;
struct SDL_Renderer;

class Case : public GameObject
{
public:
    int iValue;
    bool bMergable;
    SDL_Texture** tArray;

    Case(SDL_Texture** tArray, SDL_Texture* pTexture, SDL_Renderer* Renderer, int w, int h, int x = 0, int y = 0);
    
    void UpdateTexture();
};
