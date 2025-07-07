#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (check_matrices_A_B(A, B) || !equal_size(A, B)) {
    return FAILURE;
  }
  int err = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
        err = FAILURE;
        i = A->rows;
        j = A->columns;
      }
    }
  }
  return err;
}