using System.Runtime.InteropServices;
using Godot;

namespace BoostGodot.csharp
{
    [Tool]
    [GlobalClass]
    public partial class VDTest : Node3D
    {
        [ExportToolButton("Add Point")]
        Callable addPoint => Callable.From(AddPoint);
        [ExportToolButton("Construct")]
        Callable construct => Callable.From(Construct);
        [ExportToolButton("Reset")]
        Callable reset => Callable.From(Reset);
        VoronoiDiagram vd;
        override public void _Ready()
        {
            vd = new VoronoiDiagram();
        }

        public void AddPoint()
        {
            vd.AddPoint(new Vector2I(100, 100));
        }

        public void Construct()
        {
            vd.Construct();
        }

        public void Reset()
        {
            vd = new VoronoiDiagram();
        }
    }
}