#include "s21_matrix.h"

bool check_negative_size(matrix_t *A) {
  return (A->rows <= 0 || A->columns <= 0);
}

bool check_pointer(matrix_t *A) { return A == NULL; }

bool check_matrix_A(matrix_t *A) {
  return check_pointer(A) || A->matrix == NULL || check_negative_size(A);
}

bool check_matrices_A_B(matrix_t *A, matrix_t *B) {
  return check_pointer(A) || check_pointer(B) || check_negative_size(A) ||
         check_negative_size(B) || A->matrix == NULL || B->matrix == NULL;
}

bool check_matrices_A_B_result(matrix_t *A, matrix_t *B, matrix_t *result) {
  return check_pointer(A) || check_pointer(B) || check_negative_size(A) ||
         check_negative_size(B) || check_pointer(result) || A->matrix == NULL ||
         B->matrix == NULL;
}

bool equal_size(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

bool check_nan_inf(matrix_t *A) {
  bool err = OK;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isnan(A->matrix[i][j]) || isinf(A->matrix[i][j])) {
        err = INCORRECT_MATRIX;
        i = A->rows;
        j = A->columns;
      }
    }
  }
  return err;
}

bool check_nan_inf_num(double n) { return isnan(n) || isinf(n); }
