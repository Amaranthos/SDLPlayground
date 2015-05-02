#include "Texture.h"

Game::Texture::Texture() : width(0), height(0){
	texture = nullptr;
}


Game::Texture::~Texture() {
	Free();
}

bool Game::Texture::LoadFromFile(const std::string& path, SDL_Renderer* renderer) {
	//Dealloacte preexisting image
	Free();
	
	SDL_Texture* newTexture = nullptr;

	//Load image at path
	SDL_Surface* loadedImage = IMG_Load(path.c_str());

	if (loadedImage) {
		//Color key image
		SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0, 255, 255));

		//Create the texture
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedImage);

		if (newTexture) {
			width = loadedImage->w;
			height = loadedImage->h;
		}
		else {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedImage);
	}
	else {
		printf("Unable to load image %s! SDL_Image Error: %S\n", path.c_str(), IMG_GetError());
	}

	texture = newTexture;
	return !!texture;
}

#ifdef _SDL_TTF_H
extern TTF_Font* gFont;

bool Game::Texture::LoadFromRenderedText(std::string textureText, SDL_Color textColour) {
	//Deallocate prexisting image
	Free();
	
	SDL_Surface* textImage = TTF_RenderUTF8_Blended(gFont, textureText.c_str(), textColour);

	if (textImage) {
		//Create the texture
		texture = SDL_CreateTextureFromSurface(gRenderer, textImage);

		if (texture) {
			width = textImage->w;
			height = textImage->h;
		}
		else {
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}

		SDL_FreeSurface(textImage);
	}
	else {
		printf("Unable to  load rendered text! SDL_TTF Error: %s\n", TTF_GetError());
	}	

	return !!texture;
}
#endif

void Game::Texture::Render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip, double angle,
	SDL_Point* centre, SDL_RendererFlip flip) {
	//Set render space
	SDL_Rect renderQuad = { x, y, width, height };

	if (clip) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render
	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, centre, flip);
}

void Game::Texture::SetColour(Uint8 r, Uint8 g, Uint8 b) {
	SDL_SetTextureColorMod(texture, r, g, b);
}

void Game::Texture::SetAlpha(Uint8 a){
	SDL_SetTextureAlphaMod(texture, a);
}

void Game::Texture::SetBlendMode(SDL_BlendMode blendMode) {
	SDL_SetTextureBlendMode(texture, blendMode);
}

void Game::Texture::Free() {
	if (texture) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
		height = 0;
		width = 0;
	}
}