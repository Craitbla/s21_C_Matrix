#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define EPS 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum ERROR { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

bool check_negative_size(matrix_t *A);
bool check_pointer(matrix_t *A);
bool equal_size(matrix_t *A, matrix_t *B);
bool check_nan_inf(matrix_t *A);

bool check_matrix_A(matrix_t *A);
bool check_matrices_A_B(matrix_t *A, matrix_t *B);
bool check_matrices_A_B_result(matrix_t *A, matrix_t *B, matrix_t *result);
bool check_nan_inf_num(double n);

int check_diagonal_digit_to_zero(matrix_t *copy, int main_digit, int n, int m,
                                 int *sign);
void swap_rows(matrix_t *A, int a, int b);
void create_minor_mat(matrix_t *A, matrix_t *minor_mat, int i, int j);

#endif