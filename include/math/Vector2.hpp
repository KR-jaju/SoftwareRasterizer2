
#ifndef VECTOR2_HPP
# define VECTOR2_HPP

# include "Number.hpp"

struct Vector2 {
	Number	x;
	Number	y;
	Vector2(Number x, Number y): x(x), y(y) {}
};

#endif
