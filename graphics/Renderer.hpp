
#ifndef RENDERER_HPP
# define RENDERER_HPP

# include <cstdint>
# include "RenderInput.hpp"
# include "Shader.hpp"
# include "RenderOutput.hpp"
# include "math/Vector4.hpp"
# include "math/Math.hpp"
# include "Clipper.hpp"
# include "Rasterizer.hpp"
# include "Viewport.hpp"

class Renderer {
public:
	template <typename I, typename F, typename O>
	static void	draw(RenderInput<I> const &in, Shader<I, F, O> const &shader, RenderOutput<O> &out, Viewport viewport) {
		int64_t const	size = in.size();
		std::deque<F>	vertices;

		for (int64_t i = 0; i + 3 < size; i += 3) {
			vertices.push(shader.vert(in[i]));
			vertices.push(shader.vert(in[i + 1]));
			vertices.push(shader.vert(in[i + 2]));
			
			Clipper::clip(vertices);
			std::deque<F>::iterator	it = vertices.begin();
			if (vertices.size() < 3)
				continue; // #E
			for (std::deque<F>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
				Vector4	&position = it->position;
				position.w = Number(1) / position.w;
				position.x *= position.w;
				position.y *= position.w;
				position.z *= position.w;
			} // perspetive division
			F const	&v0 = *it;
			++it;
			while (it + 1 != vertices.end()) {
				F const	&v1 = *it;
				F const	&v2 = *(++it);
				Rasterizer::draw(v0, v1, v2, shader, out, viewport);
			}
		}
	}
private:
};

#endif
