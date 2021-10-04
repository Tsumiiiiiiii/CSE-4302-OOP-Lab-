#include<bits/stdc++.h>

using namespace std;

template <class T>
T max (T* a, int sz) {
  T ret = a[0];
  for (int i = 1; i < sz; ++i) {
    if (a[i] > ret) ret = a[i];
  }
  return ret;
}

int main() {
  int ar[] = {5, 8, 3, 1, 6, 4};
  cout << max(ar, 6);
}
