#ifndef RANDOMINPUT_H
#define RANDOMINPUT_H

#include "menu.h"
#include "matrix.h"
#include <ctime>

//¬ерхний и нижний предел случайных чисел
enum CONSTS_FOR_RANDOM {
	LOWER_BORDER = -100,
	UPPER_BORDER = 100
};

// ласс дл€ заполнени€ случайными числами
class RandomInput {
	unsigned int m_seed;
public:
	RandomInput(void);

	void Input(Matrix &matrix) const;
};

#endif // !RANDOMINPUT_H