
#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include <graphics/RenderInput.hpp>
# include "LambertAttribute.hpp"

class Triangle : public RenderInput<LambertAttribute> {
public:
	LambertAttribute	operator[](uint64_t idx) const {
		static LambertAttribute	data[] = {
			LambertAttribute(Vector4(0.0, 0.8, 0.0, 1.0), Vector4(1.0, 0.0, 0.0, 1.0)),
			LambertAttribute(Vector4(-0.8, -0.8, 0.0, 1.0), Vector4(0.0, 1.0, 0.0, 1.0)),
			LambertAttribute(Vector4(0.8, -0.8, 0.0, 1.0), Vector4(0.0, 0.0, 1.0, 1.0))
		};
		return (data[idx]);
	}
	uint64_t	size(void) const {
		return (3);
	}
private:
};

#endif
