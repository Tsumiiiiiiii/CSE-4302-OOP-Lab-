#include<iostream>

using namespace std;

class Counter {
private:
  int count, inc_steps;
public:
  Counter() : count(0), inc_steps(0) {}

  void setIncrementStep(int step_val) {
    inc_steps = step_val;
  }

  int getCount() {
    return count;
  }

  void increment() {
    count += inc_steps;
  }

  void resetCount() {
    count = 0;
  }
};

int main() {
  Counter cnt;
  cnt.setIncrementStep(10);
  cout << cnt.getCount() << "\n";
  cnt.increment();
  cout << cnt.getCount() << "\n";
  cnt.resetCount();
  cout << cnt.getCount() << "\n";
}
