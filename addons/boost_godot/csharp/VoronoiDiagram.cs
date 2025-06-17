using Godot;

namespace BoostGodot.csharp
{
    public class VoronoiDiagram
    {
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
            instance.Call("addPoint", point);
        }

        public void Construct()
        {
            if (instance == null)
            {
                GD.PrintErr("VoronoiDiagram instance is not initialized.");
                return;
            }
            instance.Call("construct");
        }
    }
}