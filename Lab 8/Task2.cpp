#include<iostream>

using namespace std;

class Seat {
protected:
  bool pleasant, comfy, seatWarmer;
public:
  Seat(bool _pleasant = false, bool _comfy = false, bool _seatWarmer = false) : pleasant(_pleasant), comfy(_comfy), seatWarmer(_seatWarmer) {}
  void getSeat() const {
    cout << "Showing seat info : ";
    cout << pleasant << " " << comfy << " " << seatWarmer << "\n";
  }
  void setSeat() {
    cout << "Enter seat info: ";
    cin >> pleasant >> comfy >> seatWarmer;
  }
};

class Wheel {
protected:
  double circumference;
public:
  Wheel(double _circumference = 0) : circumference(_circumference) {}
  void getWheel() const {
    cout << "Showing wheel info : ";
    cout << circumference << "\n";
  }
  void setWheel() {
    cout << "Enter wheel info: ";
    cin >> circumference;
  }
};

class Engine {
protected:
  double maxFCR, maxEPR, avgRPM;
public:
  Engine (double _maxFCR = 0, double _maxEPR = 0, double _avgRPM = 0) : maxFCR(_maxFCR), maxEPR(_maxEPR), avgRPM(_avgRPM) {}
  void getEngine() const {
    cout << "Showing engine info : ";
    cout << maxFCR << " " << maxEPR << " " << avgRPM << "\n";
  }
  void setEngine() {
    cout << "Enter Engine info: ";
    cin >> maxFCR >> maxEPR >> avgRPM;
  }
};

class Door {
protected:
  string openingWay;
public:
  Door(string _openingWay = "") : openingWay(_openingWay) {}
  void getDoor() const {
    cout << "Showing door info : ";
    cout << openingWay << "\n";
  }
  void setDoor() {
    cout << "Enter door info: ";
    cin >> openingWay;
  }
};

class Car : public Seat, public Wheel, public Engine, public Door {
private:
  double max_accelaration, fuel_capacity;
public:
  Car(double _max_accelaration = 0, double _fuel_capacity = 0) : max_accelaration(_max_accelaration), fuel_capacity(_fuel_capacity) {}
  void setCar() {
    cout << "Enter car info: ";
    cin >> max_accelaration >> fuel_capacity;
  }
  void getCar() const {
    cout << "Car info: ";
    cout << max_accelaration << "\n";
  }
  void get() const{
    cout << "All the relevant info per category:\n";
    getSeat();
    getWheel();
    getEngine();
    getDoor();
    getCar();
  }
  void set() {
    cout << "Enter all the relevant info as requested:\n";
    setSeat();
    setWheel();
    setEngine();
    setDoor();
  }
};

int main() {
  Car Lambo(14.7, 714714.14);
  Lambo.set();
  Lambo.get();
  return 0;
}
