#include "ISort.h"

BubbleSort::BubbleSort() {
	m_compareCounter = 0;
	m_switchCounter = 0;
}

void BubbleSort::SortMatrix(Matrix &matrix) {
	int temp = 0;
	m_compareCounter = 0;
	m_switchCounter = 0;

	for (m_compareCounter = 0; m_compareCounter < (matrix.m_matrixColumns * matrix.m_matrixRows - 1); m_compareCounter++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			for (int i = 0; i < matrix.m_matrixRows; i++) {
				if (i == matrix.m_matrixRows - 1) {
					continue;
				}
				if (matrix.m_matrix[i][j] < matrix.m_matrix[i + 1][j]) {
					m_switchCounter++;
					temp = matrix.m_matrix[i + 1][j];
					matrix.m_matrix[i + 1][j] = matrix.m_matrix[i][j];
					matrix.m_matrix[i][j] = temp;
				}
			}
		}
	}
}

void BubbleSort::SortNumber(Matrix &matrix) {
	char temp;
	std::string number;

	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			number = std::to_string(abs(matrix.m_matrix[i][j]));
			__int64 digits = (__int64)number.length();
			for (__int64 k = 0; k < digits; k++) {
				if (k == digits - 1) {
					continue;
				}
				m_compareCounter++;
				if (number[k] > number[k + 1]) {
					temp = number[k];
					number[k] = number[k + 1];
					number[k + 1] = temp;
					m_switchCounter++;
					if (matrix.m_matrix[i][j] < 0) {
						matrix.m_matrix[i][j] = -stoi(number);
					}
					else {
						matrix.m_matrix[i][j] = stoi(number);
					}
				}
			}
		}
	}
}

int BubbleSort::GetCompares(void){
	return m_compareCounter;
}

int BubbleSort::GetSwitches(void) {
	return m_switchCounter;
}

SelectionSort::SelectionSort() {
	m_compareCounter = 0;
	m_switchCounter = 0;
}

void SelectionSort::SortMatrix(Matrix &matrix) {
	int temp = 0;
	m_compareCounter = 0;
	m_switchCounter = 0;

	for (int j = 0; j < matrix.m_matrixColumns; j++) {
		for (int start = 0; start < matrix.m_matrixRows - 1; start++) {
			int biggest = start;
			for (int current = start + 1; current < matrix.m_matrixRows; current++) {
				m_compareCounter++;
				if (matrix.m_matrix[current][j] > matrix.m_matrix[biggest][j]) {
					biggest = current;
				}
			}
			if (start != biggest) {
				temp = matrix.m_matrix[start][j];
				matrix.m_matrix[start][j] = matrix.m_matrix[biggest][j];
				matrix.m_matrix[biggest][j] = temp;
				m_switchCounter++;
			}
		}
	}
}

void SelectionSort::SortNumber(Matrix &matrix) {
	char temp;
	std::string number;

	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			number = std::to_string(abs(matrix.m_matrix[i][j]));
			__int64 digits = (__int64)number.length();
			for (int start = 0; start < digits - 1; start++) {
				int smallest = start;
				for (int current = start + 1; current < digits; current++) {
					m_compareCounter++;
					if (number[current] < number[smallest]) {
						smallest = current;
					}
				}
				if (start != smallest) {
					temp = number[start];
					number[start] = number[smallest];
					number[smallest] = temp;
					m_switchCounter++;
					if (matrix.m_matrix[i][j] < 0) {
						matrix.m_matrix[i][j] = -stoi(number);
					}
					else {
						matrix.m_matrix[i][j] = stoi(number);
					}
				}
			}
		}
	}
}

int SelectionSort::GetCompares(void) {
	return m_compareCounter;
}

int SelectionSort::GetSwitches(void) {
	return m_switchCounter;
}

InsertionSort::InsertionSort() {
	m_compareCounter = 0;
	m_switchCounter = 0;
}

void InsertionSort::SortMatrix(Matrix &matrix) {
	int temp = 0;
	int compare = 0;
	m_compareCounter = 0;
	m_switchCounter = 0;

	for (int j = 0; j < matrix.m_matrixColumns; j++) {
		for (int i = 0; i < matrix.m_matrixRows - 1; i++) {
			compare = i + 1;
			temp = matrix.m_matrix[compare][j];
			for (int next = i + 1; next > 0; next--) {
				m_compareCounter++;
				if (matrix.m_matrix[next - 1][j] < temp) {
					m_switchCounter++;
					matrix.m_matrix[next][j] = matrix.m_matrix[next - 1][j];
					compare = next-1;
				}
			}
			matrix.m_matrix[compare][j] = temp;
		}
	}
}

void InsertionSort::SortNumber(Matrix &matrix) {
	char temp;
	__int64 compare = 0;
	std::string number;

	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			number = std::to_string(abs(matrix.m_matrix[i][j]));
			__int64 digits = (__int64)number.length();
			for (__int64 k = 0; k < digits - 1; k++) {
				compare = k + 1;
				temp = number[compare];
				for (__int64 next = k + 1; next > 0; next--) {
					m_compareCounter++;
					if (number[next - 1] > temp) {
						m_switchCounter++;
						number[next] = number[next - 1];
						compare = next - 1;
					}
				}
				number[compare] = temp;
			}
			if (matrix.m_matrix[i][j] < 0) {
				matrix.m_matrix[i][j] = -stoi(number);
			}
			else {
				matrix.m_matrix[i][j] = stoi(number);
			}
		}
	}
}

