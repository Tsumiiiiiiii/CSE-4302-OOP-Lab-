#include<iostream>

using namespace std;

class shape {
public:
  virtual int area() = 0; // this is pure virtual function. It has been made pure to work as a placeholder
  virtual string name() = 0; // same for this
};

class rect : public shape {
  int a, b;
  string nm;
public:
  rect(int a = 0, int b = 0) : a(a), b(b) {
    nm = "rectangle";
  }
  int area() {return a * b;}
  string name() {return nm;}
};

class sqr : public shape{
  int a;
  string nm;
public:
  sqr(int a = 0) : a(a) {
    nm = "square";
  }
  int area() {
    return a * a;
  }
  string name() {return nm;}
};

int main() {
  shape *sp;
  rect r(7, 14);
  sqr s(714);
  sp = &r;
  cout << sp->area() << " " << sp->name() << "\n";
  sp = &s;
  cout <<  sp->area() << " " << sp->name() << "\n";
}

