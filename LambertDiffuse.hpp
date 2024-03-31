
#ifndef LAMBERT_DIFFUSE_HPP
# define LAMBERT_DIFFUSE_HPP

# include <math/Vector4.hpp>
# include <graphics/Shader.hpp>
# include "LambertFragment.hpp"
# include "LambertAttribute.hpp"

class LambertDiffuse : public Shader<LambertAttribute, LambertFragment, Vector4> {
	LambertFragment	vert(LambertAttribute const &i) const {
		return (LambertFragment(i.position, i.color));
	}
	Vector4	frag(LambertFragment const &f) const {
		(void)f;
		return (f.color);
	}
};

#endif
