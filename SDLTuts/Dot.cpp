#include "Dot.h"

Dot::Dot() : velX(0), velY(0) {
	sprite = new Game::Texture;
	sprite->LoadFromFile("dot.png", window.GetRenderer());
}

Dot::~Dot(){
	sprite->Free();
	sprite = nullptr;
}

void Dot::HandleEvent(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			velY -= DOT_VEL;
			break;

		case SDLK_DOWN:
			velY += DOT_VEL;
			break;

		case SDLK_LEFT:
			velX -= DOT_VEL;
			break;

		case SDLK_RIGHT:
			velX += DOT_VEL;
			break;
		}
	}
	else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			velY += DOT_VEL;
			break;

		case SDLK_DOWN:
			velY -= DOT_VEL;
			break;

		case SDLK_LEFT:
			velX += DOT_VEL;
			break;

		case SDLK_RIGHT:
			velX -= DOT_VEL;
			break;
		}
	}
}

void Dot::Move(Tile* tiles[]) {
	box.x += velX;

	if ((box.x < 0) || (box.x + DOT_WIDTH > LEVEL_WIDTH) || TouchesWall(box, tiles)) box.x -= velX;

	box.y += velY;

	if ((box.y < 0) || (box.y + DOT_HEIGHT > LEVEL_HEIGHT) || TouchesWall(box, tiles)) box.y -= velY;
}

void Dot::Render(SDL_Rect& camera, SDL_Renderer* renderer){
	sprite->Render(box.x - camera.x, box.y - camera.y, renderer);
}

void Dot::SetCamera(SDL_Rect& camera) {
	camera.x = (box.x + DOT_WIDTH / 2) - SCREEN_WIDTH / 2;
	camera.y = (box.y + DOT_HEIGHT / 2) - SCREEN_HEIGHT / 2;

	if (camera.x < 0) camera.x = 0;
	if (camera.y < 0) camera.y = 0;
	if (camera.x < LEVEL_WIDTH - camera.w) camera.x = LEVEL_WIDTH - camera.w;
	if (camera.y < LEVEL_WIDTH - camera.h) camera.y = LEVEL_WIDTH - camera.h;

}