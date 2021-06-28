#include<iostream>

using namespace std;

class Rectangle {
private:
  float length, width;
public:
  Rectangle (float l = 1.0, float w = 1.0) : length(l), width(w) {}
  float area () {
    return length * width;
  }
  float perimeter () {
    return 2 * (length + width);
  }
  void set() {
    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    if (length >= 1.0 and length <= 20.0 and width >= 1.0 and width <= 20.0) {

    } else {
      cout << "Invalid parameters!";
      exit(0);
    }
  }
  void get() {
    cout << "Length: " << length << "\n";
    cout << "Width: " << width << "\n";
    cout << "Area: " << area() << "\n";
    cout << "Perimeter: " << perimeter() << "\n";
  }
};

int main() {
  Rectangle r;
  r.get();
  r.set();
  r.get();
}
