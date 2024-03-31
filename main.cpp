
#include <graphics/Renderer.hpp>
#include "Triangle.hpp"
#include "RenderTexture.hpp"
#include "LambertDiffuse.hpp"
#include <graphics/Viewport.hpp>
#include <iostream>

#include <SDL2/SDL.h>

// int const	width = 1280;
// int const	height = 720;
int const	width = 640;
int const	height = 360;

int	main(void) {
	Viewport		viewport(0, 0, width, height);
	Triangle		in;
	LambertDiffuse	shader;
	RenderTexture	out(width, height);

	SDL_Window* window = SDL_CreateWindow("SDL pixels", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture* pixels = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBX8888, SDL_TEXTUREACCESS_STREAMING, width, height);
	
	while (true) {
		SDL_Event	event;
	
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return (EXIT_SUCCESS);
		}
		void	*data;
		int		pitch;
		SDL_LockTexture(pixels, NULL, &data, &pitch);
		out.setTarget(data);
		Renderer::draw(in, shader, out, viewport);
		SDL_UnlockTexture(pixels);
		SDL_RenderCopy(renderer, pixels, NULL, NULL);
        SDL_RenderPresent(renderer);
	}

}
