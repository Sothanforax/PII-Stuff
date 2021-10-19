#include <iostream>
#include <SDL2/SDL.h>

int main(){
	bool keepalive = true;
	int wx, wy;

	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Failed to initialize SDL2" << std::endl;
		std::cout << SDL_GetError << std::endl;
		return -1;
	}
	std::cout << "SDL Initialized successfully" << std::endl;
	SDL_Window *win = SDL_CreateWindow("Look at me ma, I'm a window :)",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
	if(!win){
		std::cout << "Window creation failure" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	std::cout << "Window successfully created"  << std::endl;
	SDL_GetWindowSize(win, &wx, &wy);
	std::cout << "SDL_GetWindowSize returns " << wx << "x" << wy << std::endl;
	SDL_Surface *win_surface = SDL_GetWindowSurface(win);
	SDL_Surface *img_surface = SDL_LoadBMP("cliffft.bmp");
	SDL_Renderer *mainrenderer;
	SDL_CreateSoftwareRenderer(win_surface);
	SDL_SetRenderDrawColor(mainrenderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(mainrenderer, 0, 0, 640, 480);
	SDL_Rect bmprect;
	if(!img_surface){
		std::cout << SDL_GetError();
		return -1;
	}
	std::cout << "Bitmap image successfully loaded into surface" << std::endl;
	bmprect.x = 0;
	bmprect.y = 0;
	bmprect.w = 256;
	bmprect.h = 256;
	SDL_Event ex;
	while(keepalive == true){
		while(SDL_PollEvent(&ex) > 0){
			switch(ex.type){
				case SDL_QUIT:
					keepalive = false;
			}
			SDL_BlitSurface(img_surface, NULL, win_surface, &bmprect);
			SDL_RenderClear(mainrenderer);
			SDL_RenderPresent(mainrenderer);
			SDL_UpdateWindowSurface(win);
	}
}
SDL_Quit();
}
