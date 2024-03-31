
#ifndef LAMBERT_ATTRIBUTE_HPP
# define LAMBERT_ATTRIBUTE_HPP

# include <math/Vector4.hpp>

struct LambertAttribute {
	Vector4	position;
	Vector4	color;

	LambertAttribute(Vector4 const &position, Vector4 const &color) : position(position), color(color) {}
};

#endif
