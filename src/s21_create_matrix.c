#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || check_pointer(result)) {
    return INCORRECT_MATRIX;
  }
  int err = OK;
  result->rows = rows;
  result->columns = columns;

  result->matrix = (double **)calloc(rows + columns * rows, sizeof(double));
  if (result->matrix != NULL) {
    result->matrix[0] = (double *)(result->matrix + rows);
    for (int i = 1; i < rows; i++) {
      result->matrix[i] = result->matrix[0] + i * columns;
    }
  }

  return err;
}
