//#include <stdio.h>
//#include <string>
//#include <cmath>
//
//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_mixer.h>
//
//#include "Enums.h"
//#include "Texture.h"
//
////Global constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//const int THUMBSTICK_DEAD_ZONE = 8000;
//
////Global variables
//SDL_Window* gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
//
//Mix_Music* gMusic = nullptr;
//
//Mix_Chunk* gScratch = nullptr;
//Mix_Chunk* gHigh = nullptr;
//Mix_Chunk* gMedium = nullptr;
//Mix_Chunk* gLow = nullptr;
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
//		//Load
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
//			//Main loop
//			while (!quit) {
//				//Poll for events/input
//				while (SDL_PollEvent(&event) != 0) {
//					if (event.type == SDL_QUIT) quit = true;
//					else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit = true;
//					else if (event.type == SDL_KEYDOWN) {
//						switch (event.key.keysym.sym) {
//						case SDLK_1:
//							Mix_PlayChannel(-1, gHigh, 0);
//							break;
//
//						case SDLK_2:
//							Mix_PlayChannel(-1, gMedium, 0);
//							break;
//
//						case SDLK_3:
//							Mix_PlayChannel(-1, gLow, 0);
//							break;
//
//						case SDLK_4:
//							Mix_PlayChannel(-1, gScratch, 0);
//							break;
//
//						case SDLK_9:
//							if (Mix_PlayingMusic() == 0) Mix_PlayMusic(gMusic, -1);
//							else {
//								if (Mix_PausedMusic() == 1) Mix_ResumeMusic();
//								else{ Mix_PauseMusic(); }
//							}
//							break;
//
//						case SDLK_0:
//							Mix_HaltMusic();
//							break;
//						}
//					}
//				}
//
//
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//				SDL_RenderClear(gRenderer);
//
//
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
//	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
//		printf("SDL could not init! SDL_Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else {
//		//Set texture filtering
//		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) printf("Warning: Linear texture filtering not enabled!\n");
//
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
//
//				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
//					printf("Warning: SDL_mixer could not init! SDL_mixer Error: %s\n", Mix_GetError());
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
//	gMusic = Mix_LoadMUS("beat.wav");
//	if (!gMusic) success = false;
//
//	gScratch = Mix_LoadWAV("scratch.wav");
//	if (!gScratch) success = false;
//
//	gLow = Mix_LoadWAV("low.wav");
//	if (!gLow) success = false;
//
//	gMedium = Mix_LoadWAV("medium.wav");
//	if (!gMedium) success = false;
//
//	gHigh = Mix_LoadWAV("high.wav");
//	if (!gHigh) success = false;
//
//	return success;
//}
//
//void Close() {
//	//Deallocate memory
//	Mix_FreeChunk(gScratch);
//	Mix_FreeChunk(gLow);
//	Mix_FreeChunk(gMedium);
//	Mix_FreeChunk(gHigh);
//	Mix_FreeMusic(gMusic);
//
//	gLow = nullptr;
//	gMedium = nullptr;
//	gHigh = nullptr;
//	gScratch = nullptr;
//	gMusic = nullptr;
//
//	//Destroy window
//	SDL_DestroyRenderer(gRenderer);
//	SDL_DestroyWindow(gWindow);
//	gWindow = nullptr;
//	gRenderer = nullptr;
//
//	//Quit
//	Mix_Quit();
//	IMG_Quit();
//	SDL_Quit();
//}