//#include <stdio.h>
//#include <string>
//#include <cmath>
//#include <sstream>
//#include <iostream>
//
//#include <SDL.h>
//#include <SDL_image.h>
////#include <SDL_ttf.h>
//
//#include "Texture.h"
//#include "Window.h"
//
////Global constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//const int LEVEL_WIDTH = 1280;
//const int LEVEL_HEIGHT = 960;
//const int TOTAL_PARTICLES = 20;
//
////Global variables
//Game::Window window;
//Game::Texture red;
//Game::Texture green;
//Game::Texture blue;
//Game::Texture shimmer;
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
//class Particle {
//public:
//	Particle(int x, int y);
//	~Particle();
//
//	void Render(SDL_Renderer* renderer);
//
//	bool IsDead() { return frame > 10; }
//
//private:
//	int posX, posY;
//	int frame;
//	Game::Texture* texture;
//};
//
//Particle::Particle(int x, int y) {
//	posX = x - 5 + (rand() % 25);
//	posY = y - 5 + (rand() % 25);
//
//	frame = rand() % 5;
//
//	switch (rand() % 3) {
//	case 0:texture = &red; break;
//	case 1:texture = &green; break;
//	case 2:texture = &blue; break;
//	}
//}
//
//Particle::~Particle() {
//
//}
//
//void Particle::Render(SDL_Renderer* renderer) {
//	texture->Render(posX, posY, renderer);
//
//	if (frame % 2 == 0) shimmer.Render(posX, posY, renderer);
//
//	frame++;
//}
//
//class Dot {
//public:
//	Dot();
//	~Dot();
//	static const int DOT_WIDTH = 20;
//	static const int DOT_HEIGHT = 20;
//	static const int DOT_VEL = 10;
//
//	void HandleEvent(SDL_Event& event);
//	void Move();
//	void Render(SDL_Renderer* renderer);
//
//	int GetPosX() { return posX; }
//	int GetPosY() { return posY; }
//
//	Game::Texture* sprite;
//
//private:
//	Particle* particles[TOTAL_PARTICLES];
//
//	void RenderParticles(SDL_Renderer* renderer);
//
//	int posX, posY;
//	int velX, velY;
//};
//
//Dot::Dot() : posX(50), posY(50), velX(0), velY(0) {
//	sprite = new Game::Texture;
//	sprite->LoadFromFile("dot.png", window.GetRenderer());
//	for (int i = 0; i < TOTAL_PARTICLES; ++i) particles[i] = new Particle(posX, posY);
//}
//
//Dot::~Dot(){
//	sprite->Free();
//	sprite = nullptr;
//	for (int i = 0; i < TOTAL_PARTICLES; ++i) delete particles[i];
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
//	if ((posX  < 0) || (posX + DOT_WIDTH > LEVEL_WIDTH)) {
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
//void Dot::Render(SDL_Renderer* renderer){
//	sprite->Render(posX, posY, renderer);
//
//	RenderParticles(renderer);
//}
//
//void Dot::RenderParticles(SDL_Renderer* renderer) {
//	for (int i = 0; i < TOTAL_PARTICLES; ++i) {
//		if (particles[i]->IsDead()) {
//			delete particles[i];
//			particles[i] = new Particle(posX, posY);
//		}
//	}
//
//	for (int i = 0; i < TOTAL_PARTICLES; ++i) particles[i]->Render(renderer);
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
//
//			//Main loop flag
//			bool quit = false;
//
//			//Event handler
//			SDL_Event event;
//
//			Dot dot;
//
//			//Main loop
//			while (!quit) {
//
//				//Poll for events/input
//				while (SDL_PollEvent(&event) != 0) {
//					if (event.type == SDL_QUIT) quit = true;
//					else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit = true;
//					window.HandleEvent(event);
//					dot.HandleEvent(event);
//				}
//
//				dot.Move();
//
//
//				window.Clear();
//
//				dot.Render(window.GetRenderer());
//
//				window.Render();
//			}
//		}
//	}
//
//	//Clean up
//	Close();
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
//		if (!window.Init(640, 480))	success = false;
//		else {
//			//Init PNG loading
//			int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
//			if (!(IMG_Init(imgFlags) & imgFlags)) {
//				printf("SDL_Image could not initialize! SDL_Image_ErrorL %s\n", IMG_GetError());
//				success = false;
//			}
//
//			//Init SDL_TT
//			/*if (TTF_Init() == -1) {
//			printf("SDL_TTF could not initalize! SDL_TTF Error: %s\n", TTF_GetError());
//			success = false;
//			}*/
//		}
//	}
//	return success;
//}
//
//bool LoadMedia() {
//	//Loading flag
//	bool success = true;
//
//	if (!red.LoadFromFile("red.png", window.GetRenderer())) success = false;
//	if (!green.LoadFromFile("green.png", window.GetRenderer())) success = false;
//	if (!blue.LoadFromFile("blue.png", window.GetRenderer())) success = false;
//	if (!shimmer.LoadFromFile("shimmer.png", window.GetRenderer())) success = false;
//
//	red.SetAlpha(192);
//	green.SetAlpha(192);
//	blue.SetAlpha(192);
//	shimmer.SetAlpha(192);
//
//	return success;
//}
//
//void Close() {
//
//	//Destroy window
//	window.Free();
//
//	red.Free();
//	green.Free();
//	blue.Free();
//	shimmer.Free();
//
//	//Quit
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