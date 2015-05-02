//#include <stdio.h>
//#include <string>
//#include <cmath>
//#include <sstream>
//#include <iostream>
//
//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
//
//#include "Enums.h"
//#include "Texture.h"
//#include "Timer.h"
//
////Global constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//const int LEVEL_WIDTH = 1280;
//const int LEVEL_HEIGHT = 960;
//
////Global variables
//SDL_Window* gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
//Game::Texture background;
//
//TTF_Font* gFont = nullptr;
//
////Function declarations
//bool Init();									//Init sdl
//bool LoadMedia();								//Load in resources
//void Close();									//Free memory
//
//#ifdef CIRCLE_H
//bool CheckCollision(Circle& a, Circle& b);
//bool CheckCollision(Circle& a, SDL_Rect& b);
//double DistanceSquared(int x1, int y1, int x2, int y2);
//#endif
//
//class Dot
//{
//public:
//	Dot();
//	~Dot();
//	static const int DOT_WDITH = 20;
//	static const int DOT_HEIGHT = 20;
//	static const int DOT_VEL = 10;
//
//	void HandleEvent(SDL_Event& event);
//	void Move();
//	void Render();
//
//	int GetPosX() { return posX; }
//	int GetPosY() { return posY; }
//
//	Game::Texture* sprite;
//
//private:
//	int posX, posY;
//	int velX, velY;
//};
//
//Dot::Dot() : posX(0), posY(0), velX(0), velY(0) {
//	sprite = new Game::Texture;
//}
//
//Dot::~Dot(){
//	sprite->Free();
//	sprite = nullptr;
//}
//
//void Dot::HandleEvent(SDL_Event& event) {
//	if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
//		switch (event.key.keysym.sym) {
//		case SDLK_UP:
//			velY -= DOT_VEL;
//			break;
//
//		case SDLK_DOWN:
//			velY += DOT_VEL;
//			break;
//
//		case SDLK_LEFT:
//			velX -= DOT_VEL;
//			break;
//
//		case SDLK_RIGHT:
//			velX += DOT_VEL;
//			break;
//		}
//	}
//	else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
//		switch (event.key.keysym.sym) {
//		case SDLK_UP:
//			velY += DOT_VEL;
//			break;
//
//		case SDLK_DOWN:
//			velY -= DOT_VEL;
//			break;
//
//		case SDLK_LEFT:
//			velX += DOT_VEL;
//			break;
//
//		case SDLK_RIGHT:
//			velX -= DOT_VEL;
//			break;
//		}
//	}
//}
//
//void Dot::Move() {
//	posX += velX;
//
//	if ((posX  < 0) || (posX + DOT_WDITH > LEVEL_WIDTH)) {
//		posX -= velX;
//	}
//
//	posY += velY;
//
//	if ((posY < 0) || (posY + DOT_HEIGHT > LEVEL_HEIGHT)) {
//		posY -= velY;
//	}
//}
//
//void Dot::Render(){
//	sprite->Render(posX, posY);
//}
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
//			SDL_Color textColour = { 0, 0, 0, 255 };
//
//			std::string inputText = "Some Text";
//
//			background.LoadFromRenderedText(inputText.c_str(), textColour);
//
//			SDL_StartTextInput();
//
//			//Main loop
//			while (!quit) {
//				bool renderText = false;
//
//				//Poll for events/input
//				while (SDL_PollEvent(&event) != 0) {
//					if (event.type == SDL_QUIT) quit = true;
//					else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit = true;
//					else if (event.type == SDL_KEYDOWN) {
//						if (event.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0) {
//							inputText.pop_back();
//							renderText = true;;
//						}
//						else if (event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL) SDL_SetClipboardText(inputText.c_str());
//						else if (event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL){
//							inputText += SDL_GetClipboardText();
//							renderText = true;
//						}
//					}
//					else
//					{
//						if (event.type == SDL_TEXTINPUT) {
//							if (!((event.text.text[0] == 'c' || event.text.text[0] == 'C') && (event.text.text[0] == 'v' || event.text.text[0] == 'V') && SDL_GetModState() & KMOD_CTRL)) {
//								inputText += event.text.text;
//								renderText = true;
//							}
//						}
//					}
//
//					if (renderText) {
//						if (inputText != "") background.LoadFromRenderedText(inputText.c_str(), textColour);
//						else background.LoadFromRenderedText(" ", textColour);
//					}
//				}
//
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//				SDL_RenderClear(gRenderer);
//
//				//Draw
//				background.Render((SCREEN_HEIGHT - background.GetWidth()) / 2, background.GetHeight());
//
//				//Update screen
//				SDL_RenderPresent(gRenderer);
//			}
//			SDL_StopTextInput();
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
//				//Init SDL_TT
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
//	gFont = TTF_OpenFont("lazy.ttf", 28);
//
//	if (!gFont) {
//		success = false;
//		printf("Error %s", TTF_GetError());
//	}
//	//if (!background.LoadFromFile("bg.png")) success = false;
//
//	return success;
//}
//
//void Close() {
//
//	background.Free();
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
//#ifdef CIRCLE_H
//bool CheckCollision(Circle& a, Circle& b) {
//
//	int totalRSquared = a.r + b.r;
//	totalRSquared *= totalRSquared;
//
//	if (DistanceSquared(a.x, a.y, b.x, b.y) < (totalRSquared)) return true;
//
//	return false;
//}
//
//bool CheckCollision(Circle& a, SDL_Rect& b) {
//	int cX, cY;
//
//	if (a.x < b.x) cX = b.x;
//	else if (a.x > b.x + b.w) cX = b.x + b.w;
//	else cX = a.x;
//
//	if (a.y < b.y) cY = b.y;
//	else if (a.y > b.y + b.h) cY = b.y + b.h;
//	else cY = a.y;
//
//	if (DistanceSquared(a.x, a.y, cX, cY) < a.r * a.r) return true;
//
//	return false;
//}
//
//double DistanceSquared(int x1, int y1, int x2, int y2){
//	int deltaX = x2 - x1;
//	int deltaY = y2 - y1;
//
//	return deltaX*deltaX + deltaY * deltaY;
//}
//#endif