
#ifndef VECTOR4_HPP
# define VECTOR4_HPP

# include "Number.hpp"

struct Vector4 {
	Number	x;
	Number	y;
	Number	z;
	Number	w;
	Vector4(): x(0), y(0), z(0), w(0) {}
	Vector4(Number x, Number y, Number z, Number w) : x(x), y(y), z(z), w(w) {}
	static Number	dot(Vector4 const &a, Vector4 const &b) {
		return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
	}
	Vector4	operator+(Vector4 const &other) const {
		return (Vector4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w));
	}
	Vector4	operator-(Vector4 const &other) const {
		return (Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w));
	}
	Vector4	operator*(Vector4 const &other) const {
		return (Vector4(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w));
	}
	Vector4	operator*(Number v) const {
		return (Vector4(this->x * v, this->y * v, this->z * v, this->w * v));
	}
	Vector4	operator/(Number v) const {
		return (Vector4(this->x / v, this->y / v, this->z / v, this->w / v));
	}
};

#endif
