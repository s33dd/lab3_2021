#ifndef RANDOMINPUT_H
#define RANDOMINPUT_H

#include "menu.h"
#include "matrix.h"
#include <ctime>

//������� � ������ ������ ��������� �����
enum CONSTS_FOR_RANDOM {
	LOWER_BORDER = -100,
	UPPER_BORDER = 100
};

//����� ��� ���������� ���������� �������
class RandomInput {
	unsigned int m_seed;
public:
	RandomInput(void);

	void Input(Matrix &matrix) const;
};

#endif // !RANDOMINPUT_H