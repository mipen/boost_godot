#include "VoronoiDiagram.h"

void VoronoiDiagram::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("addPoint", "vector2i"), &VoronoiDiagram::addPoint);
}

void VoronoiDiagram::addPoint(const Vector2i &p) {
    points.push_back(p);
}