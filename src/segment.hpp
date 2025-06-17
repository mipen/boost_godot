#include <boost/polygon/polygon.hpp>
#include <godot_cpp/variant/vector2i.hpp>

#include "point.hpp"

#ifndef H_SEGMENT
#define H_SEGMENT

struct Segment {
	Vector2i p0;
	Vector2i p1;
};

namespace boost {
namespace polygon {
template <>
struct geometry_concept<Segment> {
	typedef segment_concept type;
};

template <>
struct segment_traits<Segment> {
	typedef int coordinate_type;
    typedef Vector2i point_type;

	static inline point_type get(const Segment& segment, direction_1d dir) {
		return dir.to_int() ? segment.p1 : segment.p0;
	}
};
} //namespace polygon
} //namespace boost

#endif