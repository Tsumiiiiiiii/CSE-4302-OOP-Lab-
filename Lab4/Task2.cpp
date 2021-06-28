#include<iostream>

using namespace std;

class Flight {
private:
  int Flight;
  string Destination;
  float Distance, MaxFuelCapacity, Need;
  float calFuel() {
    float ret;
    if (Distance <= 1000.0) ret = 500;
    else if (Distance > 2000.0) ret = 2200;
    else ret = 1100;
    if (ret > MaxFuelCapacity) {
      cout << "Not sufficient Fuel Capacity for this flight";
      exit(0);
    } else {
      cout << "Fuel Capacity is fit for this flight\n";
      return ret;
    }
  }
public:
  void FeedInfo() {
    cout << "Flight Number: ";
    cin >> Flight;
    cout << "Destination: ";
    cin >> Destination;
    cout << "Distance: ";
    cin >> Distance;
    cout << "Maximum Capacity: ";
    cin >> MaxFuelCapacity;
    Need = calFuel();
  }
  void ShowInfo() {
    cout << "Flight Number: " << Flight << "\n";
    cout << "Destination: " << Destination << "\n";
    cout << "Distance: " << Distance << "\n";
    cout << "Maximum Capacity: " << MaxFuelCapacity << "\n";
    cout << "Fuel Needed: " << Need << "\n";
  }
};

int main() {
  Flight f;
  f.FeedInfo();
  f.ShowInfo();
}
