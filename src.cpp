#include "functions.h"
#include "randomInput.h"
#include "fileInput.h"
#include "fileOutput.h"
#include "manualInput.h"
#include "tests.h"

int main(void) {
	setlocale(LC_ALL, "Russian");

	MENU wantTests = MENU::YES;
	MENU wantContinue = MENU::YES;
	MENU wantSave = MENU::YES;
	MENU wantRewrite = MENU::YES;
	INPUT_TYPE inputType = INPUT_TYPE::RANDOM;
	bool dataReaded = false;
	int *compares = new int[SORTS_QUANTITY];
	int *switches = new int[SORTS_QUANTITY];
	int *sizes = new int[SIZES_QUANTITY];
	sizes[ROWS] = 0;
	sizes[COLUMNS] = 0;
	std::string *sorts = new std::string[SORTS_QUANTITY];
	sorts[BUBBLE] = "��������� ";
	sorts[SELECT] = "������� ";
	sorts[INSERT] = "��������� ";
	sorts[SHELL] = "����� ";
	sorts[QUICK] = "������� ";

	do {
		StartInformation();
		std::string filePath = "nothing";
		int rows = sizes[ROWS];
		int columns = sizes[COLUMNS];

		wantTests = ModularTestsAsk();
		if (wantTests == MENU::YES) {
			MakeTests();
		}

		//������ ���� ���������� �������
		inputType = (INPUT_TYPE)InputAsk();

		if (inputType == INPUT_TYPE::FILE) {
			std::cout << "������� ��� �����: " << std::endl;
			filePath = GetInput<std::string>();
			FileWork tempFile(filePath);
			while (tempFile.NameForbidden()) {
				std::cout << "������� ����� ��� �����:" << std::endl;
				filePath = tempFile.ChangeName();
			}
			FileInput input(filePath);
			dataReaded = input.InputSize(sizes);
			rows = sizes[ROWS];
			columns = sizes[COLUMNS];
			while (!dataReaded) {
				std::cout << "������� ����� ��� �����:" << std::endl;
				filePath = input.ChangeName();
				dataReaded = input.InputSize(sizes);
			}
			while ((rows <= 0) && (columns <= 0)) {
				std::cout << "���������� ����� �/��� �������� ��������� ����!" << std::endl;
				std::cout << "������� ����� ��� �����:" << std::endl;
				filePath = input.ChangeName();
				dataReaded = input.InputSize(sizes);
				rows = sizes[ROWS];
				columns = sizes[COLUMNS];
			}
		}
		else {
			rows = InputRowsSize();
			while (rows <= 0) {
				std::cout << "����� ������ ���� ������ ����!" << std::endl;
				rows = InputRowsSize();
			}
			columns = InputColumnsSize();
			while (columns <= 0) {
				std::cout << "�������� ������ ���� ������ ����!" << std::endl;
				columns = InputColumnsSize();
			}
		}

		Matrix matrix(rows, columns);
				
		if (inputType == INPUT_TYPE::RANDOM) {
			RandomInput random;
			random.Input(matrix);
		}
		else {
			if (inputType == INPUT_TYPE::FILE) {
				FileInput file(filePath);
				dataReaded = file.InputMatrix(matrix);
				while (!dataReaded) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					filePath = file.ChangeName();
					dataReaded = file.InputMatrix(matrix);
				}
			}
			else {
				ManualInput manual;
				manual.Input(matrix);
			}
		}

		Matrix copy(matrix);

		ScreenOutput screen;

		std::cout << "�������� �������: " << std::endl;
		screen.MatrixOutput(matrix);

		MakeSorts(matrix, compares, switches);

		std::cout << "������������� �������:" << std::endl;
		screen.CompareTableOutput(compares, switches, sorts);

		if (inputType != INPUT_TYPE::FILE) {
			wantSave = SaveInputAsk();
			if (wantSave == MENU::YES) {
				std::cout << "������� ��� �����:" << std::endl;
				filePath = GetInput<std::string>();
				FileWork inputSaveFile(filePath);
				while (!inputSaveFile.SaveFileNormal()) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					filePath = inputSaveFile.ChangeName();
				}
				wantRewrite = RewriteAsk(filePath);
				if (wantRewrite == MENU::YES) {
					std::string newFilePath = filePath;
					FileWork newInputSave(newFilePath);
					while (newFilePath == filePath) {
						std::cout << "������� ����� ��� �����:" << std::endl;
						newFilePath = newInputSave.ChangeName();
						while (!newInputSave.SaveFileNormal()) {
							std::cout << "������� ����� ��� �����:" << std::endl;
							newFilePath = newInputSave.ChangeName();
						}
					}
					FileOutput file(newFilePath);
					file.SaveData(copy);
				}
				else {
					while (inputSaveFile.FileReadOnly()) {
						std::cout << "������� ����� ��� �����:" << std::endl;
						filePath = inputSaveFile.ChangeName();
					}
					FileOutput file(filePath);
					file.SaveData(copy);
				}
			}
		}

		wantSave = OutputFileAsk();
		if (wantSave == MENU::YES) {
			std::cout << "������� ��� �����:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "������� ����� ��� �����:" << std::endl;
				filePath = outputSaveFile.ChangeName();
			}
			wantRewrite = RewriteAsk(filePath);
			if (wantRewrite == MENU::YES) {
				std::string newFilePath = filePath;
				FileWork newOutputSave(newFilePath);
				while (newFilePath == filePath) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					newFilePath = newOutputSave.ChangeName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "������� ����� ��� �����:" << std::endl;
						newFilePath = newOutputSave.ChangeName();
					}
				}
				FileOutput file(newFilePath);
				file.Output(copy, matrix, compares, switches, sorts);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					filePath = outputSaveFile.ChangeName();
				}
				FileOutput file(filePath);
				file.Output(copy, matrix, compares, switches, sorts);
			}
		}

		wantContinue = RepeatAsk();
	} while (wantContinue == MENU::YES);
	delete[] compares;
	delete[] switches;
	delete[] sorts;
	delete[] sizes;
}