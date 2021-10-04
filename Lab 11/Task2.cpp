#include<bits/stdc++.h>

using namespace std;

const int sz = 50;
const int mx = 100;

enum employee_type {tmanager, tlaborer};

class employee {
private:
  char name[sz];
  int long number;
  static int n;
  static employee* arrap[];
public:
  virtual employee_type get_type(); 
  static void read();
  static void write();
};

int employee::n;
employee* employee::arrap[mx];

class manager : public employee {
private:
  char title[sz];
  double dues;
};

class laborer : public employee {
private:
  char role[sz];
  char shift[10];
  double dues;
};

employee_type employee::get_type() {
  if(typeid(*this) == typeid(manager) )
    return tmanager;
  else if( typeid(*this)==typeid(laborer) )
    return tlaborer;
  else
    cerr << "\nBad type\n";
  return tmanager;
}

void employee::write() {
  int size;
  //cout << “Writing “ << n << “ employees.\n”;
  ofstream ouf; //open ofstream in binary
  employee_type etype; //type of each employee object
  ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
  if(!ouf)
    { cout << "\nCan’t open file\n"; return; }
  for(int j=0; j<n; j++) { //for every employee object get its type
    etype = arrap[j]->get_type(); //write type to file
    ouf.write( (char*)&etype, sizeof(etype) );
    switch(etype)  {//find its size 
      case tmanager: size=sizeof(manager); break;
      case tlaborer: size=sizeof(laborer); break;
    } //write employee object to file
  ouf.write( (char*)(arrap[j]), size );
  if(!ouf)
    { cout << "\nCan’t write to file\n"; return; }
  }
}

void employee::read() {
  int size; //size of employee object
  employee_type etype; //type of employee
  ifstream inf; //open ifstream in binary
  inf.open("EMPLOY.DAT", ios::binary);
  if(!inf)
    {cout << "\nFailed to open file\n" ;return; }
  n = 0; //no employees in memory yet
  while(true) { //read type of next employee
    inf.read( (char*)&etype, sizeof(etype) );
    if(inf.eof() ) //quit loop on eof
      break;
    if(!inf) //error reading type
      { cout << "\nCan’t read type from file\n"; return; }
    switch(etype) { //make new employee
      case tmanager: //of correct type
        arrap[n] = new manager;
        size = sizeof(manager);
        break;
      case tlaborer:
        arrap[n] = new laborer;
        size = sizeof(laborer);
        break;
      default: cout << "\nUnknown type in file\n"; return;
    } //read data from file into it
  inf.read( (char*)arrap[n], size );
  if(!inf) //error but not eof
    { cout << "\nCan’t read data from file\n"; return; }
  n++; //count employee
  } //end while
  cout << "Reading “ << n << “ employees\n";
}

int main() {
  
}
