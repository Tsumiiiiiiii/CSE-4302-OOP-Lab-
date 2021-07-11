#include<iostream>
#include<cmath>

using namespace std;

class Coordinate {
private:
  float x, y;
public:
  Coordinate(float _x = 0, float _y = 0) : x(_x), y(_y) {}

  ~Coordinate() {}

  void show() {
    printf("(x, y) = (%.2f, %.2f)\n", x, y);
  }

  float getDistance(Coordinate c) {
    float t = (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y);
    return sqrt(t);
  }

  float getDistance() {
    Coordinate c(0, 0);
    return getDistance(c);
  }

  void move_x (float val) {
    x += val;
  }

  void move_y(float val) {
    y += val;
  }

  void move (float val) {
    move_x(val);
    move_y(val);
  }

  float dist (Coordinate a, Coordinate b) {
    float t = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt(t);
  }

  Coordinate operator ++ () {
    x += 1, y += 1;
    return Coordinate(x, y);
  } 

  Coordinate operator ++ (int) {
    Coordinate temp(x, y);
    x += 1, y += 1;
    return temp;
  }

  Coordinate operator -- () {
    x -= 1, y -= 1;
    return Coordinate(x, y);
  } 

  Coordinate operator -- (int) {
    Coordinate temp(x, y);
    x -= 1, y -= 1;
    return temp;
  }

  bool operator == (Coordinate c) {
    Coordinate temp(x, y);
    Coordinate org(0, 0);
    return dist(temp, org) == dist(c, org);
  }

  bool operator != (Coordinate c) {
    Coordinate temp(x, y);
    Coordinate org(0, 0);
    return dist(temp, org) != dist(c, org);
  }

  bool operator <= (Coordinate c) {
    Coordinate temp(x, y);
    Coordinate org(0, 0);
    return dist(temp, org) <= dist(c, org);
  }

  bool operator >= (Coordinate c) {
    Coordinate temp(x, y);
    Coordinate org(0, 0);
    return dist(temp, org) >= dist(c, org);
  }

  bool operator > (Coordinate c) {
    Coordinate temp(x, y);
    Coordinate org(0, 0);
    return dist(temp, org) > dist(c, org);
  }

  bool operator < (Coordinate c) {
    Coordinate temp(x, y);
    Coordinate org(0, 0);
    return dist(temp, org) < dist(c, org);
  }

};

int main() {
  Coordinate a(7.14, 6.9), b(14.7, 4.20);
  cout << a.getDistance(b) << "\n";
  a.move(4.78);
  a.show();
  a++;
  a.show();
  ++a;
  a.show();
  cout << (a == b);
  cout << (a <= b);
  return 0;
}
