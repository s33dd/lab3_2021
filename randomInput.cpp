#include "randomInput.h"

RandomInput::RandomInput(void) {
	m_seed = (unsigned int)time(0);
}

void RandomInput::Input(Matrix &matrix) {
	srand(m_seed);
	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			matrix.m_matrix[i][j] = rand() % (UPPER_BORDER - LOWER_BORDER) + LOWER_BORDER;
		}
	}
}