#include <iostream>
#include "Matrix.h"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Matrix A = Matrix(3, 3);
    cin >> A;
    Matrix b = Matrix(3, 1);
    cin >> b;
    A.Show();
    b.Show();
    b.insert(2, 1, 666);
    b.Show();
    //Matrix x = Matrix::Solve(A, b);
    //x.Show();
    return 0;
}
