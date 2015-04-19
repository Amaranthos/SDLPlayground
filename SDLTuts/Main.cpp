#include <SDL.h>
#include <stdio.h>

//Global constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Global variables
SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gLoadedImage = nullptr;

//Function declarations
bool Init();				//Init sdl
bool LoadMedia();			//Load in resources
void Close();				//Free memory

int main(int argc, char* args[]) {
	//Init
	if (!Init()) {
		printf("Failed to Init!\n");
	}
	else {
		//Load image
		if (!LoadMedia()) {
			printf("Failed to load media!\n");
		}
		else {
			//Apply image
			SDL_BlitSurface(gLoadedImage, nullptr, gScreenSurface, nullptr);

			//Update
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(2000);
		}
	}

	//Clean up
	Close();

	return 0;
}

bool Init() {
	//Init flag
	bool success = true;

	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not init! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		//Create the window
		gWindow = SDL_CreateWindow("SDL Playground", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == nullptr) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Get surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool LoadMedia() {
	//Loading flag
	bool success = true;

	//Load image
	gLoadedImage = SDL_LoadBMP("helloWorld.bmp");

	if (gLoadedImage == nullptr) {
		printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Close() {
	//Deallocate memory
	SDL_FreeSurface(gLoadedImage);
	gLoadedImage = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	//Quit
	SDL_Quit();
}