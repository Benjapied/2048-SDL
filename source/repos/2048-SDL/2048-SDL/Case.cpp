#include "Case.h"
#include <cmath>

Case::Case(SDL_Texture** tArray, SDL_Texture* pTexture, SDL_Renderer* Renderer, int w, int h, int x/* = 0*/, int y /*= 0*/) : GameObject(pTexture, Renderer, w, h, x, y)
{
    this->iValue = 0;
    this->bMergable = false;
    this->tArray = tArray;
}

void Case::UpdateTexture()
{
    //Faire la valeur de l'indice via le ln
    if (this->iValue == 0) {
        this->tTexture = this->tArray[0];
        return;
    }
    
    int iLogValue = log2(this->iValue);
    this->tTexture = this->tArray[iLogValue];
    return;
    
    
    
}
