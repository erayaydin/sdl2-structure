#include "Surface.h"
#include <iostream>

Surface::Surface() {
}

SDL_Surface* Surface::OnLoad(char* File) {
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* Surf_Return = NULL;

	if((Surf_Temp = SDL_LoadBMP(File)) == NULL) {
		std::cout << "hoppaaaaa" << std::endl;
		return NULL;
	}

	Surf_Return = SDL_ConvertSurfaceFormat(Surf_Temp, SDL_PIXELFORMAT_RGBA8888, 0);
	SDL_FreeSurface(Surf_Temp);

	return Surf_Return;
}

bool Surface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
	if(Surf_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

	return true;
}
