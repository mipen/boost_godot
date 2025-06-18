#include "VoronoiCanvas.h"

using namespace godot;

void VoronoiCanvas::_bind_methods() {
	// Optionally bind set_diagram if you want to set from GDScript
}

void VoronoiCanvas::_draw() {
	if (!diagram)
		return;

	auto &edges = diagram->edges();
	for (auto it = edges.begin(); it != edges.end(); ++it) {
		const auto &edge = *it;
		if (!edge.is_primary() || !edge.is_finite())
			continue;

		auto v0 = edge.vertex0();
		auto v1 = edge.vertex1();
		if (v0 && v1) {
			Vector2 p0(v0->x(), v0->y());
			Vector2 p1(v1->x(), v1->y());
			// Optionally scale/translate to fit your canvas
			draw_line(p0, p1, Color(0, 0, 0, 1), 1.0);
		}
	}
}

void VoronoiCanvas::set_diagram(voronoi_diagram<double> *vd) {
    if (vd) {
        diagram = vd;
    } else {
        UtilityFunctions::print("Failed to set diagram: null pointer.");
    }
}