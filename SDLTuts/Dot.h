#ifndef DOT_H
#define DOT_H

#include <SDL.h>

#include "Tile.h"
#include "Texture.h"

class Dot {
public:
	Dot();
	~Dot();
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;
	static const int DOT_VEL = 10;

	void HandleEvent(SDL_Event& event);
	void Move(Game::Tile* tiles[]);

	void SetCamera(SDL_Rect& camera);

	void Render(SDL_Rect& camera, SDL_Renderer* renderer);

	Game::Texture* sprite;

private:
	SDL_Rect box;
	int velX, velY;
};
#endif //DOT_H