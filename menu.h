#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <limits>

//�������� ������������, ������� � ��������� ����������� ��� ���������������� ����������

//������������ ��� ��������� ������
enum class MENU {
	NO = 0,
	YES = 1
};

//������������ ��� ����� ����������
enum class INPUT_TYPE {
	MANUAL = 0,
	FILE = 1,
	RANDOM = 2
};

//���� � ����������
template <typename ElementType>
ElementType GetInput(void) {
	ElementType input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "������� ������������ ������! ��������� ����." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
	return input;
}

void StartInformation(void);

MENU ModularTestsAsk(void);

INPUT_TYPE InputAsk(void);

MENU SaveInputAsk(void);

MENU OutputFileAsk(void);

MENU RewriteAsk(std::string path);

MENU RepeatAsk(void);

#endif // !MENU_H