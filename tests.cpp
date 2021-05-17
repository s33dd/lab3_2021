#include "tests.h"

bool FirstTest() {
	Matrix test(3, 1);
	test.SetElement(0, 0, 0);
	test.SetElement(1, 0, 1);
	test.SetElement(2, 0, 2);
	bool result = true;

	Matrix forBubble(test);
	Matrix forSelect(test);
	Matrix forInsert(test);
	Matrix forShell(test);
	Matrix forQuick(test);

	Matrix right(3, 1);
	right.SetElement(0, 0, 2);
	right.SetElement(1, 0, 1);
	right.SetElement(2, 0, 0);

	BubbleSort bubble;
	bubble.SortMatrix(forBubble);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forBubble.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки пузырьком первого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forBubble.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	SelectionSort selection;
	selection.SortMatrix(forSelect);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forSelect.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором первого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forSelect.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	InsertionSort insertion;
	insertion.SortMatrix(forInsert);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forInsert.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки вставками первого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forInsert.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	ShellSort shell;
	shell.SortMatrix(forShell);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forShell.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором первого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forShell.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	QuickSort quick;
	quick.SortMatrix(forQuick);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forQuick.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором первого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forQuick.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}
	
	return result;
}

bool SecondTest() {
	Matrix test(3, 2);
	test.SetElement(0, 0, 4);
	test.SetElement(0, 1, 12);
	test.SetElement(1, 0, 45);
	test.SetElement(1, 1, 65);
	test.SetElement(2, 0, 2);
	test.SetElement(2, 1, 0);
	bool result = true;

	Matrix forBubble(test);
	Matrix forSelect(test);
	Matrix forInsert(test);
	Matrix forShell(test);
	Matrix forQuick(test);

	Matrix right(3, 2);
	right.SetElement(0, 0, 45);
	right.SetElement(0, 1, 56);
	right.SetElement(1, 0, 4);
	right.SetElement(1, 1, 12);
	right.SetElement(2, 0, 2);
	right.SetElement(2, 1, 0);


	BubbleSort bubble;
	bubble.SortNumber(forBubble);
	bubble.SortMatrix(forBubble);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (forBubble.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки пузырьком второго теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forBubble.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	SelectionSort selection;
	selection.SortNumber(forSelect);
	selection.SortMatrix(forSelect);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forSelect.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором второго теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forSelect.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	InsertionSort insertion;
	insertion.SortNumber(forInsert);
	insertion.SortMatrix(forInsert);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forInsert.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки вставками второго теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forInsert.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	ShellSort shell;
	shell.SortNumber(forShell);
	shell.SortMatrix(forShell);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forShell.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором второго теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forShell.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	QuickSort quick;
	quick.SortNumber(forQuick);
	quick.SortMatrix(forQuick);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forQuick.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором второго теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forQuick.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	return result;
}

bool ThirdTest() {
	Matrix test(3, 2);
	test.SetElement(0, 0, 4);
	test.SetElement(0, 1, -12);
	test.SetElement(1, 0, 45);
	test.SetElement(1, 1, -65);
	test.SetElement(2, 0, 2);
	test.SetElement(2, 1, 0);
	bool result = true;

	Matrix forBubble(test);
	Matrix forSelect(test);
	Matrix forInsert(test);
	Matrix forShell(test);
	Matrix forQuick(test);

	Matrix right(3, 2);
	right.SetElement(0, 0, 45);
	right.SetElement(0, 1, 0);
	right.SetElement(1, 0, 4);
	right.SetElement(1, 1, -12);
	right.SetElement(2, 0, 2);
	right.SetElement(2, 1, -56);


	BubbleSort bubble;
	bubble.SortNumber(forBubble);
	bubble.SortMatrix(forBubble);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (forBubble.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки пузырьком третьего теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forBubble.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	SelectionSort selection;
	selection.SortNumber(forSelect);
	selection.SortMatrix(forSelect);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forSelect.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором третьего теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forSelect.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	InsertionSort insertion;
	insertion.SortNumber(forInsert);
	insertion.SortMatrix(forInsert);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forInsert.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки вставками третьего теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forInsert.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	ShellSort shell;
	shell.SortNumber(forShell);
	shell.SortMatrix(forShell);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forShell.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором третьего теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forShell.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	QuickSort quick;
	quick.SortNumber(forQuick);
	quick.SortMatrix(forQuick);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forQuick.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором третьего теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forQuick.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	return result;
}

bool FourthTest() {
	Matrix test(3, 2);
	test.SetElement(0, 0, 90);
	test.SetElement(0, 1, 12);
	test.SetElement(1, 0, 5);
	test.SetElement(1, 1, -1);
	test.SetElement(2, 0, 17);
	test.SetElement(2, 1, 0);
	bool result = true;

	Matrix forBubble(test);
	Matrix forSelect(test);
	Matrix forInsert(test);
	Matrix forShell(test);
	Matrix forQuick(test);

	Matrix right(3, 2);
	right.SetElement(0, 0, 17);
	right.SetElement(0, 1, 12);
	right.SetElement(1, 0, 9);
	right.SetElement(1, 1, 0);
	right.SetElement(2, 0, 5);
	right.SetElement(2, 1, -1);

	BubbleSort bubble;
	bubble.SortNumber(forBubble);
	bubble.SortMatrix(forBubble);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (forBubble.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки пузырьком четвёртого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forBubble.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	SelectionSort selection;
	selection.SortNumber(forSelect);
	selection.SortMatrix(forSelect);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forSelect.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором четвёртого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forSelect.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	InsertionSort insertion;
	insertion.SortNumber(forInsert);
	insertion.SortMatrix(forInsert);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forInsert.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки вставками четвёртого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forInsert.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	ShellSort shell;
	shell.SortNumber(forShell);
	shell.SortMatrix(forShell);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forShell.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором четвёртого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forShell.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	QuickSort quick;
	quick.SortNumber(forQuick);
	quick.SortMatrix(forQuick);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forQuick.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором четвёртого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forQuick.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	return result;
}

bool FifthTest() {
	Matrix test(3, 2);
	test.SetElement(0, 0, 0);
	test.SetElement(0, 1, 0);
	test.SetElement(1, 0, 1);
	test.SetElement(1, 1, -1000);
	test.SetElement(2, 0, 1000);
	test.SetElement(2, 1, 82);
	bool result = true;

	Matrix forBubble(test);
	Matrix forSelect(test);
	Matrix forInsert(test);
	Matrix forShell(test);
	Matrix forQuick(test);

	Matrix right(3, 2);
	right.SetElement(0, 0, 1);
	right.SetElement(0, 1, 28);
	right.SetElement(1, 0, 1);
	right.SetElement(1, 1, 0);
	right.SetElement(2, 0, 0);
	right.SetElement(2, 1, -1);


	BubbleSort bubble;
	bubble.SortNumber(forBubble);
	bubble.SortMatrix(forBubble);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (forBubble.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки пузырьком пятого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forBubble.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	SelectionSort selection;
	selection.SortNumber(forSelect);
	selection.SortMatrix(forSelect);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forSelect.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором пятого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forSelect.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	InsertionSort insertion;
	insertion.SortNumber(forInsert);
	insertion.SortMatrix(forInsert);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forInsert.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки вставками пятого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forInsert.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	ShellSort shell;
	shell.SortNumber(forShell);
	shell.SortMatrix(forShell);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forShell.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором пятого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forShell.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	QuickSort quick;
	quick.SortNumber(forQuick);
	quick.SortMatrix(forQuick);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			if (forQuick.GetElement(i, j) != right.GetElement(i, j)) {
				std::cout << "Ошибка в выполнении сортировки выбором пятого теста!" << std::endl;
				std::cout << "Элемент в строке: " << i << " и столбце: " << j << " не совпадает с правильным." << std::endl;
				std::cout << "Правильный элемент: " << right.GetElement(i, j) << " полученный элемент: " << forQuick.GetElement(i, j) << std::endl;
				result = false;
			}
		}
	}

	return result;
}

void MakeTests() {
	int testsPassed = 0;
	if (FirstTest()) {
		testsPassed++;
	};
	if (SecondTest()) {
		testsPassed++;
	};
	if (ThirdTest()) {
		testsPassed++;
	};
	if (FourthTest()) {
		testsPassed++;
	};
	if (FifthTest()) {
		testsPassed++;
	};
	if (testsPassed == 5) {
		std::cout << "Тесты пройдены успешно!" << std::endl;
	}
}