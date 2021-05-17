#include "functions.h"

void MakeBubble(Matrix &matrix, int &compares, int &switches) {
	Matrix sorted(matrix);

	BubbleSort bubble;
	bubble.SortNumber(sorted);

	compares = bubble.GetCompares();
	switches = bubble.GetSwitches();

	bubble.SortMatrix(sorted);

	compares += bubble.GetCompares();
	switches += bubble.GetSwitches();

	ScreenOutput screen;
	std::cout << "Матрица отсортированная пузырьком:" << std::endl;
	screen.MatrixOutput(sorted);
}

void MakeSelection(Matrix &matrix, int &compares, int &switches){
	Matrix sorted(matrix);

	SelectionSort selection;
	selection.SortNumber(sorted);

	compares = selection.GetCompares();
	switches = selection.GetSwitches();

	selection.SortMatrix(sorted);

	compares += selection.GetCompares();
	switches += selection.GetSwitches();

	ScreenOutput screen;
	std::cout << "Матрица отсортированная методом отбора:" << std::endl;
	screen.MatrixOutput(sorted);
}

void MakeInsertion(Matrix &matrix, int &compares, int &switches){
	Matrix sorted(matrix);

	InsertionSort insertion;
	insertion.SortNumber(sorted);

	compares = insertion.GetCompares();
	switches = insertion.GetSwitches();

	insertion.SortMatrix(sorted);

	compares += insertion.GetCompares();
	switches += insertion.GetSwitches();

	ScreenOutput screen;
	std::cout << "Матрица отсортированная методом вставки:" << std::endl;
	screen.MatrixOutput(sorted);
}

void MakeShell(Matrix &matrix, int &compares, int &switches){
	Matrix sorted(matrix);

	ShellSort shell;
	shell.SortNumber(sorted);

	compares = shell.GetCompares();
	switches = shell.GetSwitches();

	shell.SortMatrix(sorted);

	compares += shell.GetCompares();
	switches += shell.GetSwitches();

	ScreenOutput screen;
	std::cout << "Матрица отсортированная методом Шелла:" << std::endl;
	screen.MatrixOutput(sorted);
}

void MakeQuick(Matrix &matrix, int &compares, int &switches){
	QuickSort quick;

	quick.SortNumber(matrix);

	compares = quick.GetCompares();
	switches = quick.GetSwitches();

	quick.SetCompares(0);
	quick.SetSwitches(0);

	quick.SortMatrix(matrix);

	compares = quick.GetCompares();
	switches = quick.GetSwitches();

	ScreenOutput screen;
	std::cout << "Матрица отсортированная методом быстрой сортировкой:" << std::endl;
	screen.MatrixOutput(matrix);
}

void MakeSorts(Matrix &matrix, int *compares, int *switches) {
	MakeBubble(matrix, compares[BUBBLE], switches[BUBBLE]);
	MakeSelection(matrix, compares[SELECT], switches[SELECT]);
	MakeInsertion(matrix, compares[INSERT], switches[INSERT]);
	MakeShell(matrix, compares[SHELL], switches[SHELL]);
	MakeQuick(matrix, compares[QUICK], switches[QUICK]);
}