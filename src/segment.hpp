#include <boost/polygon/polygon.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/variant/rect2i.hpp>

#include "point.hpp"

#ifndef H_SEGMENT
#define H_SEGMENT

// struct Segment {
// 	Vector2i p0;
// 	Vector2i p1;
// };

namespace boost {
namespace polygon {
template <>
struct geometry_concept<Rect2i> {
	typedef segment_concept type;
};

template <>
struct segment_traits<Rect2i> {
	typedef int coordinate_type;
    typedef Vector2i point_type;

	static inline point_type get(const Rect2i& segment, direction_1d dir) {
		return dir.to_int() ? segment.position : segment.size;
	}
};
} //namespace polygon
} //namespace boost

#endif