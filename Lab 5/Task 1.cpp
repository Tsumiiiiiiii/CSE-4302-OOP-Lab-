#include<iostream>

using namespace std;

inline min (int a, int b) {
  return a < b ? a : b;
}

class Counter {
private:
  int count, inc_steps;
public:
  Counter(int _count = 0, int _inc_steps = 0) : count(_count), inc_steps(_inc_steps) {}

  ~Counter() {}

  void setIncrementStep(int step_val = 1) {
    if (step_val < 0) {
      printf("Negative value not allowed!");
      exit(0);
    }
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
  Counter operator + (Counter b) {
    Counter temp;
    temp.count = count + b.count;
    temp.inc_steps = min(inc_steps, b.inc_steps);
    return temp;
  }
  Counter operator += (Counter c) {
    Counter temp;
    temp.count = count + c.count;
    temp.inc_steps = min(inc_steps, c.inc_steps);
    return temp;
  }

  Counter operator + (int val) {
    return Counter(count+val, inc_steps);
  }

  friend Counter operator + (const int& val, const Counter& c);

  Counter operator ++() {
    count += inc_steps;
    return Counter(count,inc_steps);
  }

  Counter operator ++(int) {
    count += inc_steps;
    return Counter(count, inc_steps);
  }

};

Counter operator + (const int& val, const Counter& c) {
  return Counter(c.count + val,c. inc_steps);
}

int main() {
  Counter cnt;
  cnt.setIncrementStep(10);
  cout << "Count : " <<  cnt.getCount() << "\n";
  cout << "Incrementing\n";
  cnt.increment();
  cout << "Count : " << cnt.getCount() << "\n";
  cout << "Resetting\n";
  cnt.resetCount();
  cout << "Count : " << cnt.getCount() << "\n";
  Counter c(20, 6);
  Counter p = cnt + c;
  cout << (p.getCount()) << "\n";
  Counter rs = 5 + p;
  rs = p + 5;
  cout << (rs.getCount()) << "\n"; 
  rs++;
  cout << (rs.getCount()) << "\n";
  ++rs;
  cout << (rs.getCount()) << "\n";
  Counter x(3, -6);
  return 0;
}
