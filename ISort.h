#ifndef ISORT_H
#define ISORT_H
#define SORTS_QUANTITY 5

#include "matrix.h"
#include <cmath>
#include <string>

class ISort {
protected:
	~ISort() = default;
	virtual void SortMatrix(Matrix &matrix) = 0;
	virtual int GetSwitches(void) = 0;
	virtual int GetCompares(void) = 0;
};

class BubbleSort : public ISort {
	int m_compareCounter;
	int m_switchCounter;
public:
	virtual ~BubbleSort() = default;
	BubbleSort();
	void SortMatrix(Matrix &matrix) override;
	void SortNumber(Matrix &matrix);
	int GetSwitches(void) override;
	int GetCompares(void) override;
};

class SelectionSort : public ISort {
	int m_compareCounter;
	int m_switchCounter;
public:
	virtual ~SelectionSort() = default;
	SelectionSort();
	void SortMatrix(Matrix& matrix) override;
	void SortNumber(Matrix& matrix);
	int GetSwitches(void) override;
	int GetCompares(void) override;
};

class InsertionSort : public ISort {
	int m_compareCounter;
	int m_switchCounter;
public:
	virtual ~InsertionSort() = default;
	InsertionSort();
	void SortMatrix(Matrix& matrix) override;
	void SortNumber(Matrix& matrix);
	int GetSwitches(void) override;
	int GetCompares(void) override;
};

class ShellSort : public ISort {
	int m_compareCounter;
	int m_switchCounter;
public:
	virtual ~ShellSort() = default;
	ShellSort();
	void SortMatrix(Matrix& matrix) override;
	void SortNumber(Matrix& matrix);
	int GetSwitches(void) override;
	int GetCompares(void) override;
};

class QuickSort : public ISort {
	int m_compareCounter;
	int m_switchCounter;
public:
	virtual ~QuickSort() = default;
	QuickSort();
	void SortMatrix(Matrix &matrix) override;
	void OneDimensionalSort(int *array, int firstIndex, int rows);
	void OneDimensionalNumberSort(std::string& number, __int64 firstIndex, __int64 size);
	void SortNumber(Matrix& matrix);
	int GetSwitches(void) override;
	int GetCompares(void) override;
	void SetCompares(int compares);
	void SetSwitches(int switches);
};

#endif // !ISORT_H