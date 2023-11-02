#pragma once

#include <vector>

class Case;
struct SDL_Texture;
struct SDL_Renderer;

class Grid
{
public:
    bool bIsFull;
    Case** cGrid;
    int iScore;

    Grid();

    int BiToMono(int x, int y);

    int* MonoToBi(int i);

    int Rnd(int n);

    void InitGrid(SDL_Texture** tArray, SDL_Renderer* Renderer);

    void DeleteGrid();

    int Move(int x, int y, int xBase, int yBase, int directionX, int directionY);

    std::vector<int> ListEmptyCases();

    void RandNumber();

    Case& operator[](int index);

    bool isFull();

    void MergeFalse();

    bool noPossibility();

    bool Win();

    int Rand2or4();
};
