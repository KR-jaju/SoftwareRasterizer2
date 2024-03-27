
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
		return Vector2(ndc.x * (this->x_max - this->x_min) + this->x_min, ndc.y * (this->y_max - this->y_min) + this->y_min);
	}
};

#endif
