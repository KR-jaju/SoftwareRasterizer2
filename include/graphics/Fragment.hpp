
#ifndef FRAGMENT_HPP
# define FRAGMENT_HPP

# include <math/Vector4.hpp>

template <typename T> //CRTP
class Fragment {
public:
	virtual T	operator+(T const &other) const = 0;
	virtual	T	operator-(T const &other) const = 0;
	virtual T	operator*(Number const &other) const = 0;
	virtual Vector4 const	&getPosition(void) const = 0;
	virtual void	perspectiveDivide(void) = 0;
	virtual		~Fragment() {}
};

#endif
