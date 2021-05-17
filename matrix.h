#ifndef MATRIX_H
#define MATRIX_H

//Класс Matrix для работы с матрицей. Содержит в себе кол-во строк, столбцов, указатель на первый элемент матрицы
class Matrix {
	int m_matrixColumns;
	int m_matrixRows;
	int **m_matrix;

public:
	Matrix(int rows, int columns);

	~Matrix();

	Matrix(Matrix &matrix);

	int GetElement(int row, int column);

	void SetElement(int row, int column, int number);

	//int operator[](int index);

	friend class FileInput;

	friend class FileOutput;

	friend class ScreenOutput;

	friend class ManualInput;

	friend class RandomInput;

	friend class BubbleSort;

	friend class SelectionSort;

	friend class InsertionSort;

	friend class ShellSort;

	friend class QuickSort;
};
#endif // !MATRIX_H