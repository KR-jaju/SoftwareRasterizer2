
#ifndef LAMBERT_DIFFUSE_HPP
# define LAMBERT_DIFFSE_HPP

# include <math/Vector4.hpp>
# include "Shader.hpp"

class LambertDiffuse : public Shader<Vector4, Vector4, Vector4> {
	Vector4	vert(Vector4 const &i) const {
		return (i);
	}
	Vector4	frag(Vector4 const & f) const {
		return (Vector4(1.0, 0.0, 0.0, 1.0));
	}
}

#endif
