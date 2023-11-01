
#include <SDL.h>

class GameObject
{
public:

    SDL_Renderer* rRenderer;
    SDL_Texture* tTexture;
    SDL_Rect rRect;

    GameObject(SDL_Surface* Surface, SDL_Renderer* Renderer, int w, int h, int x=0, int y=0);

    ~GameObject();

    void SetPosition(int x, int y);

    void SetSize(int w, int h);

    void Draw();
    
    void SetTexture(SDL_Surface* Surface);
};
