#include <iostream>
#include "Matrix.h"
using namespace std;
int main() {
    std::cout << "Test Program has started !" << std::endl;
    Matrix A = Matrix(3, 3);
    cout << "CIN 3x3 Matrix A" << endl;
    cin >> A;
    Matrix b = Matrix(3, 1);
    cout << "CIN 1x3 Vector B" << endl;
    cin >> b;
    cout << "A = " << endl;
    A.Show();
    cout << "b = " << endl;
    b.Show();
    Matrix x = Matrix::Solve(A, b);
    cout << "Solve Ax=b" << endl;
    cout << "x = " << endl;
    x.Show();
    cout << "A = " << endl;
    A.Show();
    cout << "b = " << endl;
    b.Show();
    //b.insert_num(2, 1, 666);
    //cout << "b = " << endl;
    //b.Show();
    cout << "b[2][1] = " << b.get_num(2, 1) << endl;
    A.add_Row();
    cout << "After add one row, A = " << endl;
    A.Show();
    A.add_Col();
    cout << "After add one column, A = " << endl;
    A.Show();
    b.add_Row();
    cout << "After add one row, b = " << endl;
    b.Show();

    A.insert_num(4,4,57);
    b.insert_num(4,1,57);
    cout << "-----------------" << endl;
    cout << "A = " << endl;
    A.Show();
    cout << "b = " << endl;
    b.Show();
    x = Matrix::Solve(A, b);
    cout << "Solve Ax=b" << endl;
    cout << "x = " << endl;
    x.Show();
    return 0;
}
