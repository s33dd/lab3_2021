#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <filesystem>
#include "matrix.h"
#include "menu.h"

//Класс для проверки имён файлов перед их использованием
class FileWork {
	std::string m_path;
public:
	explicit FileWork(std::string path);

	bool NameForbidden(void) const;

	std::string ChangeName(void);

	bool FileExist(void) const;

	bool SaveFileNormal(void) const;
	
	bool FileReadOnly(void) const;
};

#endif // !FILE_H