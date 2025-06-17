#include <boost/polygon/voronoi.hpp>
#include <cstdio>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <vector>

#include "point.hpp"
#include "segment.hpp"

using boost::polygon::voronoi_builder;
using boost::polygon::voronoi_diagram;

#ifndef VORONOI_DIAGRAM_H
#define VORONOI_DIAGRAM_H

using namespace godot;

class VoronoiDiagram : public RefCounted {
	GDCLASS(VoronoiDiagram, RefCounted)

protected:
	static void _bind_methods();

private:
	std::vector<Vector2i> points;
	std::vector<Rect2i> segments;
	voronoi_diagram<float> vd;

public:
	void addPoint(const Vector2i &p);
	// void addPoints(const std::vector<Vector2i> &points);
	void addSegment(const Rect2i &s);
	void construct();
	void printDiagram();
};

#endif // VORONOI_DIAGRAM_H