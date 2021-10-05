#include <iostream>

using namespace std;

const int LIMIT = 10;

template<class T>
class safearay {
private:
  T a[LIMIT];
public:
  class OutOfBound {
  public:
    int idx;
    OutOfBound(int idx) : idx(idx) {}
  };
  T& operator [](int n) { //note: return by reference
    if( n< 0 || n>=LIMIT ) {
      throw OutOfBound(n);
    }
    return a[n];
  }
};

int main() {

  try {
    safearay<int> sa1;
    for(int i=0; i<LIMIT+5; i++) //insert elements
      sa1[i] = i; //*left* side of equal sign
    for(int i=0; i<LIMIT; i++) { //display elements
      int temp1 = sa1[i]; //*right* side of equal sign
      cout << "Element " << i << " is " << temp1 << endl;
    }

  }
  catch(safearay<int>::OutOfBound e) {
    cout<<"Out of Bound encountered at index : "<< e.idx <<endl;
  }


    return 0;
}
