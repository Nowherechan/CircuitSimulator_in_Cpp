#include <iostream>
#include "Matrix.h"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Matrix A = Matrix(3, 3);
    cin >> A;
    Matrix b = Matrix(3, 1);
    cin >> b;
    cout << "A = " << endl;
    A.Show();
    cout << "b = " << endl;
    b.Show();
    Matrix x = Matrix::Solve(A, b);
    cout << "x = " << endl;
    x.Show();
    cout << "b = " << endl;
    b.Show();
    b.insert(2, 1, 666);
    cout << "b = " << endl;
    b.Show();
    return 0;
}
