//
// Created by Z- on 2021/5/15.
//

#ifndef ANALOG_ELECTRONIC_TECH_MATRIX_H
#define ANALOG_ELECTRONIC_TECH_MATRIX_H
#include "pch.h"


class Matrix {
private:
    int rows_num, cols_num;
    double **p;
    void initialize();//初始化矩阵

public:
    Matrix(int, int);
    virtual ~Matrix();
    Matrix& operator=(const Matrix&);//复制
    Matrix& operator+=(const Matrix&);//矩阵的+=操作
    Matrix& operator-=(const Matrix&);//-=
    Matrix& operator*=(const Matrix&);//*=
    static Matrix Solve(const Matrix&, const Matrix&);//求解线性方程组Ax=b
    void Show() const;
    friend std::istream& operator>>(std::istream&, Matrix&);
    void insert(int row, int col, double num);

};


#endif //ANALOG_ELECTRONIC_TECH_MATRIX_H
