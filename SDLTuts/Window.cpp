#include "Window.h"

Game::Window::Window(): window(nullptr), mouseFocus(false), keyboardFocus(false), fullscreen(false), minimized(false), width(0), height(0) {

}

Game::Window::~Window() {
	Free();
}

bool Game::Window::Init(int width, int height) {
	window = SDL_CreateWindow("SDL Playground", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (window) {
		mouseFocus = true;
		keyboardFocus = true;
		this->width = width;
		this->height = height;

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			windowID = SDL_GetWindowID(window);
			shown = true;
		}
		else {
			printf("Warning: Renderer could not be created!: SDL Error: %s\n", SDL_GetError());
			Free();
		}
	}
	else {
		printf("Warning: Window could not be created!: SDL Error: %s\n", SDL_GetError());
	}

	return !!window && !!renderer;
}

void Game::Window::Focus() {
	if (!shown) SDL_ShowWindow(window);
	SDL_RaiseWindow(window);
}

void Game::Window::HandleEvent(SDL_Event& e) {
	if (e.type == SDL_WINDOWEVENT && e.window.windowID == windowID) {
		bool updateCaption = false;

		switch (e.window.event) {
		case SDL_WINDOWEVENT_SHOWN:
			shown = true;
			break;

		case SDL_WINDOWEVENT_HIDDEN:
			shown = false;
			break;

		case SDL_WINDOWEVENT_SIZE_CHANGED:
			width = e.window.data1;
			height = e.window.data2;
			SDL_RenderPresent(renderer);
			break;

		case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(renderer);
			break;

		case SDL_WINDOWEVENT_ENTER:
			mouseFocus = true;
			updateCaption = true;
			break;

		case SDL_WINDOWEVENT_LEAVE:
			mouseFocus = false;
			updateCaption = true;

		case SDL_WINDOWEVENT_FOCUS_GAINED:
			keyboardFocus = true;
			updateCaption = true;
			break;

		case SDL_WINDOWEVENT_FOCUS_LOST:
			keyboardFocus = false;
			updateCaption = true;
			break;

		case SDL_WINDOWEVENT_MINIMIZED:
			minimized = true;
			break;

		case SDL_WINDOWEVENT_MAXIMIZED:
			minimized = false;
			break;

		case SDL_WINDOWEVENT_RESTORED:
			minimized = false;
			break;

		case SDL_WINDOWEVENT_CLOSE:
			SDL_HideWindow(window);
			break;

		default:
			break;
		}

		if (updateCaption) {
			std::stringstream caption;
			caption << "SDL Playground - MouseFocus: " << ((mouseFocus) ? "On" : "Off") << " Keyboard Focus: " << ((keyboardFocus) ? "On" : "Off");
			SDL_SetWindowTitle(window, caption.str().c_str());
		}
	}
	else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
		if (fullscreen) {
			SDL_SetWindowFullscreen(window, SDL_FALSE);
			fullscreen = false;
		}
		else {
			SDL_SetWindowFullscreen(window, SDL_TRUE);
			fullscreen = true;
			minimized = false;
		}
	}
}

void Game::Window::Clear() {
	if (!minimized) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
	}
}

void Game::Window::Render() {
	if (!minimized) {
		SDL_RenderPresent(renderer);
	}
}

void Game::Window::Free() {
	if (renderer) SDL_DestroyRenderer(renderer);
	if (window) SDL_DestroyWindow(window);

	renderer = nullptr;
	window = nullptr;

	mouseFocus = false;
	keyboardFocus = false;
	width = 0;
	height = 0;
}