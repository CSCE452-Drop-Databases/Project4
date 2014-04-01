#pragma once

#include "stdafx.h"

static const int MATRIX_DEFAULT_ROW = 2;
static const int MATRIX_DEFAULT_COLUMN = 2;

template <typename T>
class Matrix {
private:
	int row, col;
	std::vector<std::vector<T> > matrix;

public:
	Matrix(int r = MATRIX_DEFAULT_ROW, int c = MATRIX_DEFAULT_COLUMN);
	Matrix(const Matrix<T> &m);

	void print();

	std::vector<T>& operator[] (int i) { return matrix[i]; }
	Matrix operator* (const Matrix &m);
	Matrix& operator= (const Matrix &m);

};

