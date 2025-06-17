using Godot;
using Godot.NativeInterop;

namespace BoostGodot.csharp
{
    public class VoronoiDiagram
    {
        private readonly StringName ADD_POINT = new StringName("addPoint");
        private readonly StringName ADD_SEGMENT = new StringName("addSegment");
        private readonly StringName CONSTRUCT = new StringName("construct");
        private readonly StringName PRINT_DIAGRAM = new StringName("printDiagram");
        private GodotObject instance;
        public VoronoiDiagram()
        {
            instance = (GodotObject)ClassDB.Instantiate("VoronoiDiagram");
        }

        public void AddPoint(Vector2I point)
        {
            if (instance == null)
            {
                GD.PrintErr("VoronoiDiagram instance is not initialized.");
                return;
            }
            instance.Call(ADD_POINT, point);
        }

        public void AddSegment(Rect2I p)
        {
            if (instance == null)
            {
                GD.PrintErr("VoronoiDiagram instance is not initialized.");
                return;
            }
            instance.Call(ADD_SEGMENT, p);
        }

        public void Construct()
        {
            if (instance == null)
            {
                GD.PrintErr("VoronoiDiagram instance is not initialized.");
                return;
            }
            instance.Call(CONSTRUCT);
        }

        public void PrintDiagram()
        {
            if (instance == null)
            {
                GD.PrintErr("VoronoiDiagram instance is not initialized.");
                return;
            }
            instance.Call(PRINT_DIAGRAM);
        }
    }
}