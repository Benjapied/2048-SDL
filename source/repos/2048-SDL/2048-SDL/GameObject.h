#pragma once

#include <SDL_Rect.h>

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Surface;

class GameObject
{
public:

    SDL_Renderer* rRenderer;
    SDL_Texture* tTexture;
    SDL_Rect rRect;

    GameObject(SDL_Texture* pTexture, SDL_Renderer* Renderer, int w, int h, int x = 0, int y = 0);

    ~GameObject();

    void SetPosition(int x, int y);

    void SetSize(int w, int h);

    void Draw();

    void SetTexture(SDL_Surface* Surface);

    void UpdatePosition(int i);
};
