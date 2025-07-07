#include "test.h"

START_TEST(test_sub_matrix1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
      B.matrix[i][j] = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
      check.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_matrix_fail1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_matrix_fail2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  A.rows = 1;
  A.columns = 1;
  A.matrix = NULL;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);

  s21_create_matrix(1, 1, &A);
  B.rows = 1;
  B.columns = 1;
  B.matrix = NULL;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_matrix_fail3) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.rows *= -1;
  A.columns *= -1;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);

  A.rows *= -1;
  A.columns *= -1;
  B.rows *= -1;
  B.columns *= -1;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_matrix_fail4) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  int rows1 = rand() % 100 + 1;
  int columns1 = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows1, columns1, &B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < columns1; j++) {
      B.matrix[i][j] = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_matrix_fail5) {
  int rows = 2147483647;
  int columns = 2147483647;

  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *sub_suite(void) {
  Suite *s;
  TCase *tc_main;

  s = suite_create("sub_matrix");
  tc_main = tcase_create("main");

  tcase_add_loop_test(tc_main, test_sub_matrix1, 0, 100);

  tcase_add_test(tc_main, test_sub_matrix_fail1);
  tcase_add_test(tc_main, test_sub_matrix_fail2);
  tcase_add_test(tc_main, test_sub_matrix_fail3);
  tcase_add_test(tc_main, test_sub_matrix_fail4);
  tcase_add_test(tc_main, test_sub_matrix_fail5);

  tcase_add_loop_test(tc_main, test_sub_matrix_fail4, 0, 100);
  suite_add_tcase(s, tc_main);
  return s;
}