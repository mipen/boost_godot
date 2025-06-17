#include "VoronoiDiagram.h"

using namespace godot;

void VoronoiDiagram::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("addPoint", "vector2i"), &VoronoiDiagram::addPoint);
}

void VoronoiDiagram::addPoint(const Vector2i &p) {
	UtilityFunctions::print("Adding point: ");
	UtilityFunctions::print(p);
	points.push_back(p);
	UtilityFunctions::print("Added point successfully.");
}

void VoronoiDiagram::construct() {
	UtilityFunctions::print("Constructing Voronoi diagram with ", points.size(), " points and ", segments.size(), " segments.");
	construct_voronoi(points.begin(), points.end(), segments.begin(), segments.end(), &vd);
	UtilityFunctions::print("Voronoi diagram constructed successfully.");
}