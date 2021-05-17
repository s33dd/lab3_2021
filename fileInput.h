#ifndef FILEINPUT_H
#define FILEINPUT_H

#include "file.h"

enum Characteristics {
	ROWS = 0,
	COLUMNS = 1,
	SIZES_QUANTITY = 2
};

//����� FileInput ��� ����� �� �����
class FileInput {
	std::string m_path;
public:
	FileInput(std::string path);

	bool InputSize(int *sizes);

	bool InputMatrix(Matrix &matrix);

	std::string ChangeName(void);
};

#endif // !FILEINPUT_H
