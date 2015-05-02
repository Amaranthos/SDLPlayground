#include "Tile.h"

Game::Tile::Tile(int x, int y, int tileType) {
	box.x = x;
	box.y = y;

	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;

	type = tileType;
}

Game::Tile::~Tile() {

}

void Game::Tile::Render(SDL_Rect& camera) {
	if (CheckCollision(camera, box)) tile.Render(box.x - camera.x, box.y - camera.y, window.GetRenderer(), &tileClips[type]);
}