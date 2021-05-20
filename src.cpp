#include "functions.h"
#include "randomInput.h"
#include "fileInput.h"
#include "fileOutput.h"
#include "manualInput.h"
#include "tests.h"

int main(void) {
	setlocale(LC_ALL, "Russian");

	auto wantTests = Menu::YES;
	auto wantContinue = Menu::YES;
	auto wantSave = Menu::YES;
	auto wantRewrite = Menu::YES;
	auto inputType = InputType::RANDOM;
	bool dataReaded = false;
	auto compares = new int[SORTS_QUANTITY];
	auto switches = new int[SORTS_QUANTITY];
	auto sizes = new int[SIZES_QUANTITY];
	sizes[ROWS] = 0;
	sizes[COLUMNS] = 0;
	auto sorts = new std::string[SORTS_QUANTITY];
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
		if (wantTests == Menu::YES) {
			MakeTests();
		}

		//������ ���� ���������� �������
		inputType = InputAsk();

		if (inputType == InputType::FILE) {
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
				rows = sizes[ROWS];
				columns = sizes[COLUMNS];
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
				
		if (inputType == InputType::RANDOM) {
			RandomInput random;
			random.Input(matrix);
		}
		else {
			if (inputType == InputType::FILE) {
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

		if (inputType != InputType::FILE) {
			wantSave = SaveInputAsk();
			if (wantSave == Menu::YES) {
				std::cout << "������� ��� �����:" << std::endl;
				filePath = GetInput<std::string>();
				FileWork inputSaveFile(filePath);
				while (!inputSaveFile.SaveFileNormal()) {
					std::cout << "������� ����� ��� �����:" << std::endl;
					filePath = inputSaveFile.ChangeName();
				}
				wantRewrite = RewriteAsk(filePath);
				if (wantRewrite == Menu::YES) {
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
		if (wantSave == Menu::YES) {
			std::cout << "������� ��� �����:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "������� ����� ��� �����:" << std::endl;
				filePath = outputSaveFile.ChangeName();
			}
			wantRewrite = RewriteAsk(filePath);
			if (wantRewrite == Menu::YES) {
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
	} while (wantContinue == Menu::YES);
	delete[] compares;
	delete[] switches;
	delete[] sorts;
	delete[] sizes;
}