//#include "LTexture.h"
//
//extern SDL_Renderer* gRenderer;
//
//LGame::Texture::LTexture() : texture(nullptr), width(0), height(0){
//
//}
//
//
//LGame::Texture::~LTexture() {
//	Free();
//}
//
//bool LGame::Texture::LoadFromFile(const std::string& path) {
//	//Dealloacte preexisting image
//	Free();
//
//	SDL_Texture* newTexture = nullptr;
//
//	//Load image at path
//	SDL_Surface* loadedImage = IMG_Load(path.c_str());
//
//	if (loadedImage) {
//		//Color key image
//		SDL_SetColorKey(loadedImage, SDL_TRUE, SDL_MapRGB(loadedImage->format, 0, 255, 255));
//
//		//Create the texture
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedImage);
//
//		if (newTexture) {
//			width = loadedImage->w;
//			height = loadedImage->h;
//		}
//		else {
//			printf("Unable to create texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
//		}
//		SDL_FreeSurface(loadedImage);
//	}
//	else {
//		//Failed to load
//		printf("Unable to load image %s! SDL_Image_Error: %S\n", path.c_str(), IMG_GetError());
//	}
//
//	texture = newTexture;
//	return texture != nullptr;
//}
//
//void LGame::Texture::Free() {
//	if (texture) {
//		SDL_DestroyTexture(texture);
//		texture = nullptr;
//		height = 0;
//		width = 0;
//	}
//}
//
//void LGame::Texture::Render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* centre, SDL_RendererFlip flip) {
//	//Set render space
//	SDL_Rect renderQuad = { x, y, width, height };
//
//	if (clip) {
//		renderQuad.w = clip->w;
//		renderQuad.h = clip->h;
//	}
//
//	//Render
//	SDL_RenderCopyEx(gRenderer, texture, clip, &renderQuad, angle, centre, flip);
//}
//
//void LGame::Texture::SetColour(Uint8 r, Uint8 g, Uint8 b) {
//	SDL_SetTextureColorMod(texture, r, g, b);
//}
//
//void LGame::Texture::SetAlpha(Uint8 a){
//	SDL_SetTextureAlphaMod(texture, a);
//}
//
//void LGame::Texture::SetBlendMode(SDL_BlendMode blendMode) {
//	SDL_SetTextureBlendMode(texture, blendMode);
//}