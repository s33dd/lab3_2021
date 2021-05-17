#include "manualInput.h"

void ManualInput::Input(Matrix &matrix) {
	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			std::cout << "������� ������� �������:" << std::endl;
			matrix.m_matrix[i][j] = GetInput<int>();
		}
	}
}

int InputRowsSize(void) {
	std::cout << "������� ���������� ����� �������:" << std::endl;
	std::cout << "��� ����� �������� ����� ����� ����� ������ ��� ����� �����." << std::endl;
	int rows = GetInput<int>();
	return rows;
}

int InputColumnsSize(void) {
	std::cout << "������� ���������� �������� �������:" << std::endl;
	std::cout << "��� ����� �������� ����� ����� ����� ������ ��� ����� �����." << std::endl;
	int columns = GetInput<int>();
	return columns;
}