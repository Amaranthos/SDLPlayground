#ifndef BUTTON_H
#define BUTT0N_H

#include <SDL.h>

#include "Enums.h"
#include "Texture.h"

namespace Game {
	class Button {
	public:
		Button();

		void SetPosition(int x, int y);
		void HandleEvent(SDL_Event* event);

		void Render();

		static const int WIDTH = 300;
		static const int HEIGHT = 200;

	private:
		SDL_Point position;
		LeftButtonSprite currSprite;
	};
}
#endif //BUTTON_H

