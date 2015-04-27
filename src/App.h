#ifndef _APP_H_
#define _APP_H_

#include <SDL2/SDL.h>

class App {
	private:
		bool Running;

		SDL_Surface* Surf_Display;

		SDL_Window* Window;
	
	public:
		App();
		int OnExecute();

	public:
		bool OnInit();

		void OnEvent(SDL_Event* Event);

		void OnLoop();

		void OnRender();

		void OnCleanup();
};

#endif
