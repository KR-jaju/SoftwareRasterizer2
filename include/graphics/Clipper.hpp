#ifndef CLIPPER_HPP
# define CLIPPER_HPP

# include <queue>

//가능한 경우 최대 3+6 -> 9각형
class Clipper { // 결과가 항상 볼록함(convex) -> 한 면에 대해서 clipping 할 때 최대 1의 각이 생김
public:
	template <typename F>
	static void	clip(std::deque<F> &vertices) {
		Clipper::clipSide(vertices, Vector4(1, 0, 0, 0));
		Clipper::clipSide(vertices, Vector4(-1, 0, 0, 0));
		Clipper::clipSide(vertices, Vector4(0, 1, 0, 0));
		Clipper::clipSide(vertices, Vector4(0, -1, 0, 0));
		Clipper::clipSide(vertices, Vector4(0, 0, 1, 0));
		Clipper::clipSide(vertices, Vector4(0, 0, -1, 0));
	}
private:
	template <typename F>
	static bool	isInside(F const &a, Vector4 const &axis) {
		Vector4 const	&position = a.getPosition();
		Number const	w = position.w;
		Number const	v = Vector4::dot(position, axis); // 
		return (v <= w);
	}
	// (a.x + (b.x - a.x) * t) / (a.w + (b.w - a.w) * t) = 1.0
	// 에서 유도됨.
	template <typename F>
	static F	interpolate(F const &a, F const &b, Vector4 const &axis) {
		Vector4 const	&a_position = a.getPosition();
		Vector4 const	&b_position = b.getPosition();
		Number const	p = Vector4::dot(a_position, axis);
		Number const	q = Vector4::dot(b_position, axis); // b_position의 특정 축
		Number const	r = p - a_position.w;
		Number const	s = q - b_position.w;
		Number const	t = r / (r - s);

		return (Math::lerp(a, b, t));
	}
	template <typename F>
	static void	clipSide(std::deque<F> &queue, Vector4 const &axis) {
		int const	count = static_cast<int>(queue.size());
		if (count <= 2)
			return ; // #E
		F	curr = queue.back();
		for (int i = 0; i < count; ++i) {
			F	prev = curr;
			curr = queue.front();
			queue.pop_front();
			F	intersection = Clipper::interpolate(prev, curr, axis);
			if (Clipper::isInside(curr, axis)) {
				if (!Clipper::isInside(prev, axis)) {
					queue.push_back(intersection);
				}
				queue.push_back(curr);
			} else if (Clipper::isInside(prev, axis)) {
				queue.push_back(intersection);
			}
		}
	}
};

#endif