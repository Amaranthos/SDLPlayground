//#include <stdio.h>
//#include <string>
//#include <cmath>
//
//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
//
//#include "Enums.h"
//#include "Texture.h"
//
////Global constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//const int WALKING_ANIMATION_FRAMES = 4;
//
////Global variables
//SDL_Window* gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
//Game::Texture gTexture;
//TTF_Font* gFont = nullptr;
//
//
////Function declarations
//bool Init();									//Init sdl
//bool LoadMedia();								//Load in resources
//void Close();									//Free memory
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
//						switch (event.key.keysym.sym){
//						case SDLK_ESCAPE:
//							quit = true;
//							break;
//
//
//
//						default:
//							break;
//						}
//					}
//				}
//
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//				SDL_RenderClear(gRenderer);
//
//				gTexture.Render((SCREEN_WIDTH - gTexture.GetWidth()) / 2, (SCREEN_HEIGHT - gTexture.GetHeight()) / 2);
//
//				//Update screen
//				SDL_RenderPresent(gRenderer);
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
//
//				//Init PNG loading
//				int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
//				if (!(IMG_Init(imgFlags) & imgFlags)) {
//					printf("SDL_Image could not initialize! SDL_Image_ErrorL %s\n", IMG_GetError());
//					success = false;
//				}
//				//Init SDL_TTF
//				if (TTF_Init() == -1) {
//					printf("SDL_TTF could not initalize! SDL_TTF Error: %s\n", TTF_GetError());
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
//
//	gFont = TTF_OpenFont("lazy.ttf", 28);
//	if (gFont) {
//		SDL_Color textColor = { 0, 0, 0 };
//		if (!gTexture.LoadFromRenderedText("The quick brown fox jumped of the lazy dog", textColor)) success = false;
//	}
//	else success = false;
//
//	return success;
//}
//
//void Close() {
//	//Deallocate memory
//	gTexture.Free();
//
//	TTF_CloseFont(gFont);
//	gFont = nullptr;
//
//	//Destroy window
//	SDL_DestroyRenderer(gRenderer);
//	SDL_DestroyWindow(gWindow);
//	gWindow = nullptr;
//	gRenderer = nullptr;
//
//	//Quit
//	TTF_Quit();
//	IMG_Quit();
//	SDL_Quit();
//}