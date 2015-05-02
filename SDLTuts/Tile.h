#ifndef TILE_H
#define TILE_H

#include <SDL.h>

#include "Globals.h"

namespace Game {
	class Tile {
	public:
		Tile(int x, int y, int tileType);
		~Tile();

		void Render(SDL_Rect& camera);

		int GetType() { return type; }
		SDL_Rect GetBox() { return box; }

	private:
		SDL_Rect box;
		int type;
	};
}
#endif //TILE_H