#include "fileOutput.h"

FileOutput::FileOutput(std::string path) {
	m_path = path;
}

void FileOutput::Output(Matrix &original, Matrix &sorted, int *compares, int *switches, std::string *names) const {
	std::ofstream outputFile;
	outputFile.open(m_path);
	outputFile << "Введённая матрица: " << std::endl;
	for (int i = 0; i < original.m_matrixRows; i++) {
		for (int j = 0; j < original.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << original.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "Матрица отсортированная пузырьком:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "Матрица отсортированная выбором:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "Матрица отсортированная вставками:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "Матрица отсортированная методом Шелла:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "Матрица отсортированная быстрой сортировкой:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "Сравнительная таблица:" << std::endl;
	outputFile.width(13);
	outputFile << " " << "Сравнения: " << "Перестановки:" << std::endl;
	for (int i = 0; i < SORTS_QUANTITY; i++) {
		outputFile.width(13);
		outputFile << names[i];
		outputFile.width(7);
		outputFile << compares[i] << "       " << switches[i] << std::endl;
	}
	outputFile.close();
}

void FileOutput::SaveData(Matrix &matrix) const
{
	std::ofstream dataFile;
	dataFile.open(m_path);
	dataFile << matrix.m_matrixRows << std::endl;
	dataFile << matrix.m_matrixColumns << std::endl;
	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			dataFile << matrix.m_matrix[i][j] << std::endl;;
		}
	}
	dataFile.close();
}