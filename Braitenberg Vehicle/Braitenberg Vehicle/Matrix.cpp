#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(int r, int c) {
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

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &m) {
	row = m.row;
	col = m.col;

	matrix = m.matrix;
}

template <typename T>
void Matrix<T>::print() {
	for (int i = 0; i < row; ++i) {
		printf("|");
		for (int j = 0; j < col; ++j) {
			printf(" %d", matrix[i][j]);
		}
		printf(" |\n");
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator* (const Matrix<T> &m) {
	Matrix<T> prod(row, m.col);
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

template <typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix &m) {
	row = m.row;
	col = m.col;
	matrix = m.matrix;

	return *this;
}

template Matrix<int>;
template Matrix<double>;