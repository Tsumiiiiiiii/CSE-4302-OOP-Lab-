#include<iostream>

using namespace std;

class Calculator {
private:
  int val;
public:
  Calculator() : val(0) {}
  Calculator(int _val) : val(_val) {}
  int getValue() {return val;}
  void setValue(int _val) {val = _val;}
  void add(int Value) {val += Value;}
  void subtract(int Value) {val -= Value;}
  void multiply(int Value) {val *= Value;}
  void divideBy(int Value) {
    if (Value == 0) {
      cout << "Error : divide by 0 is undefined.\n";
    } else {
      val /= Value;
    }
  };
  void clear() {val = 0;}
  void display() {cout << "Calculator display: " << val << "\n";}
  ~Calculator() {cout << "Calculator object is destroyed.\n";}
};

int main() {
  Calculator c;
  c.add(10);
  c.display();
  c.subtract(8);
  c.display();
  c.multiply(4);
  c.display();
  c.divideBy(2);
  c.display();
  c.clear();
  c.display();
}
