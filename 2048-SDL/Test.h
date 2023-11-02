#pragma once

#include "Grid.h"

class Test
{
public:
	Grid gTestGrid, gEndGrid;

	Test(SDL_Texture** tArray, SDL_Renderer* Renderer);

	bool CheckGrid();

	void LunchTests();

	void IntegrationTest1();

	void IntegrationTest2();

	void IntegrationTest3();

	void IntegrationTest4();

	void IntegrationTest5();
};

