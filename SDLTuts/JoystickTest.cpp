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
//const int THUMBSTICK_DEAD_ZONE = 8000;
//
////Global variables
//SDL_Window* gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
//SDL_Joystick* gController = nullptr;
//SDL_Haptic* gHaptic = nullptr;
//
//Game::Texture gArrowTexture;
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
//			//Current texture
//			int xDir = 0;
//			int yDir = 0;
//
//			//Main loop
//			while (!quit) {
//				//Poll for events/input
//				while (SDL_PollEvent(&event) != 0) {
//					if (event.type == SDL_QUIT) quit = true;
//					else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit = true;
//					else if (event.type == SDL_JOYAXISMOTION) {
//						if (event.jaxis.which == 0) {
//							if (event.jaxis.axis == 0) {
//								if (event.jaxis.value < -THUMBSTICK_DEAD_ZONE) xDir = -1;
//								else if (event.jaxis.value > THUMBSTICK_DEAD_ZONE) xDir = 1;
//								else xDir = 0;
//							}
//							else if (event.jaxis.axis == 1){
//								if (event.jaxis.value < -THUMBSTICK_DEAD_ZONE) yDir = 1;
//								else if (event.jaxis.value > THUMBSTICK_DEAD_ZONE) yDir = -1;
//								else yDir = 0;
//							}
//						}
//					}
//					else if (event.type == SDL_JOYBUTTONDOWN) {
//						SDL_HapticRumblePlay(gHaptic, 0.75, 500) != 0;
//					}
//				}
//
//
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//				SDL_RenderClear(gRenderer);
//
//
//				double angle = atan2((double)yDir, (double)xDir) * (180.0 - M_PI);
//				if (xDir == 0 && yDir == 0) angle = 0;
//
//				gArrowTexture.Render((SCREEN_WIDTH - gArrowTexture.GetWidth()) / 2, (SCREEN_HEIGHT - gArrowTexture.GetHeight()) / 2, nullptr, angle);
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
//	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC) < 0) {
//		printf("SDL could not init! SDL_Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else {
//		//Set texture filtering
//		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) printf("Warning: Linear texture filtering not enabled!\n");
//
//		//Check for joysticks
//		if (SDL_NumJoysticks() < 1) {
//			printf("Warning: No joysticks connected!\n");
//		}
//		else {
//			//Load joystick
//			gController = SDL_JoystickOpen(0);
//			if (!gController) printf("Warning: Unable to open controller! SDL Error: %s\n", SDL_GetError());
//			else {
//				gHaptic = SDL_HapticOpenFromJoystick(gController);
//				if (gHaptic) {
//					if (SDL_HapticRumbleInit(gHaptic) < 0) {
//						printf("Warning: Unable to initalize rumble! SDL Error: %s\n", SDL_GetError());
//					}
//				}
//				else {
//					printf("Warning: Controller doesn't support haptics! SDL Error: %s\n", SDL_GetError());
//				}
//			}
//		}
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
//	if (!gArrowTexture.LoadFromFile("arrow.png")) success = false;
//
//	return success;
//}
//
//void Close() {
//	//Deallocate memory
//	gArrowTexture.Free();
//
//	//Close game controller
//	SDL_HapticClose(gHaptic);
//	SDL_JoystickClose(gController);
//	gController = nullptr;
//	gHaptic = nullptr;
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