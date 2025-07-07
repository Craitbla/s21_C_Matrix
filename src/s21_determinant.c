#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  if (check_matrix_A(A) || result == NULL)
    return INCORRECT_MATRIX;
  else if (A->columns != A->rows || check_nan_inf(A))
    return CALCULATION_ERROR;
  else {
    bool err_flag = 0;
    double factor;
    int main_gigit = 1, sign = 1, diagonal_digit;
    matrix_t copy;
    s21_create_matrix(A->rows, A->columns, &copy);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        copy.matrix[i][j] = A->matrix[i][j];
      }
    }
    for (int n = 0; n < A->columns; n++) {
      diagonal_digit = main_gigit - 1;
      if (check_diagonal_digit_to_zero(&copy, diagonal_digit, n, main_gigit,
                                       &sign)) {
        err_flag = 1;
        break;
      }
      for (int i = A->rows - 1; i >= main_gigit; i--) {
        if (copy.matrix[diagonal_digit][n] != 0)
          factor = copy.matrix[i][n] / copy.matrix[diagonal_digit][n];
        for (int j = 0; j < A->columns; j++) {
          copy.matrix[i][j] -= copy.matrix[diagonal_digit][j] * factor;
        }
      }
      main_gigit++;
    }
    *result = 1;
    if (err_flag) {
      *result = 0;
    } else {
      *result = 1;
      for (int j = 0; j < A->rows; j++) *result *= copy.matrix[j][j];
      if (sign == -1) *result *= -1;
    }
    s21_remove_matrix(&copy);
  }
  return err;
}

int check_diagonal_digit_to_zero(matrix_t *copy, int diagonal_digit, int n,
                                 int main_gigit, int *sign) {
  int flag_null_row = 1;
  if (copy->matrix[diagonal_digit][n] == 0) {
    for (int k = main_gigit; k < copy->rows; k++) {
      if (copy->matrix[k][n] != 0) {
        flag_null_row = 0;
        swap_rows(copy, diagonal_digit, k);
        *sign *= -1;
        break;
      }
    }
  } else
    flag_null_row = 0;
  return flag_null_row;
}

void swap_rows(matrix_t *copy, int a, int b) {
  double tmp = 0;
  for (int i = 0; i < copy->columns; i++) {
    tmp = copy->matrix[a][i];
    copy->matrix[a][i] = copy->matrix[b][i];
    copy->matrix[b][i] = tmp;
  }
}