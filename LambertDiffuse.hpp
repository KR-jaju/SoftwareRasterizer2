
#ifndef LAMBERT_DIFFUSE_HPP
# define LAMBERT_DIFFSE_HPP

# include <math/Vector4.hpp>
# include <graphics/Shader.hpp>
# include "LambertFragment.hpp"

class LambertDiffuse : public Shader<Vector4, LambertFragment, Vector4> {
	LambertFragment	vert(Vector4 const &i) const {
		return (LambertFragment(i));
	}
	Vector4	frag(LambertFragment const &f) const {
		(void)f;
		return (Vector4(1.0, 0.0, 0.0, 1.0));
	}
};

#endif
