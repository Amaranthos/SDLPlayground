#ifndef WINDOW_H
#define WINDOW_H

#include <sstream>

#include <SDL.h>

namespace Game{
	class Window {
	public:
		Window();
		~Window();

		bool Init(int width, int height);
		
		void HandleEvent(SDL_Event& event);
		void Clear();
		void Render();

		void Focus();

		void Free();

		//Getters and setters
		int GetWidth() { return width; }
		int GetHeight() { return height; }
		SDL_Renderer* GetRenderer() { return renderer; }
		bool HasMouseFocus() { return mouseFocus; }
		bool HasKeyboard() { return keyboardFocus; }
		bool IsMinimized() { return minimized; }
		bool IsShown() { return shown; }
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		int windowID;
		
		int width;
		int height;

		bool mouseFocus;
		bool keyboardFocus;
		bool fullscreen;
		bool minimized;
		bool shown;
	};
}
#endif //WINDOW_H
