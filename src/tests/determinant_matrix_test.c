#include "test.h"

START_TEST(test_determinant_matrix1) {
  int rows = rand() % 100 + 1;
  int columns = rows;
  double det = 0;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = j;
    }
  }
  int code = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, 0, EPS);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix2) {
  int rows = 4;
  int columns = rows;
  double det = 0;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = j + i;
    }
  }

  int code = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, 0, EPS);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix3) {
  int rows = 5;
  int columns = rows;
  double det = 0;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);

  A.matrix[0][1] = 6;
  A.matrix[0][2] = -2;
  A.matrix[0][3] = -1;
  A.matrix[0][4] = 5;
  A.matrix[1][3] = -9;
  A.matrix[1][4] = -7;
  A.matrix[2][1] = 15;
  A.matrix[2][2] = 35;
  A.matrix[3][1] = -1;
  A.matrix[3][2] = -11;
  A.matrix[3][3] = -2;
  A.matrix[3][4] = 1;
  A.matrix[4][0] = -2;
  A.matrix[4][1] = -2;
  A.matrix[4][2] = 3;
  A.matrix[4][4] = -2;

  int code = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, 2480, EPS);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix4) {
  int rows = 3;
  int columns = rows;
  double det = 0;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = 1;

  int code = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, -32, EPS);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix5) {
  int rows = 2;
  int columns = rows;
  double det = 0;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -5;
  A.matrix[0][1] = -4;
  A.matrix[1][0] = -2;
  A.matrix[1][1] = -3;

  int code = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, 7, EPS);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix6) {
  int rows = 1;
  int columns = rows;
  double det = 0;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = -5;

  int code = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, -5, EPS);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix7) {
  int rows = rand() % 100 + 1;
  int columns = rows;
  double det = 0;
  matrix_t A = {0};
  rows *= -1;
  s21_create_matrix(rows, columns, &A);
  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix8) {
  int rows = rand() % 100 + 1;
  int columns = rows;
  double det = 0;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);

  int code = s21_determinant(NULL, &det);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix9) {
  int rows = rand() % 100 + 1;
  int columns = rows;

  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);

  int code = s21_determinant(&A, NULL);
  ck_assert_int_eq(code, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix10) {
  int rows = 4;
  int columns = 5;
  double det = 0;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
      ;
    }
  }

  int code = s21_determinant(&A, &det);
  ck_assert_int_eq(code, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_matrix11) {
  int rows = 3;
  int columns = rows;
  double det = 0;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 2.1234567;
  A.matrix[0][1] = 3.7654321;
  A.matrix[0][2] = 4.1234567;

  A.matrix[1][0] = 5.7654321;
  A.matrix[1][1] = 6.1234567;
  A.matrix[1][2] = 7.7654321;

  A.matrix[2][0] = 8.1234567;
  A.matrix[2][1] = 9.7654321;
  A.matrix[2][2] = 10.1234567;

  int code = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, 15.4074096, EPS);
  ck_assert_int_eq(code, 0);

  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant_matrix_suite(void) {
  Suite *s;
  TCase *tc_main;

  s = suite_create("determinant_matrix");
  tc_main = tcase_create("main");

  tcase_add_test(tc_main, test_determinant_matrix1);
  tcase_add_test(tc_main, test_determinant_matrix2);
  tcase_add_test(tc_main, test_determinant_matrix3);
  tcase_add_test(tc_main, test_determinant_matrix4);
  tcase_add_test(tc_main, test_determinant_matrix5);
  tcase_add_test(tc_main, test_determinant_matrix6);
  tcase_add_test(tc_main, test_determinant_matrix7);
  tcase_add_test(tc_main, test_determinant_matrix8);
  tcase_add_test(tc_main, test_determinant_matrix9);
  tcase_add_test(tc_main, test_determinant_matrix10);
  tcase_add_test(tc_main, test_determinant_matrix11);

  suite_add_tcase(s, tc_main);
  return s;
}