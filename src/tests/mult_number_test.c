#include "test.h"

START_TEST(test_mult_number1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  double number = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
      check.matrix[i][j] = number * A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_fail1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t result = {0};
  double number = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
  s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(s21_mult_number(NULL, number, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_mult_number(&A, NAN, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_fail2) {
  matrix_t A = {0};
  matrix_t result = {0};
  double number = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;

  A.rows = 1;
  A.columns = 1;
  A.matrix = NULL;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_fail3) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t result = {0};
  double number = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
  s21_create_matrix(rows, columns, &A);

  A.rows *= -1;
  A.columns *= -1;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_fail4) {
  int rows = 2147483647;
  int columns = 2147483647;

  matrix_t A = {0};
  matrix_t result = {0};
  double number = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
  s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(s21_mult_number(&A, number, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_number_suite(void) {
  Suite *s;
  TCase *tc_main;

  s = suite_create("mult_number");
  tc_main = tcase_create("main");

  tcase_add_loop_test(tc_main, test_mult_number1, 0, 200);

  tcase_add_test(tc_main, test_mult_number_fail1);
  tcase_add_test(tc_main, test_mult_number_fail2);
  tcase_add_test(tc_main, test_mult_number_fail3);
  tcase_add_test(tc_main, test_mult_number_fail4);

  suite_add_tcase(s, tc_main);
  return s;
}