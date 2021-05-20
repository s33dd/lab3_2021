#include "fileInput.h"

FileInput::FileInput(std::string path) {
	m_path = path;
}

bool FileInput::InputSize(int *sizes) const {
	std::ifstream inputFile;
	inputFile.open(m_path);
	sizes[ROWS] = 0;
	sizes[COLUMNS] = 0;
	std::string data;
	try {
		getline(inputFile, data);
		sizes[ROWS] = stoi(data);
		getline(inputFile, data);
		sizes[COLUMNS] = stoi(data);
	}
	catch (const std::exception&) {
		std::cout << "Произошла ошибка при чтении данных из файла. Проверьте правильность данных." << std::endl;
		inputFile.close();
		return false;
	}
	inputFile.close();
	return true;
}

bool FileInput::InputMatrix(Matrix &matrix) const {
	std::ifstream inputFile;
	inputFile.open(m_path);
	std::string data;
	getline(inputFile, data);
	matrix.m_matrixRows = stoi(data);
	getline(inputFile, data);
	matrix.m_matrixColumns = stoi(data);
	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			try {
				getline(inputFile, data);
				matrix.m_matrix[i][j] = stoi(data);
			}
			catch (const std::exception&) {
				std::cout << "Произошла ошибка при чтении данных из файла. Проверьте правильность данных." << std::endl;
				inputFile.close();
				return false;
			}
		}
	}
	inputFile.close();
	return true;
}

std::string FileInput::ChangeName(void) {
	m_path = GetInput<std::string>();
	FileWork file(m_path);
	while (file.NameForbidden()) {
		m_path = file.ChangeName();
	}
	return m_path;
}