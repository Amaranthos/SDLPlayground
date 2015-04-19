#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	//Window
	SDL_Window* window = nullptr;

	//Surface contained by the window
	SDL_Surface* screenSurface = nullptr;

	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not init! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		//Create the window
		window = SDL_CreateWindow("SDL Playground", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == nullptr) {

		}
	}
}