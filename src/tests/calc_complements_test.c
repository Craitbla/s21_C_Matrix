#include "test.h"
START_TEST(test_calc_complemets1) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &A);

  int code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 0, EPS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complemets2) {
  matrix_t A = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_calc_complemets3) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 4, &A);

  int code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complemets4) {
  matrix_t expected = {0};
  matrix_t A = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &A);
  int code2 = s21_create_matrix(3, 3, &expected);
  if (code1 == 0 && code2 == 0) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;

    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;

    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&A, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

Suite *calc_complements_suite(void) {
  Suite *s = suite_create("calc_complements");
  TCase *tc = tcase_create("main");

  tcase_add_test(tc, test_calc_complemets1);
  tcase_add_test(tc, test_calc_complemets2);
  tcase_add_test(tc, test_calc_complemets3);
  tcase_add_test(tc, test_calc_complemets4);

  suite_add_tcase(s, tc);
  return s;
}