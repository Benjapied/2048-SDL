
#include "Window.h"
#include "GameObject.h"
#include "Test.h"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


// You shouldn't really use this statement, but it's fine for small programs
using namespace std;

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) 
{

    //-------------------
    //Initialisation SDL
    //-------------------
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Surface* lantern0 = SDL_LoadBMP("img/lantern0.bmp");
    SDL_Surface* lantern2 = SDL_LoadBMP("img/lantern2.bmp");
    SDL_Surface* lantern4 = SDL_LoadBMP("img/lantern4.bmp");
    SDL_Surface* lantern8 = SDL_LoadBMP("img/lantern8.bmp");
    SDL_Surface* lantern16 = SDL_LoadBMP("img/lantern16.bmp");
    SDL_Surface* lantern32 = SDL_LoadBMP("img/lantern32.bmp");
    SDL_Surface* lantern64 = SDL_LoadBMP("img/lantern64.bmp");
    SDL_Surface* lantern128 = SDL_LoadBMP("img/lantern128.bmp");
    SDL_Surface* lantern256 = SDL_LoadBMP("img/lantern256.bmp");
    SDL_Surface* lantern512 = SDL_LoadBMP("img/lantern512.bmp");
    SDL_Surface* lantern1024 = SDL_LoadBMP("img/lantern1024.bmp");
    SDL_Surface* lantern2048 = SDL_LoadBMP("img/lantern2048.bmp");

    SDL_Surface* surfaceGrid[12] = { lantern0, lantern2, lantern4, lantern8, lantern16, lantern32, lantern64, lantern128, lantern256, lantern512, lantern1024, lantern2048 };

    const char* title = "2048";
    Window window(title, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Surface* lose = SDL_LoadBMP("img/lose.bmp");
    SDL_Texture* tLose = SDL_CreateTextureFromSurface(window.renderer, lose);
    GameObject loseBackground(tLose, window.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Surface* win = SDL_LoadBMP("img/win.bmp");
    SDL_Texture* tWin = SDL_CreateTextureFromSurface(window.renderer, win);
    GameObject winBackground(tWin, window.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    TTF_Font* font = TTF_OpenFont("font/851CHIKARA-DZUYOKU_kanaA_004.ttf", 512);

    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, u8"敗北した", { 255, 0, 0 });
    SDL_Texture* tTextSurface = SDL_CreateTextureFromSurface(window.renderer, textSurface);
    GameObject loseTexture(tTextSurface, window.renderer, 400, 200, 730, 290);
    SDL_FreeSurface(textSurface);

    SDL_Surface* winText = TTF_RenderUTF8_Solid(font, u8"頂点に達した", { 255, 255, 255 });
    SDL_Texture* tWinTextSurface = SDL_CreateTextureFromSurface(window.renderer, winText);
    GameObject winTexture(tWinTextSurface, window.renderer, 500, 300, 700, 390);
    SDL_FreeSurface(winText);

    GameObject* FinishArray[4] = { &loseBackground, &winBackground, &loseTexture, &winTexture };
    
    SDL_Texture* textureGrid[12];
    for (int i = 0; i < 12; i++) {
        textureGrid[i] = SDL_CreateTextureFromSurface(window.renderer, surfaceGrid[i]);
    }

    //Destroying SurfaceGrid and each elements
    for (int j = 0; j < 12; j++) {
        SDL_FreeSurface(surfaceGrid[j]);
    }

    window.WindowGridInit(textureGrid);

    SDL_Surface* gridBackground = IMG_Load("img/grid-background.png");
    SDL_Texture* tgridBackground = SDL_CreateTextureFromSurface(window.renderer, gridBackground);
    GameObject gridBack(tgridBackground, window.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_FreeSurface(gridBackground);

    SDL_Surface* bg = SDL_LoadBMP("img/background.bmp");
    SDL_Texture* tBg = SDL_CreateTextureFromSurface(window.renderer, bg);
    GameObject background(tBg, window.renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_FreeSurface(bg);

    

    //----------
    //Game Loop
    //----------
    
    //Test test(textureGrid, window.renderer);

    window.GameLoop(&background, &gridBack, FinishArray);

    //Destroying TextureGrid and each elements
    for (int j = 0; j < 12; j++) {
        SDL_DestroyTexture(textureGrid[j]);
    }

    return 0;
}
