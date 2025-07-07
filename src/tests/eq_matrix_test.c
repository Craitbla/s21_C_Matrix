#include "test.h"

START_TEST(test_eq_matrix1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = ((double)rand() / RAND_MAX) * (100000 - 100) + 100000;
      A.matrix[i][j] = rand_val;
      B.matrix[i][j] = rand_val;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix2) {
  int rows = 3;
  int columns = rows;

  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 2.1234567;
  A.matrix[0][1] = 3.7654321;
  A.matrix[0][2] = 4.1234567;

  A.matrix[1][0] = 5.7654321;
  A.matrix[1][1] = 6.1234567;
  A.matrix[1][2] = 7.7654321;

  A.matrix[2][0] = 8.1234567;
  A.matrix[2][1] = 9.7654321;
  A.matrix[2][2] = 10.1234567;

  B.matrix[0][0] = 2.123456707;
  B.matrix[0][1] = 3.765432107;
  B.matrix[0][2] = 4.123456707;

  B.matrix[1][0] = 5.765432107;
  B.matrix[1][1] = 6.123456707;
  B.matrix[1][2] = 7.765432107;

  B.matrix[2][0] = 8.123456707;
  B.matrix[2][1] = 9.765432107;
  B.matrix[2][2] = 10.123456707;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix3) {
  int rows = 2;
  int columns = rows;

  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;

  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;

  B.matrix[1][0] = 1;
  B.matrix[1][1] = 2;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix4) {
  int rows = 1;
  int columns = rows;

  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = INFINITY;
  B.matrix[0][0] = INFINITY;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix5) {
  int rows = 1;
  int columns = rows;

  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_fail1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  int rows1 = rand() % 100 + 1;
  int columns1 = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t B = {0};

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
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_fail2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(s21_eq_matrix(NULL, &B), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_fail3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  A.rows = 1;
  A.columns = 1;
  A.matrix = NULL;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_create_matrix(1, 1, &A);
  B.rows = 1;
  B.columns = 1;
  B.matrix = NULL;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_eq_matrix_fail4) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;

  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  A.rows *= -1;
  A.columns *= -1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  A.rows *= -1;
  A.columns *= -1;
  B.rows *= -1;
  B.columns *= -1;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_fail5) {
  int rows = 2147483647;
  int columns = 2147483647;

  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *eq_matrix_suite(void) {
  Suite *s;
  TCase *tc_main;

  s = suite_create("eq_matrix");
  tc_main = tcase_create("main");

  tcase_add_loop_test(tc_main, test_eq_matrix1, 0, 100);
  tcase_add_test(tc_main, test_eq_matrix2);
  tcase_add_test(tc_main, test_eq_matrix3);
  tcase_add_test(tc_main, test_eq_matrix4);
  tcase_add_test(tc_main, test_eq_matrix5);

  tcase_add_loop_test(tc_main, test_eq_matrix_fail1, 0, 100);
  tcase_add_test(tc_main, test_eq_matrix_fail2);
  tcase_add_test(tc_main, test_eq_matrix_fail3);
  tcase_add_test(tc_main, test_eq_matrix_fail4);
  tcase_add_test(tc_main, test_eq_matrix_fail5);

  suite_add_tcase(s, tc_main);
  return s;
}