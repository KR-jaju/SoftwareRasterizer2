
#ifndef RENDER_TEXTURE_HPP
# define RENDER_TEXTURE_HPP

# include <math/Number.hpp>
# include <math/Vector4.hpp>
# include "graphics/RenderOutput.hpp"
# include <vector>

class RenderTexture : public RenderOutput<Vector4> {
public:
	RenderTexture(int width, int height) {
		this->width = width;
		this->height = height;
		this->depth.resize(width * height, 1.0f);
	}
	void	setTarget(void *addr) {
		this->addr = addr;
	}
	void	write(uint64_t x, uint64_t y, Vector4 const &data) {
		unsigned int const	r = (int)Math::clamp(data.x * 256, Number(0), Number(255)) & 0x000000ff;
		unsigned int const	g = (int)Math::clamp(data.y * 256, Number(0), Number(255)) & 0x000000ff;
		unsigned int const	b = (int)Math::clamp(data.z * 256, Number(0), Number(255)) & 0x000000ff;
		unsigned int const	color = 0x000000ff | (r << 24) | (g << 16) | (b << 8);
		*((unsigned int *)this->addr + this->width * y + x) = color;
		// color;
	}
	int64_t	getWidth(void) const {
		return (this->height);
	}
	int64_t	getHeight(void) const {
		return (this->width);
	}
	// Vector4	get(uint64_t x, uint64_t y) const {
	// 	return (this->addr[x + y * this->width]);
	// }
	bool	depthTest(uint64_t x, uint64_t y, Number depth) const {
		float const	dst = this->depth[x + y * this->width];
		return (depth < dst);
	}
private:
	void	*addr;
	int64_t	width;
	int64_t	height;
	std::vector<float>		depth;
};

#endif
