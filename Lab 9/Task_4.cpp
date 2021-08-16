#include<iostream>

using namespace std;

class Furniture {
protected:
  int regularPrice, discountedPrice;
  string material, productName;
public:
  Furniture(int rp = 0, int dp = 0, string m = "", string pn = "") : regularPrice(rp), discountedPrice(dp), material(m), productName(pn) {}
  void set() {
    cout << "Product Name :";
    cin >> productName;
    cout << "Regular Price :"; 
    cin >> regularPrice;
    cout << "Discounted Price :";
    cin >> discountedPrice;
    cout << "Material :";
    cin >> material;
  }
  void get() {
    cout << "Product Name: " << productName << "\n";
    cout << "Regular Price :" << regularPrice << "\n";
    cout << "Discounted Price :" << discountedPrice << "\n";
    cout << "Material :" << material << "\n"; 
  }
  int getDP() {
    return discountedPrice;
  }
};

class Bed : public Furniture {
private:
  string bedSize;
public:
  Bed(string bs = "") : bedSize(bs) {
  }
  void setSize() {
    cout << "Bed Size: ";
    cin >> bedSize;
  }
  void setBed() {
    set();
    setSize();
  }
  void getSize() {
    cout << "Bed Size :" << bedSize << "\n";
  }
  void productDetails() {
    get();
    getSize();
  }
};

class Sofa : public Furniture {
private:
  string seatNumber;
public:
  Sofa(string sn = "") : seatNumber(sn) {}
  void setNumber() {
    cout << "Seat Number: ";
    cin >> seatNumber;
  }
  void setSofa() {
    set();
    setNumber();
  }
  void getSofa() {
    cout << "Seat Number :" << seatNumber << "\n";
  }
  void productDetails() {
    get();
    getSofa();
  }
};

class DiningTable : public Furniture {
private:
  string chairCount;
public:
  DiningTable(string cc = "") : chairCount(cc) {}
  void setCount() {
    cout << "Chair Count: ";
    cin >> chairCount;
  }
  void setDiningTable() {
    set();
    setCount();
  }
  void getCount() {
    cout << "Chair Count: " << chairCount << "\n";
  }
  void productDetails() {
    get();
    getCount();
  }
};

void order(Furniture** b1, Furniture** b2) {
  if ((*b1)->getDP() < (*b2)->getDP()) {
    Furniture* temp = *b1;
    *b1 = *b2;
    *b2 = temp;
  }
}

void bsort(Furniture** b, int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      order(b + i, b + j);
    }
  }
}

int main() {
  int n; cin >> n;
  Furniture* b[n];
  for (int i = 0; i < n; ++i) {
    b[i] = new Furniture;
    b[i]->set();
    cout << "\n";
  }
  bsort(b, n);
  cout << "The sorted array is: " << "\n";
  for (int i = 0; i < n; ++i) {
    cout << b[i]->getDP() << "\n";
  }
}
