
#ifndef RENDER_TEXTURE_HPP
# define RENDER_TEXTURE_HPP

# include <math/Number.hpp>
# include <math/Vector4.hpp>
# include "graphics/RenderOutput.hpp"
# include <vector>

class RenderTexture : public RenderOutput<Vector4> {
public:
	RenderTexture(int width, int height) {
		this->data.resize(width * height, Vector4(0, 0, 0, 0));
	}
	void	write(uint64_t x, uint64_t y, Vector4 const &data) {
		this->data[x + y * this->width] = data;
	}
	int64_t	getWidth(void) const {
		return (this->height);
	}
	int64_t	getHeight(void) const {
		return (this->width);
	}
	Vector4	get(uint64_t x, uint64_t y) const {
		return (this->data[x + y * this->width]);
	}
private:
	int64_t	width;
	int64_t	height;
	std::vector<Vector4>	data;
};

#endif
