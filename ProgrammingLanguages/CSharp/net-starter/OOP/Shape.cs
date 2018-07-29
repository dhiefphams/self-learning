using System;

// Only allow inheritence for class and interface
// Access visibility: public, protected, internal, private
// Override: must provide virtual or abstract in based class
// By default: class is inhert from System.Object class
namespace NetStarter.OOP.Inheritence
{
    /// the shape examples
    public abstract class Shape
    {
        public abstract double Area { get; }
        
        public abstract double Perimeter { get; }

        public override string ToString() => GetType().Name;

        public static double GetArea(Shape shape) => shape.Area;

        public static double GetPerimeter(Shape shape) => shape.Perimeter;
        public static void run()
        {
            Shape[] shapes = { new Rectangle(10, 12), new Square(5), new Circle(3) };
            foreach(var shape in shapes) {
                Console.WriteLine($"{shape}: area, {Shape.GetArea(shape)}; " +
                                  $"perimetr, {Shape.GetPerimeter(shape)}");
                var rect = shape as Rectangle;
                if (rect != null) {
                    Console.WriteLine($"\t Is Square: {rect.IsSquare()}, Diagonal: {rect.Diagonal}");
                    continue;
                }

                var square = shape as Square;
                if (square != null   ) {
                    Console.WriteLine($"\t Diaginal: {square.Diagonal}");
                }
            }
        }
    }

    public class Square: Shape
    {
        public double Side { get; }

        public Square(double length) {
            this.Side = length;
        }

        public override double Area => Math.Pow(Side, 2);
        public override double Perimeter => Side * 4;

        public double Diagonal => Math.Round(Math.Sqrt(2) * Side, 2);

    }

    public class Rectangle: Shape
    {
        public double Width { get; }

        public double Height { get; }

        public Rectangle(double width, double height)
        {
            this.Width = width;
            this.Height = height;
        }

        public override double Area => Width * Height;
        
        public override double Perimeter => 2 * Width + 2 * Height;

        public bool IsSquare() => Width == Height;
        
        public double Diagonal => Math.Round(Math.Sqrt(Math.Pow(Height, 2) + Math.Pow(Width, 2)), 2);
    }

    public class Circle: Shape
    {
        public double Radius { get; }
        public Circle(double radius)
        {
            this.Radius = radius;
        }

        public override double Area => Math.Round(Math.PI * Math.Pow(this.Radius, 2), 2);

        public override double Perimeter => Math.Round(Math.PI * 2 * this.Radius, 2);

        public double Cirumference => Perimeter;

        public double Diameter => this.Radius * 2;
    }
}