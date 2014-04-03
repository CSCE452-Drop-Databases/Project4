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
	Matrix(int r = MATRIX_DEFAULT_ROW, int c = MATRIX_DEFAULT_COLUMN) {
        if (r < MATRIX_DEFAULT_ROW || c < MATRIX_DEFAULT_COLUMN) {
            printf("ERROR :  Matrix Constructor :: Invalid Dimensions, default %ux%u \n", MATRIX_DEFAULT_ROW, MATRIX_DEFAULT_COLUMN);
            row = MATRIX_DEFAULT_ROW;
            col = MATRIX_DEFAULT_COLUMN;
        }
        else {
            row = r;
            col = c;
        }

        matrix = std::vector<std::vector<T> >(row, std::vector<T>(col));

    }

	Matrix(const Matrix<T> &m) {
        row = m.row;
        col = m.col;

        matrix = m.matrix;
    }

	void print() {
        for (int i = 0; i < row; ++i) {
            printf("|");
            for (int j = 0; j < col; ++j) {
                printf(" %d", matrix[i][j]);
            }
            printf(" |\n");
        }
    }

	std::vector<T>& operator[] (int i) { return matrix[i]; }

	Matrix operator* (const double s) {
		Matrix prod(row, col);
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				prod[i][j] = matrix[i][j] * s;
			}
		}
		return prod;
	}

	Matrix operator* (const Matrix &m) {
        Matrix prod(row, m.col);
        // checking dimensions
        // TODO: Actually throw a real exception
        if (col != m.row) {
            printf("Error: Matrices not compatible for multiplication\n");
            return prod;
        }

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < m.col; ++c) {
                for (int i = 0; i < col; ++i) {
                    prod.matrix[r][c] += matrix[r][i] * m.matrix[i][c];
                }
            }
        }

        return prod;
    }
	
    Matrix& operator= (const Matrix &m) {
        row = m.row;
        col = m.col;
        matrix = m.matrix;

        return *this;
    }

};

template <typename T>
Matrix<T> operator* (const double s, Matrix<T> m) {
	return m*s;
}