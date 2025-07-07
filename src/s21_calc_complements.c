#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (check_matrix_A(A) || result == NULL)
    return INCORRECT_MATRIX;
  else if (A->rows != A->columns || check_nan_inf(A))
    return CALCULATION_ERROR;
  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1 || A->columns == 1) {
    result->matrix[0][0] = 0;
  } else {
    matrix_t minor_mat;
    double det = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        create_minor_mat(A, &minor_mat, i, j);
        s21_determinant(&minor_mat, &det);
        if ((i + j) % 2 == 1 && det != 0) det *= -1;
        result->matrix[i][j] = det;
        s21_remove_matrix(&minor_mat);
      }
    }
  }
  return OK;
}

void create_minor_mat(matrix_t *A, matrix_t *minor_mat, int i, int j) {
  s21_create_matrix(A->columns - 1, A->rows - 1, minor_mat);
  int q = 0, w = 0;
  for (int p = 0; p < A->rows; p++) {
    if (p == i)
      continue;
    else {
      w = 0;
      for (int o = 0; o < A->columns; o++) {
        if (o == j)
          continue;
        else {
          minor_mat->matrix[q][w] = A->matrix[p][o];
          w++;
        }
      }
      q++;
    }
  }
}