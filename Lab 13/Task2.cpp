#include<bits/stdc++.h>

using namespace std;

namespace foo {
  int x = 14; // x defined here
}

namespace my_namespace {
  int x = 7; // x defined here too
}

int main() {
  // since the two x are defined in different namespaces, hence, they can have different values without causing any error
  cout << foo::x << "\n"; 
  cout << my_namespace::x;
}
