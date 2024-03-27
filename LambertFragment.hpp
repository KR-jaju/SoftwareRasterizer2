
#ifndef LAMBERT_FRAGMENT_HPP
# define LAMBERT_FRAGMENT_HPP

#include <graphics/Fragment.hpp>
#include <math/Vector4.hpp>

class LambertFragment : public Fragment<LambertFragment> {
public:
	LambertFragment(Vector4 const &p) : position(p) {}
	LambertFragment operator+(LambertFragment const &other) const {
		return (LambertFragment(
			this->position + other.position
		));
	}
	LambertFragment operator-(LambertFragment const &other) const {
		return (LambertFragment(
			this->position - other.position
		));
	}
	LambertFragment	operator*(Number const &v) const {
		return (LambertFragment(
			this->position * v
		));
	}
	Vector4 const	&getPosition(void) const {
		return (this->position);
	}
	void	perspectiveDivide(void) {
		this->position.w = Number(1) / this->position.w;
		this->position.x *= this->position.w;
		this->position.y *= this->position.w;
		this->position.z *= this->position.w;
	}
private:
	Vector4 position;
};

#endif
