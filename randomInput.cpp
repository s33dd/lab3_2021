#include "randomInput.h"

RandomInput::RandomInput(void) {
	m_seed = static_cast<unsigned>(time(nullptr));
}

void RandomInput::Input(Matrix &matrix) const {
	srand(m_seed);
	for (int i = 0; i < matrix.m_matrixRows; i++) {
		for (int j = 0; j < matrix.m_matrixColumns; j++) {
			matrix.m_matrix[i][j] = rand() % (UPPER_BORDER - LOWER_BORDER) + LOWER_BORDER;
		}
	}
}