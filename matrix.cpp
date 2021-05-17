#include "matrix.h"

Matrix::Matrix(int rows, int columns) {
	m_matrixColumns = columns;
	m_matrixRows = rows;
	m_matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		m_matrix[i] = new int[columns];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < m_matrixRows; i++) {
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
}

Matrix::Matrix(Matrix& matrix) {
	m_matrixColumns = matrix.m_matrixColumns;
	m_matrixRows = matrix.m_matrixRows;
	m_matrix = new int* [m_matrixRows];
	for (int i = 0; i < m_matrixRows; i++) {
		m_matrix[i] = new int[m_matrixColumns];
	}
	for (int i = 0; i < m_matrixRows; i++) {
		for (int j = 0; j < m_matrixColumns; j++) {
			m_matrix[i][j] = matrix.m_matrix[i][j];
		}
	}
}

int Matrix::GetElement(int row, int column) {
	return m_matrix[row][column];
}

void Matrix::SetElement(int row, int column, int number) {
	m_matrix[row][column] = number;
}