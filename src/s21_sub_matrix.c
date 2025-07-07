#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrices_A_B_result(A, B, result))
    return INCORRECT_MATRIX;
  else if (!equal_size(A, B) || check_nan_inf(A) || check_nan_inf(B))
    return CALCULATION_ERROR;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}