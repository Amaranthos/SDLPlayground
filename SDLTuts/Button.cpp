#include "Button.h"

extern Game::Texture gButtonTexture;
extern SDL_Rect gButtonClip[Total];

Game::Button::Button() : position({ 0, 0 }), currSprite(LeftButtonSprite::Out) {

}

void Game::Button::SetPosition(int x, int y){
	position.x = x;
	position.y = y;
}

void Game::Button::HandleEvent(SDL_Event* event) {
	if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN || event->type == SDL_MOUSEBUTTONUP) {
		//Get position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if cursor is in button
		bool isInside = true;

		if (x < position.x) isInside = false;
		else if (x > position.x + WIDTH) isInside = false;
		else if (y < position.y) isInside = false;
		else if (y > position.y + HEIGHT) isInside = false;

		if (!isInside) currSprite = LeftButtonSprite::Out;
		else {
			switch (event->type) {
			case SDL_MOUSEMOTION:
				currSprite = LeftButtonSprite::Over_Motion;
				break;

			case SDL_MOUSEBUTTONDOWN:
				currSprite = LeftButtonSprite::Down;
				break;

			case SDL_MOUSEBUTTONUP:
				currSprite = LeftButtonSprite::Up;
				break;

			default:
				break;
			}
		}
	}
}

void Game::Button::Render() {
	gButtonTexture.Render(position.x, position.y, &gButtonClip[currSprite]);
}