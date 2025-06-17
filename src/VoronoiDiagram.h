#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <boost/polygon/voronoi.hpp>

#include "point.hpp"
#include "segment.hpp"

using boost::polygon::voronoi_builder;
using boost::polygon::voronoi_diagram;

using namespace godot;

class VoronoiDiagram : public RefCounted {
    GDCLASS(VoronoiDiagram, RefCounted)

protected:
    static void _bind_methods();

private:
    std::vector<Vector2i> points;
    std::vector<Segment> segments;
    voronoi_diagram<double> vd;

public:
    void addPoint(const Vector2i &p);
    // void addPoints(const std::vector<Vector2i> &points);
};