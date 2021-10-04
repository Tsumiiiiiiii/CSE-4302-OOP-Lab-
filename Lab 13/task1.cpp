#include<bits/stdc++.h>

using namespace std;

int main() {
  int a[10];
  set <int> st;
  for (int i = 0; i < 20; ++i) {
    if (i & 1) st.insert(i); // if number is odd its inserted in the set
    else a[i / 2] = i; // if number is even its inserted in the array
  }
  vector <int> v(20); // vector of size 20
  merge(a, a+10, st.begin(), st.end(), v.begin());
  for (int i : v) cout << i << " "; // prints all the elements of vectors
  return 0;
}
