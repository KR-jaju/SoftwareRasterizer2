
#ifndef RENDER_INPUT_HPP
# define RENDER_INPUT_HPP

# include <cstdint>
# include <math/Vector4.hpp>

template <typename I>
class RenderInput {
public:
	virtual I	operator[](uint64_t idx) const = 0;
	virtual uint64_t	size(void) const = 0;
};

#endif