int InsertionSort::GetCompares(void) {
	return m_compareCounter;
}

int InsertionSort::GetSwitches(void) {
	return m_switchCounter;
}

ShellSort::ShellSort() {
	m_compareCounter = 0;
	m_switchCounter = 0;
}

void ShellSort::SortMatrix(Matrix &matrix) {
	int temp = 0;
	int distance = matrix.m_matrixRows;
	distance /= 2;
	m_compareCounter = 0;
	m_switchCounter = 0;

	while (distance > 0) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			for (int i = 0; i < matrix.m_matrixRows - distance; i++) {
				for (int k = i; k >= 0; k--) {
					m_compareCounter++;
					if (matrix.m_matrix[k][j] < matrix.m_matrix[k + distance][j]) {
						m_switchCounter++;
						temp = matrix.m_matrix[k + distance][j];
						matrix.m_matrix[k + distance][j] = matrix.m_matrix[k][j];
						matrix.m_matrix[k][j] = temp;
					}
				}

			}
		}
		distance /= 2;
	}
}

void ShellSort::SortNumber(Matrix &matrix) {
	char temp;
	std::string number;

	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			number = std::to_string(abs(matrix.m_matrix[i][j]));
			__int64 digits = (__int64)number.length();
			__int64 distance = digits;
			distance /= 2;
			while (distance > 0) {
				for (__int64 k = 0; k < digits - distance; k++) {
					for (__int64 z = k; z >= 0; z--) {
						m_compareCounter++;
						if (number[z] > number[z + distance]) {
							temp = number[z];
							number[z] = number[z + distance];
							number[z + distance] = temp;
						}
					}
				}
				distance /= 2;
				if (matrix.m_matrix[i][j] < 0) {
					matrix.m_matrix[i][j] = -stoi(number);
				}
				else {
					matrix.m_matrix[i][j] = stoi(number);
				}
			}
		}
	}
}

int ShellSort::GetCompares(void) {
	return m_compareCounter;
}

int ShellSort::GetSwitches(void) {
	return m_switchCounter;
}

QuickSort::QuickSort() {
	m_compareCounter = 0;
	m_switchCounter = 0;
}

void QuickSort::SortMatrix(Matrix &matrix) {
	int *column = new int[matrix.m_matrixRows];
	for (int j = 0; j < matrix.m_matrixColumns; j++) {
		for (int i = 0; i < matrix.m_matrixRows; i++) {
			column[i] = matrix.m_matrix[i][j];
		}
		OneDimensionalSort(column, 0, matrix.m_matrixRows);
		for (int k = 0; k < matrix.m_matrixRows; k++) {
			matrix.m_matrix[k][j] = column[k];
		}
	}
	delete[] column;
}

void QuickSort::SortNumber(Matrix &matrix) {
	std::string number;
	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			number = std::to_string(abs(matrix.m_matrix[i][j]));
			__int64 digits = (__int64)number.length();
			OneDimensionalNumberSort(number, 0, digits);
			if (matrix.m_matrix[i][j] < 0) {
				matrix.m_matrix[i][j] = -stoi(number);
			}
			else {
				matrix.m_matrix[i][j] = stoi(number);
			}
		}
	}
}

void QuickSort::OneDimensionalNumberSort(std::string &number, __int64 firstIndex, __int64 size) {
	__int64 leftBorder = firstIndex;
	__int64 rightBorder = size - 1;
	char temp;
	char comparingElement = number[firstIndex];
	while (leftBorder <= rightBorder) {
		while (number[leftBorder] < comparingElement) {
			leftBorder++;
			m_compareCounter++;
		}
		while (number[rightBorder] > comparingElement) {
			rightBorder--;
			m_compareCounter++;
		}
		if (leftBorder <= rightBorder) {
			m_switchCounter++;
			temp = number[leftBorder];
			number[leftBorder] = number[rightBorder];
			number[rightBorder] = temp;
			leftBorder++;
			rightBorder--;
		}
	}
	if (rightBorder > firstIndex) {
		OneDimensionalNumberSort(number, firstIndex, rightBorder + 1);
	}
	if (leftBorder < size) {
		OneDimensionalNumberSort(number, leftBorder, size);
	}
}

void QuickSort::OneDimensionalSort(int *array, int firstIndex, int size) {
	int leftBorder = firstIndex;
	int rightBorder = size - 1;
	int temp = 0;
	int comparingElement = array[firstIndex];
	while (leftBorder <= rightBorder) {
		m_compareCounter++;
		while (array[leftBorder] > comparingElement) {
			leftBorder++;
			m_compareCounter++;
		}
		m_compareCounter++;
		while (array[rightBorder] < comparingElement) {
			rightBorder--;
			m_compareCounter++;
		}
		if (leftBorder <= rightBorder) {
			m_switchCounter++;
			temp = array[rightBorder];
			array[rightBorder] = array[leftBorder];
			array[leftBorder] = temp;
			leftBorder++;
			rightBorder--;
		}
	}
	if (rightBorder > firstIndex) {
		OneDimensionalSort(array, firstIndex, rightBorder + 1);
	}
	if (leftBorder < size) {
		OneDimensionalSort(array, leftBorder, size);
	}
}

int QuickSort::GetCompares(void) {
	return m_compareCounter;
}

int QuickSort::GetSwitches(void) {
	return m_switchCounter;
}

void QuickSort::SetCompares(int compares) {
	m_compareCounter = compares;
}

void QuickSort::SetSwitches(int switches) {
	m_switchCounter = switches;
}