#include<iostream>
#include<cmath>

using namespace std;

const double pi = acos(-1);

class Shape {
protected:
  string name;
  int dimension;
public:
  Shape(string _name = "", int _dimension = 0) : name(_name), dimension(_dimension) {}
  void whoami() {
    cout << "My name is " << name << " and my dimension is " << dimension << "\n";
  }
};

class twoDimensionalShape : public Shape {
protected:
  double area, perimeter;
public:
  twoDimensionalShape() : area(0), perimeter(0) {
    dimension = 2;
  }
};

class threeDimensionalShape : public Shape {
protected:
  double area, volume;
public:
  threeDimensionalShape() : area(0), volume(0) {
    dimension = 3;
  }
};

class Rectangle : public twoDimensionalShape {
private:
  double length, breadth;
public:
  Rectangle(double _length = 0, double _breadth = 0) : length(_length), breadth(_breadth) {
    name = "Rectangle";
  }
  double area() {
    return length * breadth;
  }
  double perimeter() {
    return 2 * (length + breadth);
  }
  void get() const {
    cout << "The sides of the rectangle : ";
    cout << length << " " << breadth << "\n";
  }
  void set() {
    cout << "Enter sides of the rectangle : ";
    cin >> length >> breadth;
  }
};

class Square : public twoDimensionalShape {
private:
  double side;
public:
  Square(double _side = 0) : side(_side) {
    name = "Square";
  }
  double area() {
    return side * side;
  }
  double perimeter() {
    return 4 * side;
  }
  void get() const {
    cout << "The side of the square : ";
    cout << side << "\n";
  }
  void set() {
    cout << "Enter side of the square : ";
    cin >> side;
  }
};

class Triangle : public twoDimensionalShape {
private:
  double a, b, c;
public:
  Triangle(double _a = 0, double _b = 0, double _c = 0) : a(_a), b(_b), c(_c){
    name = "Triangle";
  }
  double area() {
    double s = (a + b + c) / 2;
    s = s * (s - a) * (s - b) * (s - c);
    return sqrt(s);
  }
  double perimeter() {
    return a + b + c;
  }
  void get() const {
    cout << "The sides of the triangles : ";
    cout << a << " " << b << " " << c << "\n";
  }
  void set() {
    cout << "Enter sides of the triangle : ";
    cin >> a >> b >> c;
  }
};

class Circle : public twoDimensionalShape {
private:
  double radius;
public:
  Circle(double _radius = 0) : radius(_radius) {
    name = "Circle";
  }
  double area() {
    return pi * radius * radius; 
  }
  double perimeter() {
    return 2 * pi * radius;
  }
  void get() const {
    cout << "The radius of the circle is : ";
    cout << radius << "\n";
  }
  void set() {
    cout << "Enter the radius of the circle : ";
    cin >> radius;
  }
};

class Cube : public threeDimensionalShape {
private :
  double edge;
public:
  Cube(double _edge = 0) : edge(_edge) {
    name = "Cube";
  }
  double area() {
    return 6 * edge * edge;
  }
  double volume() {
    return edge * edge * edge;
  }
  void get() const {
    cout << "The edges of the cube is : ";
    cout << edge << "\n";
  }
  void set() {
    cout << "Enter the edge of the cube : ";
    cin >> edge;
  }
};

class Parallelepiped : public threeDimensionalShape {
private:
  double a, b, c;
public:
  Parallelepiped(double _a = 0, double _b = 0, double _c = 0) : a(_a), b(_b), c(_c) {
    name = "Parallelepiped";
  }
  double area() {
    return 2 * (a * b + b * c + c * a);
  }
  double volume() {
    return a * b * c;
  }
  void get() const {
    cout << "The edges of the parallelepiped is : ";
    cout << a << " " << b << " " << c << "\n";
  }
  void set() {
    cout << "Enter the edges of the parallelepiped : ";
    cin >> a >> b >> c;
  }
};

class Sphere : public threeDimensionalShape {
private:
  double radius;
public:
  Sphere(double _radius = 0) : radius(_radius) {
    name = "Sphere";
  }
  double area() {
    return 4 * pi * radius * radius;
  }
  double volume() {
    return (4 / 3.0) * pi * radius * radius * radius; 
  }
  void get() const {
    cout << "The radius of the sphere is : ";
    cout << radius << "\n";
  }
  void set() {
    cout << "Enter the radius of the sphere : ";
    cin >> radius;
  }
};

class Cylinder : public threeDimensionalShape {
private:
  double height, radius;
public:
  Cylinder(double _height = 0, double _radius = 0) : height(_height), radius(_radius) {
    name = "Cylinder";
  }
  double area() {
    return 2 * pi * radius * (height + radius);
  }
  double volume() {
    return pi * radius * radius * height;
  }
  void get() const {
    cout << "The height and radius of the cylinder is : ";
    cout << height << " " << radius << "\n";
  }
  void set() {
    cout << "Enter the height of the cylinder : ";
    cin >> height >> radius;
  }
};

int main() {
  Rectangle r;
  r.set();
  r.get();
  cout << r.area() << " " << r.perimeter() << "\n";
  Triangle t;
  t.set();
  t.get();
  cout << t.area() << " " << t.perimeter() << "\n";
  Square sq;
  sq.set();
  sq.get();
  cout << sq.area() << " " << sq.perimeter() << "\n";
  Circle cr;
  cr.set();
  cr.get();
  cout << cr.area() << " " << cr.perimeter() << "\n";
  Cube c;
  c.set();
  c.get();
  cout << c.area() << " " << c.volume() << "\n";
  Parallelepiped pp;
  pp.set();
  pp.get();
  cout << sq.area() << " " << pp.volume() << "\n";
  Sphere s;
  s.set();
  s.get();
  cout << s.area() << " " << s.volume() << "\n";
  Cylinder cd;
  cd.set();
  cd.get();
  cout << cd.area() << " " << cd.volume() << "\n";
}
