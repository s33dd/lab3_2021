#ifndef FILEINPUT_H
#define FILEINPUT_H

#include "file.h"

enum Characteristics {
	ROWS = 0,
	COLUMNS = 1,
	SIZES_QUANTITY = 2
};

//Класс FileInput для ввода из файла
class FileInput {
	std::string m_path;
public:
	explicit FileInput(std::string path);

	bool InputSize(int *sizes) const;

	bool InputMatrix(Matrix &matrix) const;

	std::string ChangeName(void);
};

#endif // !FILEINPUT_H