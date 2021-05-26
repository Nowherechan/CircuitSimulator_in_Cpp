//
// Created by Z- on 2021/5/15.
//

#include "Matrix.h"
#include "pch.h"
using std::endl;
using std::cout;
using std::istream;
const double EPS = 1e-10;

void Matrix::initialize()
{
    p = new double*[rows_num];
    for (int i = 0; i < rows_num; i++) {
        p[i] = new double[cols_num];
    }
}

Matrix::Matrix(int rows, int cols)//声明一个矩阵，数值全为0
{
    rows_num = rows;
    cols_num = cols;
    initialize();
    for (int i = 0; i < rows_num; i++) {
        for (int j = 0; j < cols_num; j++) {
            p[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows_num; i++) {
        delete[] p[i];
    }
    delete[] p;
}

Matrix& Matrix::operator=(const Matrix &m)
{
    if (this == &m) return *this;

    if (rows_num != m.rows_num || cols_num != m.cols_num) {
        for (int i = 0; i < rows_num; i++) {
            delete[] p[i];
        }
        delete[] p;

        rows_num = m.rows_num;
        cols_num = m.cols_num;
        initialize();
    }

    for (int i = 0; i < rows_num; i++) {
        for (int j = 0; j < cols_num; j++) {
            p[i][j] = m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix &m)
{
    for (int i = 0; i < rows_num; i++) {
        for (int j = 0; j < cols_num; j++) {
            p [i][j] += m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix &m)
{
    for (int i = 0; i < rows_num; i++) {
        for (int j = 0; j < cols_num; j++) {
            p [i][j] -= m.p[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix &m)
{
    Matrix temp(rows_num, m.cols_num);
    for (int i = 0; i < temp.rows_num; i++) {
        for (int j = 0; j < temp.rows_num; i++) {
            for (int k = 0; k < cols_num; k++) {
                temp.p[i][j] += (p[i][k] * m.p[k][j]);
            }
        }
    }
    *this = temp;
    return *this;
}

Matrix Matrix::Solve(const Matrix &vA, const Matrix &vb)//解方程Ax=b
{
    Matrix A(vA.rows_num, vA.cols_num);
    Matrix b(vb.rows_num, vb.cols_num);
    A = vA;
    b = vb;
    for (int i = 0; i < A.rows_num; i++) {
        if (A.p[i][i] == 0) {
            cout << "ERROR !" << endl;
        }
        for (int j = i + 1; j < A.rows_num; j++) {
            for (int k = i + 1; k < A.cols_num; k++) {
                A.p[j][k] -= A.p[i][k] * (A.p[j][i] / A.p[i][i]);
                if (abs(A.p[j][k]) < EPS)
                    A.p[j][k] = 0;
            }
            b.p[j][0] -= b.p[i][0] * (A.p[j][i] / A.p[i][i]);
            if (abs(A.p[j][0]) < EPS)
                A.p[j][0] = 0;
            A.p[j][i] = 0;
        }
    }

    Matrix x(b.rows_num, 1);
    x.p[x.rows_num - 1][0] = b.p[x.rows_num - 1][0] / A.p[x.rows_num -1][x.rows_num - 1];
    if (abs(x.p[x.rows_num -1][0]) < EPS)
        x.p[x.rows_num - 1][0] = 0;
    for (int i = x.rows_num - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < x.rows_num; j++) {
            sum += A.p[i][j] * x.p[j][0];
        }
        x.p[i][0] = (b.p[i][0] - sum) / A.p[i][i];
        if (abs(x.p[i][0]) < EPS)
            x.p[i][0] = 0;
    }

    return x;
}

void Matrix::Show() const
{
    for (int i = 0; i < rows_num; i++) {
        for (int j = 0; j < cols_num; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

istream& operator>>(istream& is, Matrix& m)
{
    for (int i = 0; i < m.rows_num; i++) {
        for (int j = 0; j < m.cols_num; j++) {
            is >> m.p[i][j];
        }
    }
    return is;
}

void Matrix::insert_num(int row, int col, double num)
{
    if (row > rows_num || col > cols_num) {
        cout << "ERROR !" << endl;
    }
    p[row - 1][col - 1] = num;
}

double  Matrix::get_num(int row, int col)
{
    if (row > rows_num || col > cols_num) {
        cout << "ERROR !" << endl;
    }
    return p[row - 1][col - 1];
}

int Matrix::get_rows_num() const { return rows_num; }

int Matrix::get_cols_num() const { return cols_num; }

void Matrix::add_Row()
{

    Matrix temp = Matrix(rows_num + 1, cols_num);
    for (int r = 1; r <= rows_num; r++)
        for (int c = 1; c <= cols_num; c++) {
            temp.insert_num(r, c, get_num(r, c));
        }
    for (int c = 1; c <= cols_num; c++) {
        temp.insert_num(rows_num + 1, c, 0);
    }
    *this = temp;

}

void Matrix::add_Col()
{
    Matrix temp = Matrix(rows_num, cols_num + 1);
    for (int r = 1; r <= rows_num; r++)
        for (int c = 1; c <= cols_num; c++) {
            temp.insert_num(r, c, get_num(r, c));
        }
    for (int r = 1; r <= rows_num; r++) {
        temp.insert_num(r, cols_num + 1, 0);
    }
    *this = temp;

}