#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL2/SDL.h>

class Surface {
	public:
		Surface();

	public:
		static SDL_Surface* OnLoad(char* File);

		static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
};

#endif
