
#ifndef RENDER_OUTPUT_HPP
# define RENDER_OUTPUT_HPP

# include <cstdint>

template <typename O>
class RenderOutput {
public:
	virtual void	write(uint64_t x, uint64_t y, O const &data) = 0;
	virtual int64_t	getWidth(void) const = 0;
	virtual int64_t	getHeight(void) const = 0;
};

#endif
