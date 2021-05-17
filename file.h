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
	FileWork(std::string path);

	bool NameForbidden(void);

	std::string ChangeName(void);

	//Получение имени файла
	//std::string GetName();

	bool FileExist(void);

	bool SaveFileNormal(void);

	bool FileReadOnly();
};

#endif // !FILE_H
