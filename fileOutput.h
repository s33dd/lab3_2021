#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H
#define SORTS_QUANTITY 5

#include "file.h"

//Класс для вывода в файл
class FileOutput {
	std::string m_path;
public:
	explicit FileOutput(std::string path);

	void Output(Matrix &original, Matrix &sorted, int *compares, int *switches, std::string *names) const;

	void SaveData(Matrix &matrix) const;
};

#endif // !FILEOUTPUT_H