#include "menu.h"
#include <fstream>

void StartInformation() {
	std::cout << "________________________" << std::endl;
	std::cout << "������������ ������ �� ���������������� �3" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "������� 25" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "���������� ��������� ��������� ��� ���������� ������� ������ ��������: �����������, ������, �������, ����� � ������� ����������." << std::endl;
	std::cout << "������� �� ����� ��������������� (���� ���) � ������������� (��� ������� �� �������) ������� ������." << std::endl;
	std::cout << "��������� ������������� ������� ������������� �������, � ������� ���������� ������� ����� ��������� � ������������ ���������� � ������ ������ ����������." << std::endl;
	std::cout << "C��������� ������ ����������� � ������ �������� ����� ������� ����� �� �����������, ����� ����������� ������ � �������� �� ��������." << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "�������� ������� 403 ������ ";
	std::cout << "����������� ����� ����������.  2021 ���" << std::endl;
	std::cout << "________________________" << std::endl << std::endl;
}

bool RightMenuChoice(MENU choice) {
	if ((choice == MENU::NO) || (choice == MENU::YES)) {
		return true;
	}
	else {
		std::cout << "����������� ��������� ��������!" << std::endl;
		return false;
	}
}

bool RightInputChoice(INPUT_TYPE choice) {
	if ((choice == INPUT_TYPE::RANDOM) || (choice == INPUT_TYPE::MANUAL) || (choice == INPUT_TYPE::FILE)) {
		return true;
	}
	else {
		std::cout << "����������� ��������� ��������!" << std::endl;
		return false;
	}
}

MENU ModularTestsAsk(void) {
	std::cout << "������� ��������� ��������� �����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	while (!RightMenuChoice(decision)) {
		decision = (MENU)GetInput<int>();
	}
	return decision;
}

INPUT_TYPE InputAsk(void) {
	std::cout << "��� �� ������� ��������� ������?" << std::endl;
	std::cout << "2 � ���������� ������� / 1 � �� ����� / 0 � � ����������" << std::endl;
	std::cout << "��� �����: ";
	INPUT_TYPE decision = (INPUT_TYPE)GetInput<int>();
	while (!RightInputChoice(decision)) {
		decision = (INPUT_TYPE)GetInput<int>();
	}
	return decision;
}

MENU SaveInputAsk(void) {
	std::cout << "������� ��������� �������� ������ � ����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	while (!RightMenuChoice(decision)) {
		decision = (MENU)GetInput<int>();
	}
	return decision;
}

MENU OutputFileAsk(void) {
	std::cout << "������� ��������� ��������� � ����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	while (!RightMenuChoice(decision)) {
		decision = (MENU)GetInput<int>();
	}
	return decision;
}

MENU RewriteAsk(std::string path) {
	std::ifstream checkFile;
	checkFile.open(path);
	MENU decision = MENU::NO;
	if (checkFile.is_open()) {
		std::cout << "���� � ����� ������ ��� ����������!" << std::endl;
		std::cout << "��� �� ������� ������� � ������?" << std::endl;
		std::cout << "1 � ������� ����� / 0 � ������������ ������������" << std::endl;
		std::cout << "��� �����: ";
		decision = (MENU)GetInput<int>();
		while (!RightMenuChoice(decision)) {
			decision = (MENU)GetInput<int>();
		}
		checkFile.close();
		return decision;
	}
	else {
		checkFile.close();
		return decision;
	}
}

MENU RepeatAsk(void) {
	std::cout << "������� �� �� �������� ��������� ���������?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	while (!RightMenuChoice(decision)) {
		decision = (MENU)GetInput<int>();
	}
	return decision;
}