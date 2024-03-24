
#ifndef SHADER_HPP
# define SHADER_HPP

template <typename I, typename F, typename O>
class Shader {
public:
	virtual F	vert(I const &i) const = 0;
	virtual O	frag(F const & f) const = 0;
};

#endif