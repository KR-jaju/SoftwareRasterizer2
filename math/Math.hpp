#ifndef MATH_HPP
# define MATH_HPP

# include "Number.hpp"

class Math
{
public:
	template <typename T>
	static T	lerp(T const &a, T const &b, T const &c, Number t, Number u, Number v) {
		return (a * t + b * u + c * v);
	}
	template <typename T>
	static T	min(T const &a, T const &b) {
		if (a < b)
			return (a);
		return (b);
	}
	template <typename T>
	static T	max(T const &a, T const &b) {
		if (a > b)
			return (a);
		return (b);
	}
	template <typename T>
	static T	floor(T const &a) {
		if (a < 0)
			return ((int)a - 1);
		return (int)a;
	}
	template <typename T>
	static T	round(T const &a) {
		return (Math::ceil(a + T(-0.5)));
	}
	template <typename T>
	static T	ceil(T const &a) {
		return (-Math::floor(a));
	}
	template <typename T, typename U, typename V>
	static Number	area(T const &a, U const &b, V const &c) {
		return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
	}
};


#endif
