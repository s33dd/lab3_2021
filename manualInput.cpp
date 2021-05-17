#include "manualInput.h"

void ManualInput::Input(Matrix &matrix) {
	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			std::cout << "Введите элемент матрицы:" << std::endl;
			matrix.m_matrix[i][j] = GetInput<int>();
		}
	}
}

int InputRowsSize(void) {
	std::cout << "Введите количество строк матрицы:" << std::endl;
	std::cout << "При вводе дробного числа будет взята только его целая часть." << std::endl;
	int rows = GetInput<int>();
	return rows;
}

int InputColumnsSize(void) {
	std::cout << "Введите количество столбцов матрицы:" << std::endl;
	std::cout << "При вводе дробного числа будет взята только его целая часть." << std::endl;
	int columns = GetInput<int>();
	return columns;
}