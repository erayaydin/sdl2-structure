#include "App.h"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const char* SCREEN_TITLE = "Game Name";

App::App() {
	Surf_Display = NULL;
	Window = NULL;
	Surf_Test = NULL;

	Running = true;
}

int App::OnExecute() {
	if(OnInit() == false) {
		return -1;
	}

	SDL_Event Event;
	
	while(Running) {
		while(SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();
	
	return 0;
}

bool App::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	if((Window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL)) == NULL) {
		return false;
	}

	if((Surf_Display = SDL_GetWindowSurface(Window)) == NULL) {
		return false;
	}

	SDL_FillRect(Surf_Display, NULL, SDL_MapRGB(Surf_Display->format, 0xFF, 0xFF, 0xFF));

	if((Surf_Test = Surface::OnLoad("/home/eray/Development/C++/SDL/example1/bin/test.bmp")) == NULL) {
		std::cout << "Hoppa!" << std::endl;
		return false;
	}

	return true;
}

void App::OnEvent(SDL_Event* Event) {
	if(Event->type == SDL_QUIT) {
		Running = false;
	}

	if(Event->type == SDL_KEYDOWN) {
		switch(Event->key.keysym.sym) {
			case SDLK_UP:
				std::cout << "Up pressed!" << std::endl;
			break;

			case SDLK_DOWN:
				std::cout << "Down pressed!" << std::endl;
			break;

			case SDLK_LEFT:
				std::cout << "Left pressed!" << std::endl;
			break;

			case SDLK_RIGHT:
				std::cout << "Right pressed!" << std::endl;
			break;
		}
	}
}

void App::OnLoop() {
	SDL_UpdateWindowSurface(Window);
}

void App::OnRender() {
	Surface::OnDraw(Surf_Display, Surf_Test, 0, 0);

}

void App::OnCleanup() {
	SDL_DestroyWindow(Window);
	Surf_Display = NULL;

	SDL_FreeSurface(Surf_Test);
	Surf_Test = NULL;

	SDL_Quit();
}

int main(int argc, char* argv[]) {
	App theApp;

	return theApp.OnExecute();
}
