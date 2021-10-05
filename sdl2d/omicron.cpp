#include <iostream>
#include <SDL2/SDL.h>

int main(){
	bool keepalive = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Failed to initialize SDL2" << std::endl;
		std::cout << SDL_GetError << std::endl;
		return -1;
	}
	SDL_Window *win = SDL_CreateWindow("Look at me ma, I'm a window :)",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
	if(!win){
		std::cout << "Window creation failure" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	SDL_Surface *win_surface = SDL_GetWindowSurface(win);
	SDL_Surface *img_surface = SDL_LoadBMP("cliffft.bmp");
	if(!img_surface){
		std::cout << SDL_GetError();
		return -1;
	}
	while(keepalive == true){
		SDL_Event ex;
		while(SDL_PollEvent(&ex) > 0){
			switch(ex.type){
				case SDL_QUIT:
					keepalive = false;
			}
			SDL_BlitSurface(img_surface, NULL, win_surface, NULL);
			std::cout << SDL_GetError() << std::endl;
			SDL_UpdateWindowSurface(win);
	}
	SDL_Quit();
}
}
