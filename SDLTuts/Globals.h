#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>

#include "Tile.h"
#include "Texture.h"
#include "Window.h"

//Global constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;
const int TOTAL_PARTICLES = 20;
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 192;
const int TOTAL_TILE_SPRITES = 12;

const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_CENTRE = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;

//Global variables
Game::Window window;
Game::Texture tile;
SDL_Rect tileClips[TOTAL_TILE_SPRITES];

//Function declarations
bool Init();
bool LoadMedia(Game::Tile* tiles[]);
void Close(Game::Tile* tiles[]);

bool CheckCollision(SDL_Rect a, SDL_Rect b);
bool TouchesWall(SDL_Rect box, Game::Tile* tiles[]);
bool SetTiles(Game::Tile* tiles[]);

bool Init() {
	//Init flag
	bool success = true;

	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not init! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		//Set texture filtering
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) printf("Warning: Linear texture filtering not enabled!\n");

		if (!window.Init(SCREEN_WIDTH, SCREEN_HEIGHT))	success = false;
		else {
			//Init PNG loading
			int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags)) {
				printf("SDL_Image could not initialize! SDL_Image_ErrorL %s\n", IMG_GetError());
				success = false;
			}

			//Init SDL_TT
			/*if (TTF_Init() == -1) {
			printf("SDL_TTF could not initalize! SDL_TTF Error: %s\n", TTF_GetError());
			success = false;
			}*/
		}
	}
	return success;
}

bool LoadMedia(Game::Tile* tiles[]) {
	//Loading flag
	bool success = true;

	if (!tile.LoadFromFile("tiles.png", window.GetRenderer())) success = false;
	if (!SetTiles(tiles)) success = false;

	return success;
}

void Close() {

	//Destroy window
	window.Free();

	tile.Free();

	//Quit
	IMG_Quit();
	SDL_Quit();
}

bool SetTiles(Game::Tile* tiles[]) {
	bool tilesLoaded = true;

	int x = 0, y = 0;

	std::ifstream map("lazy.map");

	if (!map) tilesLoaded = false;
	else {
		for (int i = 0; i < TOTAL_TILES; ++i) {
			int tileType = -1;
			map >> tileType;

			if (map.fail()) {
				tilesLoaded = false;
				break;
			}

			if ((tileType >= 0) && (tileType < TOTAL_TILE_SPRITES)) tiles[i] = new Game::Tile(x, y, tileType);
			else {
				tilesLoaded = false;
				break;
			}

			x += TILE_WIDTH;

			if (x >= LEVEL_WIDTH) {
				x = 0;
				y += TILE_HEIGHT;
			}
		}

		if (tilesLoaded) {
			tileClips[TILE_RED].x = 0;
			tileClips[TILE_RED].y = 0;
			tileClips[TILE_RED].w = TILE_WIDTH;
			tileClips[TILE_RED].h = TILE_HEIGHT;

			tileClips[TILE_GREEN].x = 0;
			tileClips[TILE_GREEN].y = 80;
			tileClips[TILE_GREEN].w = TILE_WIDTH;
			tileClips[TILE_GREEN].h = TILE_HEIGHT;

			tileClips[TILE_BLUE].x = 0;
			tileClips[TILE_BLUE].y = 1600;
			tileClips[TILE_BLUE].w = TILE_WIDTH;
			tileClips[TILE_BLUE].h = TILE_HEIGHT;

			tileClips[TILE_TOPLEFT].x = 80;
			tileClips[TILE_TOPLEFT].y = 0;
			tileClips[TILE_TOPLEFT].w = TILE_WIDTH;
			tileClips[TILE_TOPLEFT].h = TILE_HEIGHT;

			tileClips[TILE_LEFT].x = 80;
			tileClips[TILE_LEFT].y = 80;
			tileClips[TILE_LEFT].w = TILE_WIDTH;
			tileClips[TILE_LEFT].h = TILE_HEIGHT;

			tileClips[TILE_BOTTOMLEFT].x = 80;
			tileClips[TILE_BOTTOMLEFT].y = 160;
			tileClips[TILE_BOTTOMLEFT].w = TILE_WIDTH;
			tileClips[TILE_BOTTOMLEFT].h = TILE_HEIGHT;

			tileClips[TILE_TOP].x = 160;
			tileClips[TILE_TOP].y = 0;
			tileClips[TILE_TOP].w = TILE_WIDTH;
			tileClips[TILE_TOP].h = TILE_HEIGHT;

			tileClips[TILE_CENTRE].x = 160;
			tileClips[TILE_CENTRE].y = 80;
			tileClips[TILE_CENTRE].w = TILE_WIDTH;
			tileClips[TILE_CENTRE].h = TILE_HEIGHT;

			tileClips[TILE_BOTTOM].x = 160;
			tileClips[TILE_BOTTOM].y = 160;
			tileClips[TILE_BOTTOM].w = TILE_WIDTH;
			tileClips[TILE_BOTTOM].h = TILE_HEIGHT;

			tileClips[TILE_TOPRIGHT].x = 240;
			tileClips[TILE_TOPRIGHT].y = 0;
			tileClips[TILE_TOPRIGHT].w = TILE_WIDTH;
			tileClips[TILE_TOPRIGHT].h = TILE_HEIGHT;

			tileClips[TILE_RIGHT].x = 240;
			tileClips[TILE_RIGHT].y = 80;
			tileClips[TILE_RIGHT].w = TILE_WIDTH;
			tileClips[TILE_RIGHT].h = TILE_HEIGHT;

			tileClips[TILE_BOTTOMRIGHT].x = 240;
			tileClips[TILE_BOTTOMRIGHT].y = 160;
			tileClips[TILE_BOTTOMRIGHT].w = TILE_WIDTH;
			tileClips[TILE_BOTTOMRIGHT].h = TILE_HEIGHT;
		}
	}

	map.close();

	return tilesLoaded;
}

bool TouchesWall(SDL_Rect box, Game::Tile* tiles[]) {
	for (int i = 0; i < TOTAL_TILES; ++i) {
		if ((tiles[i]->GetType() >= TILE_CENTRE) && (tiles[i]->GetType() <= TILE_TOPLEFT))
			if (CheckCollision(box, tiles[i]->GetBox())) return true;
	}
	return false;
}
#endif //GLOBALS_H