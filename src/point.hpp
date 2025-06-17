#include <boost/polygon/polygon.hpp>
#include <godot_cpp/variant/vector2i.hpp>

#ifndef H_POINT
#define H_POINT

using namespace godot;

namespace boost {
namespace polygon {
template <>
struct geometry_concept<Vector2i> {
	typedef point_concept type;
};

template <>
struct point_traits<Vector2i> {
	typedef int coordinate_type;

	static inline coordinate_type get(const Vector2i &point, orientation_2d orient) {
		if (orient == HORIZONTAL)
			return point.x;
		return point.y;
	}
};

template <>
struct point_mutable_traits<Vector2i> {
	typedef int coordinate_type;

	static inline void set(Vector2i &point, orientation_2d orient, int value) {
		if (orient == HORIZONTAL)
			point.x = value;
		else
			point.y = value;
	}

	static inline Vector2i construct(int xVal, int yVal) {
		Vector2i res;
		res.x = xVal;
		res.y = yVal;
		return res;
	}
};
} //namespace polygon
} //namespace boost

#endif