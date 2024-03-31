
#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include <graphics/RenderInput.hpp>

class Triangle : public RenderInput<Vector4> {
public:
	Vector4	operator[](uint64_t idx) const {
		static Vector4	data[] = {
			Vector4(0.0, 0.8, 0.0, 1.0),
			Vector4(-0.8, -0.8, 0.0, 1.0),
			Vector4(0.8, -0.8, 0.0, 1.0),
		};
		return (data[idx]);
	}
	uint64_t	size(void) const {
		return (3);
	}
private:
};

#endif
