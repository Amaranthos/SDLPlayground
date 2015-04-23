//#include <stdio.h>
//#include <string>
//#include <cmath>
//
//#include <SDL.h>
//#include <SDL_image.h>
//
//#include "Enums.h"
//#include "LTexture.h"
//
////Global constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//const int WALKING_ANIMATION_FRAMES = 4;
//
////Global variables
//SDL_Window* gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
//LTexture gTexture;
//SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];
//
//
////Function declarations
//bool Init();									//Init sdl
//bool LoadMedia();								//Load in resources
//void Close();									//Free memory
//SDL_Texture* LoadTexture(std::string path);		//Loads an image
//
//int main(int argc, char* args[]) {
//	//Init
//	if (!Init()) {
//		printf("Failed to Init!\n");
//	}
//	else {
//		//Load image
//		if (!LoadMedia()) {
//			printf("Failed to load media!\n");
//		}
//		else {
//			//Main loop flag
//			bool quit = false;
//
//			//Event handler
//			SDL_Event event;
//
//			//Animation
//			int frame = 0;
//
//
//			//Main loop
//			while (!quit) {
//				//Poll for events/input
//				while (SDL_PollEvent(&event) != 0) {
//					if (event.type == SDL_QUIT) {
//						quit = true;
//					}
//					else if (event.type == SDL_KEYDOWN){
//						if (event.key.keysym.sym == SDLK_ESCAPE){
//							quit = true;
//						}
//					}
//				}
//
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//				SDL_RenderClear(gRenderer);
//
//				SDL_Rect* current = &gSpriteClips[frame / 4];
//				gTexture.Render((SCREEN_WIDTH - current->w) / 2, (SCREEN_HEIGHT - current->h) / 2, current);
//
//				//Update screen
//				SDL_RenderPresent(gRenderer);
//
//				++frame;
//
//				if (frame / 4 >= WALKING_ANIMATION_FRAMES) frame = 0;
//			}
//		}
//	}
//
//	//Clean up
//	Close();
//
//	return 0;
//}
//
//bool Init() {
//	//Init flag
//	bool success = true;
//
//	//Init SDL
//	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//		printf("SDL could not init! SDL_Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else {
//		//Create the window
//		gWindow = SDL_CreateWindow("SDL Playground", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//
//		if (gWindow == nullptr) {
//			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
//			success = false;
//		}
//		else {
//			//Create a renderer
//			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//
//			if (gRenderer == nullptr){
//				printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
//				success = false;
//			}
//			else {
//				//Init renderer colour
//				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//				//Init PNG loading
//				int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
//				if (!(IMG_Init(imgFlags) & imgFlags)) {
//					printf("SDL_Image could not initialize! SDL_Image_ErrorL %s\n", IMG_GetError());
//					success = false;
//				}
//			}
//		}
//	}
//	return success;
//}
//
//bool LoadMedia() {
//	//Loading flag
//	bool success = true;
//
//	if (gTexture.LoadFromFile("foo.png")) {
//		gSpriteClips[0].x = 0;
//		gSpriteClips[0].y = 0;
//		gSpriteClips[0].w = 64;
//		gSpriteClips[0].h = 205;
//
//		gSpriteClips[1].x = 64;
//		gSpriteClips[1].y = 0;
//		gSpriteClips[1].w = 64;
//		gSpriteClips[1].h = 205;
//
//		gSpriteClips[2].x = 128;
//		gSpriteClips[2].y = 0;
//		gSpriteClips[2].w = 64;
//		gSpriteClips[2].h = 205;
//
//		gSpriteClips[3].x = 196;
//		gSpriteClips[3].y = 0;
//		gSpriteClips[3].w = 64;
//		gSpriteClips[3].h = 205;
//	}
//	else {
//		success = false;
//	}
//
//
//
//	return success;
//}
//
//void Close() {
//	//Deallocate memory
//	gTexture.Free();
//
//
//	//Destroy window
//	SDL_DestroyRenderer(gRenderer);
//	SDL_DestroyWindow(gWindow);
//	gWindow = nullptr;
//	gRenderer = nullptr;
//
//	//Quit
//	IMG_Quit();
//	SDL_Quit();
//}
//
//SDL_Texture* LoadTexture(std::string path){
//	SDL_Texture* newTexture = nullptr;
//
//	//Load image at path
//	SDL_Surface* loadedImage = IMG_Load(path.c_str());
//
//	if (loadedImage == nullptr) {
//		printf("Unable to load image %s! SDL_Error: %s\n", path.c_str(), IMG_GetError());
//	}
//	else {
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedImage);
//
//		if (newTexture == nullptr) {
//			printf("Unable to create texture from %S! SDL_Error: %S\n", path.c_str(), SDL_GetError());
//		}
//
//		SDL_FreeSurface(loadedImage);
//	}
//	return newTexture;
//}