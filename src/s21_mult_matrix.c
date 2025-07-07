#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrices_A_B_result(A, B, result))
    return INCORRECT_MATRIX;
  else if (A->columns != B->rows || check_nan_inf(A) || check_nan_inf(B))
    return CALCULATION_ERROR;
  int err = OK;
  if (!s21_create_matrix(A->rows, B->columns, result)) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < B->columns; ++j) {
        for (int p = 0; p < A->columns; ++p) {
          result->matrix[i][j] += A->matrix[i][p] * B->matrix[p][j];
        }
      }
    }
  } else
    err = INCORRECT_MATRIX;
  return err;
}