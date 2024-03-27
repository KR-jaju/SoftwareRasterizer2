
#include <graphics/Renderer.hpp>
#include "Triangle.hpp"
#include "RenderTexture.hpp"
#include "LambertDiffuse.hpp"
#include <graphics/Viewport.hpp>
#include <iostream>

int	main(void) {
	Viewport		viewport(0, 0, 128, 128);
	Triangle		in;
	LambertDiffuse	shader;
	RenderTexture	out(128, 128);
	
	Renderer::draw(in, shader, out, viewport);

	for (int y = 0; y < 128; ++y) {
		for (int x = 0; x < 128; ++x) {
			if (out.get(x, y).x > 0.5) {
				std::cout << "#";
			} else {
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
}