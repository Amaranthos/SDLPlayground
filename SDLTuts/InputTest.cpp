//#include <stdio.h>
//#include <string>
//
//#include <SDL.h>
//#include <SDL_image.h>
//
//#include "Enums.h"
//
////Global constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
////Global variables
//SDL_Window* gWindow = nullptr;
//SDL_Surface* gScreenSurface = nullptr;
//SDL_Surface* gKeyPressSurfaces[Key_Press_Surface_Total];
//SDL_Surface* gCurrSurface = nullptr;
//
////Function declarations
//bool Init();									//Init sdl
//bool LoadMedia();								//Load in resources
//void Close();									//Free memory
//SDL_Surface* LoadSurface(std::string path);		//Loads an image
//
//int test(int argc, char* args[]) {
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
//			//Main loop
//			while (!quit) {
//				//Poll for events/input
//				while (SDL_PollEvent(&event) != 0) {
//					if (event.type == SDL_QUIT) {
//						quit = true;
//					}
//					//else if(event.type == SDL_KEYDOWN){
//					//	switch (event.key.keysym.sym) {
//					//		case SDLK_UP:
//					//			//gCurrSurface = gKeyPressSurfaces[Key_Press_Surface_Up];
//					//			break;
//
//					//		case SDLK_DOWN:
//					//			//gCurrSurface = gKeyPressSurfaces[Key_Press_Surface_Down];
//					//			break;
//
//					//		case SDLK_LEFT:
//					//			//gCurrSurface = gKeyPressSurfaces[Key_Press_Surface_Left];
//					//			break;
//
//					//		case SDLK_RIGHT:
//					//			//gCurrSurface = gKeyPressSurfaces[Key_Press_Surface_Right];
//					//			break;
//
//					//		case SDLK_ESCAPE:
//					//			quit = true;
//					//			break;
//
//					//		default:
//					//			//gCurrSurface = gKeyPressSurfaces[Key_Press_Surface_Default];
//					//			break;
//					//	}
//					//}
//				}
//
//				//Apply image
//				/*SDL_Rect stretchRect;
//				stretchRect.x = 0;
//				stretchRect.y = 0;
//				stretchRect.w = SCREEN_WIDTH;
//				stretchRect.h = SCREEN_HEIGHT;
//				SDL_BlitScaled(gCurrSurface, NULL, gScreenSurface, &stretchRect);*/
//
//				if (SDL_BlitSurface(gCurrSurface, NULL, gScreenSurface, NULL) == -1) {
//					printf("Couldn't blit\n");
//				}
//
//				//Update
//				SDL_UpdateWindowSurface(gWindow);
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
//			//Init PNG loading
//			int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
//			if (!(IMG_Init(imgFlags) & imgFlags)) {
//				printf("SDL_Image could not initialize! SDL_Image_ErrorL %s\n", IMG_GetError());
//			}
//			else {
//				//Get surface
//				gScreenSurface = SDL_GetWindowSurface(gWindow);
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
//	//Load PNG
//	gCurrSurface = LoadSurface("loaded.png");
//	if (gCurrSurface == nullptr) {
//		success = false;
//	}
//
//	////Load defualt image
//	//gKeyPressSurfaces[Key_Press_Surface_Default] = LoadSurface("press.bmp");
//	//if (gKeyPressSurfaces[Key_Press_Surface_Default] == nullptr) {
//	//	success = false;
//	//}
//
//	////Load up image
//	//gKeyPressSurfaces[Key_Press_Surface_Up] = LoadSurface("up.bmp");
//	//if (gKeyPressSurfaces[Key_Press_Surface_Up] == nullptr) {
//	//	success = false;
//	//}
//
//	////Load down image
//	//gKeyPressSurfaces[Key_Press_Surface_Down] = LoadSurface("down.bmp");
//	//if (gKeyPressSurfaces[Key_Press_Surface_Down] == nullptr) {
//	//	success = false;
//	//}
//
//	////Load left image
//	//gKeyPressSurfaces[Key_Press_Surface_Left] = LoadSurface("left.bmp");
//	//if (gKeyPressSurfaces[Key_Press_Surface_Left] == nullptr) {
//	//	success = false;
//	//}
//
//	////Load right image
//	//gKeyPressSurfaces[Key_Press_Surface_Right] = LoadSurface("right.bmp");
//	//if (gKeyPressSurfaces[Key_Press_Surface_Right] == nullptr) {
//	//	success = false;
//	//}
//
//	return success;
//}
//
//void Close() {
//	//Deallocate memory
//	for (int i = 0; i < Key_Press_Surface_Total; ++i) {
//		SDL_FreeSurface(gKeyPressSurfaces[i]);
//		gKeyPressSurfaces[i] = nullptr;
//	}
//
//	//Destroy window
//	SDL_DestroyWindow(gWindow);
//	gWindow = nullptr;
//
//	//Quit
//	SDL_Quit();
//}
//
//SDL_Surface* LoadSurface(std::string path){
//	SDL_Surface* optimised = nullptr;
//
//	//Load image at path
//	SDL_Surface* loadedImage = IMG_Load(path.c_str());
//
//	if (loadedImage == nullptr) {
//		printf("Unable to load image %s! SDL_Error: %s\n", path.c_str(), IMG_GetError());
//	}
//	else {
//		optimised = SDL_ConvertSurface(loadedImage, gScreenSurface->format, NULL);
//
//		if (optimised == nullptr) {
//			printf("Unable to optimize image %S! SDL_Error: %S\n", path.c_str(), SDL_GetError());
//		}
//		else {
//			printf("Loaded image %s!", path.c_str());
//		}
//
//		SDL_FreeSurface(loadedImage);
//	}
//	return optimised;
//}