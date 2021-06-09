#include<iostream>

using namespace std;

class RationalNumber {
private:
  int numerator, denominator;
public:
  void assign(int _numerator, int _denominator) {
    if (_denominator == 0) {
      cout << "ERROR : DENOMINATOR CAN'T BE 0 !";
      exit(0);
    } else {
      numerator = _numerator;
      denominator = _denominator;
    }
  }

  double convert() {
    return numerator / (double) denominator;
  }

  void invert() {
    swap(numerator, denominator);
  }

  void print() {
    cout << "The Rational Number is " << numerator << "/" << denominator << "\n";
  }
};

int main() {
  RationalNumber x;
  x.assign(5, 0);
  cout << x.convert() << "\n";
  x.print();
  x.invert();
  cout << x.convert() << "\n";
  x.print();
}
