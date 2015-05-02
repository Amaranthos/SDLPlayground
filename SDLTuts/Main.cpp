#include <stdio.h>
#include <string>
#include <cmath>
#include <sstream>
#include <iostream>
#include <fstream>

#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_ttf.h>

#include "Globals.h"
#include "Texture.h"
#include "Window.h"
#include "Dot.h"

bool Init();
bool LoadMedia(Game::Tile* tiles[]);
void Close(Game::Tile* tiles[]);

bool CheckCollision(SDL_Rect a, SDL_Rect b);
bool TouchesWall(SDL_Rect box, Game::Tile* tiles[]);
bool SetTiles(Game::Tile* tiles[]);

int main(int argc, char* args[]) {
	//Init
	if (!Init()) {
		printf("Failed to Init!\n");
	}
	else {
		Game::Tile* tileSet[TOTAL_TILES];

		//Load
		if (!LoadMedia(tileSet)) {
			printf("Failed to load media!\n");
		}
		else {

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event event;

			Dot dot;

			SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

			//Main loop
			while (!quit) {
				
				//Poll for events/input
				while (SDL_PollEvent(&event) != 0) {
					if (event.type == SDL_QUIT) quit = true;
					else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) quit = true;
					window.HandleEvent(event);
					dot.HandleEvent(event);
				}

				dot.Move(tileSet);
				dot.SetCamera(camera);
				

				window.Clear();

				for (int i = 0; i < TOTAL_TILES; ++i)
					tileSet[i]->Render(camera);

				dot.Render(camera, window.GetRenderer());

				window.Render();
			}
		}
	}

	//Clean up
	Close();
	return 0;
}