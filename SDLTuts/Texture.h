#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_ttf.h>

namespace Game {
	class Texture {
	public:
		Texture();
		~Texture();

		//Member functions
		bool LoadFromFile(const std::string& path, SDL_Renderer* renderer);

#ifdef _SDL_TTF_H
		bool LoadFromRenderedText(std::string textureText, SDL_Color textColour);
#endif

		void Render(int x, int y, SDL_Renderer* renderer= nullptr, SDL_Rect* clip = nullptr, double angle = 0.0,
			SDL_Point* centre = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);

		void SetColour(Uint8 r, Uint8 g, Uint8 b);
		void SetAlpha(Uint8 a);
		void SetBlendMode(SDL_BlendMode blendMode);

		void Free();

		//Getters/Setters
		int GetWidth() { return width; }
		int GetHeight() { return height; }

	private:
		SDL_Texture* texture;

		int width;
		int height;
	};
}
#endif //TEXTURE_H