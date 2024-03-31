
#include <graphics/Renderer.hpp>
#include "Triangle.hpp"
#include "RenderTexture.hpp"
#include "LambertDiffuse.hpp"
#include <graphics/Viewport.hpp>
#include <iostream>

int	main(void) {
	int const	size = 64;
	Viewport		viewport(0, 0, size, size);
	Triangle		in;
	LambertDiffuse	shader;
	RenderTexture	out(size, size);
	
	Renderer::draw(in, shader, out, viewport);

	for (int y = 0; y < size; ++y) {
		for (int x = 0; x < size; ++x) {
			if (out.get(x, y).x > 0.5) {
				std::cout << "#";
			} else {
				std::cout << " ";
			}
		}
		std::cout << '\n';
	}
}