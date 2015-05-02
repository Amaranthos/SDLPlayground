//#include <stdio.h>
//#include <string>
//#include <cmath>
//#include <sstream>
//
//#include <SDL.h>
//#include <SDL_image.h>
//
//#include "Enums.h"
//#include "Texture.h"
//#include "Timer.h"
//#include "Dot.h"
//
////Global constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
////Global variables
//SDL_Window* gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
//Dot dot = { 10, 10 };
//Dot dot2 = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4 };
//
////Function declarations
//bool Init();									//Init sdl
//bool LoadMedia();								//Load in resources
//void Close();									//Free memory
//bool CheckCollision(Circle& a, Circle& b);
//bool CheckCollision(Circle& a, SDL_Rect& b);
//double DistanceSquared(int x1, int y1, int x2, int y2);
//
//struct  Circle {
//	int x, y;
//	int r;
//};
//
//class Dot
//{
//public:
//	Dot(int x, int y);
//	~Dot();
//	static const int DOT_WDITH = 20;
//	static const int DOT_HEIGHT = 20;
//	static const int DOT_VEL = 1;
//
//	void HandleEvent(SDL_Event& event);
//	void Move(SDL_Rect& square, Circle& circle);
//	void Render();
//
//	Circle& GetColliders() { return collider; }
//
//	Game::Texture* sprite;
//
//private:
//	void ShiftColliders();
//
//	int posX, posY;
//	int velX, velY;
//	Circle collider;
//};
//
//Dot::Dot(int x, int y) : posX(x), posY(y), velX(0), velY(0) {
//	sprite = new Game::Texture;
//	collider.r = DOT_WDITH / 2;
//
//	ShiftColliders();
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
//void Dot::Move(SDL_Rect& square, Circle& circle) {
//	posX += velX;
//	ShiftColliders();
//
//	if ((posX - collider.r < 0) || (posX + collider.r > SCREEN_WIDTH) || CheckCollision(collider, square) || CheckCollision(collider, circle)) {
//		posX -= velX;
//		ShiftColliders();
//	}
//
//	posY += velY;
//	ShiftColliders();
//
//	if ((posY - collider.r < 0) || (posY + collider.r > SCREEN_HEIGHT) || CheckCollision(collider, square) || CheckCollision(collider, circle)) {
//		posY -= velY;
//		ShiftColliders();
//	}
//}
//
//void Dot::Render(){
//	sprite->Render(posX - collider.r, posY - collider.r);
//}
//
//void Dot::ShiftColliders() {
//	collider.x = posX;
//	collider.y = posY;
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
//
//			SDL_Rect wall;
//			wall.x = 300;
//			wall.y = 40;
//			wall.w = 40;
//			wall.h = 400;
//
//			//Main loop
//			while (!quit) {
//				//Poll for events/input
//				while (SDL_PollEvent(&event) != 0) {
//					if (event.type == SDL_QUIT) quit = true;
//					else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit = true;
//
//					dot.HandleEvent(event);
//				}
//
//				dot.Move(wall, dot2.GetColliders());
//
//				//Clear screen
//				SDL_SetRenderDrawColor(gRenderer, 125, 255, 255, 255);
//				SDL_RenderClear(gRenderer);
//
//				//Draw
//				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
//				SDL_RenderDrawRect(gRenderer, &wall);
//				dot.Render();
//				dot2.Render();
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
//	dot.sprite->LoadFromFile("dot.png");
//	dot2.sprite->LoadFromFile("dot.png");
//
//	return success;
//}
//
//void Close() {
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