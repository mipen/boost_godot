#include "VoronoiDiagram.h"

using namespace godot;

void VoronoiDiagram::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("addPoint", "vector2i"), &VoronoiDiagram::addPoint);
	godot::ClassDB::bind_method(D_METHOD("addSegment", "rect2i"), &VoronoiDiagram::addSegment);
	godot::ClassDB::bind_method(D_METHOD("construct"), &VoronoiDiagram::construct);
	godot::ClassDB::bind_method(D_METHOD("printDiagram"), &VoronoiDiagram::printDiagram);
}

void VoronoiDiagram::addPoint(const Vector2i &p) {
	UtilityFunctions::print("Adding point: ");
	UtilityFunctions::print(p);
	points.push_back(p);
	UtilityFunctions::print("Added point successfully.");
}

void VoronoiDiagram::addSegment(const Rect2i &s) {
	UtilityFunctions::print("Adding segment: ");
	UtilityFunctions::print(s.position, " to ", s.size);
	segments.push_back(s);
	UtilityFunctions::print("Added segment successfully.");
}

void VoronoiDiagram::construct() {
	UtilityFunctions::print("Constructing Voronoi diagram with ", points.size(), " points and ", segments.size(), " segments.");
	construct_voronoi(points.begin(), points.end(), segments.begin(), segments.end(), &vd);
	UtilityFunctions::print("Voronoi diagram constructed successfully.");
}

void VoronoiDiagram::printDiagram() {
	UtilityFunctions::print("Cells: " + String::num_int64(vd.num_cells()) +
		" | Vertices: " + String::num_int64(vd.num_vertices()) +
		" | Edges: " + String::num_int64(vd.num_edges()));
}