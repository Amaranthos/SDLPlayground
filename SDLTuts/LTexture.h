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
	void Free();
	void Render(int x, int y, SDL_Rect* clip = nullptr);

	int GetWidth() { return width; }
	int GetHeight() { return height; }

private:
	SDL_Texture* texture;

	int width;
	int height;
};

#endif //LTEXTURE_H