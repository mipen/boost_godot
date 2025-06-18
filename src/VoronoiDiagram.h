#include <boost/polygon/voronoi.hpp>
#include <cstdio>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <vector>

#include "debug/VoronoiCanvas.h"
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
	voronoi_diagram<double> vd;
	Control *canvas = nullptr;

public:
	void addPoint(const Vector2i &p);
	// void addPoints(const std::vector<Vector2i> &points);
	void addSegment(const Rect2i &s);
	void construct();
	void printDiagram();
	void registerCanvas(Control *canvas);
};

#endif // VORONOI_DIAGRAM_H