#ifndef MANUALINPUT__H
#define MANUALINPUT_H

#include "menu.h"
#include "matrix.h"

//����� ��� ���������� � ����������
class ManualInput {
public:
	void Input(Matrix &matrix) const;
};

int InputRowsSize(void);

int InputColumnsSize(void);

#endif // !MANUALINPUT__H