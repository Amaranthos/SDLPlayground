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
//#include "Button.h"
//
////Global constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//const int TOTAL_BUTTONS = 4;
//
////Global variables
//SDL_Window* gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
//Game::Texture gTexture;
//Game::Texture gButtonTexture;
//SDL_Rect gButtonClip[Total];
//TTF_Font* gFont = nullptr;
//Game::Button gButtons[TOTAL_BUTTONS];
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
//						switch (event.key.keysym.sym){
//						case SDLK_ESCAPE:
//							quit = true;
//							break;
//						default:
//							break;
//						}
//					}
//
//					for (int i = 0; i < TOTAL_BUTTONS; ++i) {
//						gButtons[i].HandleEvent(&event);
//					}
//				}
//
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//				SDL_RenderClear(gRenderer);
//
//				for (int i = 0; i < TOTAL_BUTTONS; ++i){
//					gButtons[i].Render();
//				}
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
//	if (gButtonTexture.LoadFromFile("button.png")) {
//		for (int i = 0; i < LeftButtonSprite::Total; ++i) {
//			gButtonClip[i].x = 0;
//			gButtonClip[i].y = i * 200;
//			gButtonClip[i].w = Game::Button::WIDTH;
//			gButtonClip[i].h = Game::Button::HEIGHT;
//		}
//	}
//
//	gButtons[0].SetPosition(0, 0);
//	gButtons[1].SetPosition(SCREEN_WIDTH - Game::Button::WIDTH, 0);
//	gButtons[2].SetPosition(0, SCREEN_HEIGHT - Game::Button::HEIGHT);
//	gButtons[3].SetPosition(SCREEN_WIDTH - Game::Button::WIDTH, SCREEN_HEIGHT - Game::Button::HEIGHT);
//
//	return success;
//}
//
//void Close() {
//	//Deallocate memory
//	gTexture.Free();
//	gButtonTexture.Free();
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