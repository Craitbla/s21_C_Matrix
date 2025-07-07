#ifndef _S21_MATRIX_TEST_H_
#define _S21_MATRIX_TEST_H_

#include <check.h>

#include "../s21_matrix.h"

Suite *sum_suite(void);
Suite *sub_suite(void);
Suite *mult_number_suite(void);
Suite *mult_matrix_suite(void);
Suite *transpose_suite(void);
Suite *determinant_matrix_suite(void);
Suite *eq_matrix_suite(void);
Suite *inverse_matrix_suite(void);
Suite *calc_complements_suite(void);

#endif