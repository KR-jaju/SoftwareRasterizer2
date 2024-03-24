
#ifndef VECTOR4_HPP
# define VECTOR4_HPP

# include "Number.hpp"

struct Vector4 {
	Number	x;
	Number	y;
	Number	z;
	Number	w;
	Vector4(Number x, Number y, Number z, Number w) : x(x), y(y), z(z), w(w) {}
};

#endif
