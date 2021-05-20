#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "screenOutput.h"
#include "ISort.h"

enum Sorts {
	BUBBLE = 0,
	SELECT = 1,
	INSERT = 2,
	SHELL = 3,
	QUICK = 4
};

void MakeSorts(Matrix &matrix, int *compares, int *switches);

#endif // !FUNCTIONS_H