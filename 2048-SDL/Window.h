#pragma once

#include "Grid.h"

class GameObject;
struct SDL_Window;
struct SDL_Renderer;

class Window {
public:

	SDL_Window* window;
	SDL_Renderer* renderer;
	int iPoints;
	Grid gGameGrid;


	Window(const char* name, int width, int height);

	~Window();

	void WindowGridInit(SDL_Texture** tArray);

	void Update();

	void Clear();

	void GameLoop(GameObject* background, GameObject* gridBack, GameObject** finishArray);

	void CheckCases(int i, int j, int iDirectionX, int iDirectionY);

	void SwapCases(int i, int j);

};