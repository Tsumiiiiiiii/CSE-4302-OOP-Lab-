#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 10; 

template<class T>
class safearay {
private:
  T arr[LIMIT];
public:
  T& operator [](int n) { //note: return by reference
    if(n< 0 || n>=LIMIT) {
      cout << "\nIndex out of bounds";
      exit(1);
    }
    return arr[n];
  }
};

int main() {

  safearay<int> sa1;
  for(int i = 0; i < LIMIT; i++) 
    sa1[i] = i; 
  for(int i = 0; i < LIMIT; i++) {
    int temp1 = sa1[i];
    cout << "Element " << i << " is " << temp1 << "\n";
  }

  safearay<double> sa2;
  for(int i=0;i<LIMIT;i++) {
    sa2[i]= i * 0.5;
  }
  for(int i=0; i<LIMIT; i++) {
    cout << "Element " << i << " is " << sa2[i] << "\n";
  }
  return 0;
}
