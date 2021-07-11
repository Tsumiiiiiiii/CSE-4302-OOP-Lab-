#include<iostream>

using namespace std;

class Matrix3D {
private:
  double mat[3][3];
public:
  Matrix3D() {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) mat[i][j] = 0;
    }
  }

  Matrix3D(double a[3][3]) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) mat[i][j] = a[i][j];
    }
  }

  ~Matrix3D() {}

  void setMatrix () {
    cout << "Input the matrix: \n";
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) cin >> mat[i][j];
    }
  }

  void show() {
    cout << "The matrix is: \n";
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) cout << mat[i][j] << " ";
      cout << "\n";
    }
  }

  double det () {
    double DET = 0;
    for(int i=0;i<3;i++) {
      DET = DET + (mat[0][i]* (mat[1][(i + 1) % 3] * mat[2][( i + 2) % 3] - mat[1][(i + 2) % 3]*mat[2][(i + 1) % 3]));
    }
    return DET;
  }

  Matrix3D inverse() {
    Matrix3D ret;
    double DET = det();
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        ret.mat[i][j] = ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / DET;
      }
    }
    return ret;
  }

  Matrix3D operator + (Matrix3D b) {
    Matrix3D ret;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        ret.mat[i][j] = mat[i][j] + b.mat[i][j];
      }
    }
    return ret;
  }

  Matrix3D operator - (Matrix3D b) {
    Matrix3D ret;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        ret.mat[i][j] = mat[i][j] - b.mat[i][j];
      }
    }
    return ret;
  }

  Matrix3D operator * (Matrix3D b) {
    Matrix3D ret, a(mat);
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
        for(int k = 0; k < 3; ++k) {
          ret.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        }
      }
    }
    return ret;
  }

};

int main() {
  double p[3][3] = {{1,2,3}, {14,15,34}, {3,6,15}};
  double q[3][3] = {{5, 6, 7}, {69, 420, 14}, {7, 14, 417}};
  Matrix3D a(p), b(q);
  Matrix3D c = a + b;
  Matrix3D d = a - b;
  Matrix3D e = a * b;
  Matrix3D f = a.inverse();
  c.show();
  d.show();
  e.show();
  f.show(); 
}
