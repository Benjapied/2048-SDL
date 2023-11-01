
#include <SDL.h>

class Window {
public:

	SDL_Window* window;
	SDL_Renderer* renderer;

	Window(const char* name, int width, int height);

	~Window();

	void Update();

	void Clear();

};