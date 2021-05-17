#include "fileOutput.h"

FileOutput::FileOutput(std::string path) {
	m_path = path;
}

void FileOutput::Output(Matrix &original, Matrix &sorted, int *compares, int *switches, std::string *names) {
	std::ofstream outputFile;
	outputFile.open(m_path);
	outputFile << "�������� �������: " << std::endl;
	for (int i = 0; i < original.m_matrixRows; i++) {
		for (int j = 0; j < original.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << original.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "������� ��������������� ���������:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "������� ��������������� �������:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "������� ��������������� ���������:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "������� ��������������� ������� �����:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "������� ��������������� ������� �����������:" << std::endl;
	for (int i = 0; i < sorted.m_matrixRows; i++) {
		for (int j = 0; j < sorted.m_matrixColumns; j++) {
			outputFile.width(10);
			outputFile << sorted.m_matrix[i][j] << " ";
		}
		outputFile << std::endl;
	}
	outputFile << "������������� �������:" << std::endl;
	outputFile.width(13);
	outputFile << " " << "���������: " << "������������:" << std::endl;
	for (int i = 0; i < SORTS_QUANTITY; i++) {
		outputFile.width(13);
		outputFile << names[i];
		outputFile.width(7);
		outputFile << compares[i] << "       " << switches[i] << std::endl;
	}
	outputFile.close();
}

void FileOutput::SaveData(Matrix &original) {
	std::ofstream dataFile;
	dataFile.open(m_path);
	dataFile << original.m_matrixRows << std::endl;
	dataFile << original.m_matrixColumns << std::endl;
	for (int i = 0; i < original.m_matrixRows; i++) {
		for (int j = 0; j < original.m_matrixColumns; j++) {
			dataFile << original.m_matrix[i][j] << std::endl;;
		}
	}
	dataFile.close();
}