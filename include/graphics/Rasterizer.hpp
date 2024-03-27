
#ifndef RASTERIZER_HPP
# define RASTERIZER_HPP

# include <cstdint>
# include "Shader.hpp"
# include "RenderOutput.hpp"
# include "math/Vector4.hpp"
# include "math/Math.hpp"
# include "Viewport.hpp"

class Rasterizer {
public:
	template <typename I, typename F, typename O>
	static void	draw(F const &v0, F const &v1, F const &v2, Shader<I, F, O> const &shader, RenderOutput<O> &out, Viewport viewport) {
		// 1. w로 나눔 -> ndc를 얻음
		// 2. ndc -> viewport space
		// for문을 돌면서 fragcoord를 만듬.
		Vector2 const	v0_screen = viewport.transform(v0.getPosition());
		Vector2 const	v1_screen = viewport.transform(v1.getPosition());
		Vector2 const	v2_screen = viewport.transform(v2.getPosition());
		uint64_t const	x_min = Math::max(Math::round(Math::min(v0_screen.x, v1_screen.x, v2_screen.x)), viewport.x_min);
		uint64_t const	x_max = Math::min(Math::round(Math::max(v0_screen.x, v1_screen.x, v2_screen.x)), viewport.x_max);
		uint64_t const	y_min = Math::max(Math::round(Math::min(v0_screen.y, v1_screen.y, v2_screen.y)), viewport.y_min);
		uint64_t const	y_max = Math::min(Math::round(Math::max(v0_screen.y, v1_screen.y, v2_screen.y)), viewport.y_max);
		Number const	area = Math::area(v0_screen, v1_screen, v2_screen);

		for (uint64_t y = y_min; y <= y_max; ++y) {
			for (uint64_t x = x_min; x <= x_max; ++x) {
				Number const	&u = Math::area(v1_screen, v2_screen, Vector2(x, y)) / area;
				Number const	&v = Math::area(v1_screen, v2_screen, Vector2(x, y)) / area;
				Number const	&w = 1 - u - v;
				if (0 <= u && u <= 1 && v <= 0 && v <= 1 && 0 <= w && w <= 1) {
					F const	&fragment = Math::lerp(v0, v1, v2, u, v, w);
					if (!out.depthTest(x, y, fragment.getPosition().z))
						continue;
					out.write(x, y, shader.frag(fragment));
				}
			}
		}
	}
};

#endif