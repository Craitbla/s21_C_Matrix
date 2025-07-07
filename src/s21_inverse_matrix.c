#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (check_matrix_A(A) || result == NULL)
    return INCORRECT_MATRIX;
  else if (A->rows != A->columns || check_nan_inf(A))
    return CALCULATION_ERROR;
  else if (A->rows == 1 && A->columns == 1) {
    if (A->matrix[0][0] != 0) {
      s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    } else
      err = CALCULATION_ERROR;
  } else {
    double det, factor;
    s21_determinant(A, &det);
    if (det != 0) {
      factor = 1.0 / det;
      matrix_t minor_mat, tr_minor_mat;
      s21_calc_complements(A, &minor_mat);
      s21_transpose(&minor_mat, &tr_minor_mat);
      s21_mult_number(&tr_minor_mat, factor, result);
      s21_remove_matrix(&minor_mat);
      s21_remove_matrix(&tr_minor_mat);
    } else {
      err = CALCULATION_ERROR;
    }
  }
  return err;
}
