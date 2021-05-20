#ifndef SCREENOUTPUT_H
#define SCREENOUTPUT_H

#include "ISort.h"
#include "menu.h"
#include "matrix.h"

//����� ��� ������ ������ �� �����
class ScreenOutput {
public:
	void MatrixOutput(Matrix &matrix);

	void CompareTableOutput(int* compares, int* switches, std::string *names);
};

#endif // !SCREENOUTPUT_H