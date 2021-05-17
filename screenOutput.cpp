#include "screenOutput.h"

void ScreenOutput::MatrixOutput(Matrix &matrix) {
	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			std::cout.width(10);
			std::cout << matrix.m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void ScreenOutput::CompareTableOutput(int *compares, int *switches, std::string *names) {
	std::cout.width(13);
	std::cout << " " << "Сравнения: " << "Перестановки:" << std::endl;
	for (int i = 0; i < SORTS_QUANTITY; i++) {
		std::cout.width(13);
		std::cout << names[i];
		std::cout.width(7);
		std::cout << compares[i] << "       " << switches[i] << std::endl;
	}
}