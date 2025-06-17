using System;
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
        [ExportToolButton("Add Segment")]
        Callable addSegment => Callable.From(AddSegment);
        [ExportToolButton("Construct")]
        Callable construct => Callable.From(Construct);
        [ExportToolButton("Print Diagram")]
        Callable printDiagram => Callable.From(vd.PrintDiagram);
        [ExportToolButton("Reset")]
        Callable reset => Callable.From(Reset);
        private VoronoiDiagram vd;
        private Random random = new Random();

        override public void _Ready()
        {
            vd = new VoronoiDiagram();
        }

        public void AddPoint()
        {
            vd.AddPoint(new Vector2I(randNum(), randNum()));
        }

        public void AddSegment()
        {
            vd.AddSegment(new Rect2I(
                new Vector2I(randNum(), randNum()),
                new Vector2I(randNum(), randNum())));
        }

        public void Construct()
        {
            vd.Construct();
        }

        public void Reset()
        {
            vd = new VoronoiDiagram();
        }

        private int randNum()
        {
            return 100 - random.Next(201);
        }
    }
}