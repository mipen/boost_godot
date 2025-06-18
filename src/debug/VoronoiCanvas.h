#ifndef VORONOI_CANVAS_H
#define VORONOI_CANVAS_H

#include <boost/polygon/voronoi.hpp>
#include <godot_cpp/classes/control.hpp>

using boost::polygon::voronoi_diagram;

using namespace godot;

class VoronoiCanvas : public Control {
	GDCLASS(VoronoiCanvas, Control);

private:
	voronoi_diagram<double> *diagram;

protected:
	static void _bind_methods();

public:
	virtual void _draw() override;
	void set_diagram(voronoi_diagram<double> *vd);
};

#endif // VORONOI_CANVAS_H