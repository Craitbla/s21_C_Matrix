#include "test.h"

START_TEST(test_transpose1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &check);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
      check.matrix[j][i] = A.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_fail1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(s21_transpose(NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_transpose(&A, NULL), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_fail2) {
  matrix_t A = {0};

  matrix_t result = {0};

  A.rows = 1;
  A.columns = 1;
  A.matrix = NULL;
  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_fail3) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);

  A.rows *= -1;
  A.columns *= -1;
  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_fail4) {
  int rows = 2147483647;
  int columns = 2147483647;

  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);

  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *transpose_suite(void) {
  Suite *s;
  TCase *tc_main;

  s = suite_create("transpose");
  tc_main = tcase_create("main");

  tcase_add_loop_test(tc_main, test_transpose1, 0, 100);

  tcase_add_test(tc_main, test_transpose_fail1);
  tcase_add_test(tc_main, test_transpose_fail2);
  tcase_add_test(tc_main, test_transpose_fail3);
  tcase_add_test(tc_main, test_transpose_fail4);

  suite_add_tcase(s, tc_main);
  return s;
}