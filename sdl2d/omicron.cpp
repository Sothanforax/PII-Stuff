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
	SDL_Renderer *mainrenderer = SDL_CreateSoftwareRenderer(win_surface);
	if(!mainrenderer){
		std::cout << "Failed to create renderer" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	std::cout << "Renderer successfully created" << std::endl;
	SDL_Rect ssrect1;
	SDL_Rect ssrect2;
	ssrect1.w = 100;
	ssrect1.h = 100;
	ssrect1.x = 200;
	ssrect1.y = 200;
	ssrect2.w = 100;
	ssrect2.h = 100;
	ssrect2.x = 100;
	ssrect2.y = 100;
	SDL_Event ex;
	while(keepalive == true){
		while(SDL_PollEvent(&ex) > 0){
			switch(ex.type){
				case SDL_QUIT:
					keepalive = false;
			}
			SDL_RenderClear(mainrenderer);
			SDL_SetRenderDrawColor(mainrenderer, 0, 255, 255, 255);
			SDL_RenderFillRect(mainrenderer, &ssrect1);
			SDL_SetRenderDrawColor(mainrenderer, 255, 255, 255, 255);
			SDL_RenderDrawLine(mainrenderer, 0, 0, 400, 400);
			SDL_SetRenderDrawColor(mainrenderer, 255, 0, 0, 255);
			SDL_RenderFillRect(mainrenderer, &ssrect2);
			SDL_SetRenderDrawColor(mainrenderer, 0, 0, 0, 255);
			SDL_RenderPresent(mainrenderer);
			SDL_UpdateWindowSurface(win);
	}
}
SDL_Quit();
}
