
#ifndef VIEWPORT_HPP
# define VIEWPORT_HPP

# include <cstdint>
# include <math/Vector2.hpp>
# include <math/Vector4.hpp>

struct Viewport {
public:
	Number	x_min;
	Number	y_min;
	Number	x_max;
	Number	y_max;
	Viewport(Number x_min, Number y_min, Number x_max, Number y_max): x_min(x_min), y_min(y_min), x_max(x_max), y_max(y_max) {}
	Vector2	transform(Vector4 ndc) const {
		Number	const xa = (x_max - x_min) * Number(0.5);
		Number	const xb = (x_max + x_min) * Number(0.5);
		Number	const ya = (y_max - y_min) * Number(0.5);
		Number	const yb = (y_max + y_min) * Number(0.5);
		return Vector2(ndc.x * xa + xb, -ndc.y * ya + yb);
	}
};

#endif
