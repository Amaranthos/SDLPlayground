#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <stdio.h>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

class LTexture
{
public:
	LTexture();
	~LTexture();

	bool LoadFromFile(const std::string& path);
	bool LoadFromRenderedText(std::string textureText, SDL_Color textColour);
	void Render(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* centre = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void SetColour(Uint8 r, Uint8 g, Uint8 b);
	void SetAlpha(Uint8 a);
	void SetBlendMode(SDL_BlendMode blendMode);
	void Free();

	int GetWidth() { return width; }
	int GetHeight() { return height; }

private:
	SDL_Texture* texture;

	int width;
	int height;
};

#endif //LTEXTURE_H