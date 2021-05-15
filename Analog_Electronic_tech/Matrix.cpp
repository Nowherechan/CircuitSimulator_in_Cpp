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