#include "test.h"

START_TEST(test_inverse_matrix1) {
  matrix_t A = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  int row = 8;
  int columns = row;
  s21_create_matrix(row, columns, &A);
  s21_create_matrix(row, columns, &check);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 8;
  A.matrix[0][2] = 7;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 1;
  A.matrix[0][5] = 8;
  A.matrix[0][6] = 3;
  A.matrix[0][7] = 9;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 2;
  A.matrix[1][4] = 2;
  A.matrix[1][5] = 1;
  A.matrix[1][6] = 5;
  A.matrix[1][7] = 8;

  A.matrix[2][0] = 8;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 7;
  A.matrix[2][3] = 7;
  A.matrix[2][4] = 3;
  A.matrix[2][5] = 4;
  A.matrix[2][6] = 4;
  A.matrix[2][7] = 1;

  A.matrix[3][0] = 1;
  A.matrix[3][1] = 7;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 4;
  A.matrix[3][4] = 4;
  A.matrix[3][5] = 3;
  A.matrix[3][6] = 0;
  A.matrix[3][7] = 5;

  A.matrix[4][0] = 5;
  A.matrix[4][1] = 7;
  A.matrix[4][2] = 5;
  A.matrix[4][3] = 6;
  A.matrix[4][4] = 8;
  A.matrix[4][5] = 3;
  A.matrix[4][6] = 1;
  A.matrix[4][7] = 9;

  A.matrix[5][0] = 3;
  A.matrix[5][1] = 7;
  A.matrix[5][2] = 8;
  A.matrix[5][3] = 0;
  A.matrix[5][4] = 5;
  A.matrix[5][5] = 7;
  A.matrix[5][6] = 0;
  A.matrix[5][7] = 2;

  A.matrix[6][0] = 5;
  A.matrix[6][1] = 8;
  A.matrix[6][2] = 3;
  A.matrix[6][3] = 5;
  A.matrix[6][4] = 9;
  A.matrix[6][5] = 1;
  A.matrix[6][6] = 2;
  A.matrix[6][7] = 0;

  A.matrix[7][0] = 7;
  A.matrix[7][1] = 8;
  A.matrix[7][2] = 7;
  A.matrix[7][3] = 4;
  A.matrix[7][4] = 7;
  A.matrix[7][5] = 9;
  A.matrix[7][6] = 1;
  A.matrix[7][7] = 5;

  check.matrix[0][0] = -0.5349902183;
  check.matrix[0][1] = 0.2894503762;
  check.matrix[0][2] = 0.2648128502;
  check.matrix[0][3] = 0.6295578936;
  check.matrix[0][4] = -0.1684575429;
  check.matrix[0][5] = 0.2471263249;
  check.matrix[0][6] = -0.3773947292;
  check.matrix[0][7] = 0.0217143747;

  check.matrix[1][0] = -0.3358379646;
  check.matrix[1][1] = 0.2037511071;
  check.matrix[1][2] = 0.2032547229;
  check.matrix[1][3] = 0.6234293334;
  check.matrix[1][4] = -0.1799149334;
  check.matrix[1][5] = 0.3295114996;
  check.matrix[1][6] = -0.2254070837;
  check.matrix[1][7] = -0.1935314328;

  check.matrix[2][0] = 0.09452225456;
  check.matrix[2][1] = -0.09221066155;
  check.matrix[2][2] = 0.03813722914;
  check.matrix[2][3] = -0.2190871073;
  check.matrix[2][4] = 0.1695573745;
  check.matrix[2][5] = 0.1092580516;
  check.matrix[2][6] = 0.007715043036;
  check.matrix[2][7] = -0.1600498331;

  check.matrix[3][0] = 0.3630563639;
  check.matrix[3][1] = -0.3052665388;
  check.matrix[3][2] = -0.04656927155;
  check.matrix[3][3] = -0.4771776828;
  check.matrix[3][4] = 0.2389343637;
  check.matrix[3][5] = -0.2685487089;
  check.matrix[3][6] = 0.1928760759;
  check.matrix[3][7] = -0.001245826966;

  check.matrix[4][0] = 0.2619837848;
  check.matrix[4][1] = -0.133556544;
  check.matrix[4][2] = -0.2495968906;
  check.matrix[4][3] = -0.4562289726;
  check.matrix[4][4] = 0.1044612934;
  check.matrix[4][5] = -0.2245895097;
  check.matrix[4][6] = 0.3128420752;
  check.matrix[4][7] = 0.1500734843;

  check.matrix[5][0] = 0.2992174649;
  check.matrix[5][1] = -0.1560300945;
  check.matrix[5][2] = -0.1850280149;
  check.matrix[5][3] = -0.3646314915;
  check.matrix[5][4] = -0.02339656554;
  check.matrix[5][5] = -0.2701059926;
  check.matrix[5][6] = 0.1915783395;
  check.matrix[5][7] = 0.2628500238;

  check.matrix[6][0] = 0.3028673486;
  check.matrix[6][1] = 0.0418714657;
  check.matrix[6][2] = -0.2001336669;
  check.matrix[6][3] = -0.3106910771;
  check.matrix[6][4] = -0.1692459178;
  check.matrix[6][5] = -0.2826713255;
  check.matrix[6][6] = 0.3477738954;
  check.matrix[6][7] = 0.1562734201;

  check.matrix[7][0] = -0.1023914038;
  check.matrix[7][1] = 0.1015348978;
  check.matrix[7][2] = 0.0104305565;
  check.matrix[7][3] = 0.1667915738;
  check.matrix[7][4] = 0.02489382894;
  check.matrix[7][5] = 0.04583280613;
  check.matrix[7][6] = -0.1284726616;
  check.matrix[7][7] = -0.01017100922;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(test_inverse_matrix2) {
  matrix_t A, result, check;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;

  check.matrix[0][0] = 44300.0 / 367429.0;
  check.matrix[0][1] = -236300.0 / 367429.0;
  check.matrix[0][2] = 200360.0 / 367429.0;
  check.matrix[1][0] = 20600.0 / 367429.0;
  check.matrix[1][1] = 56000.0 / 367429.0;
  check.matrix[1][2] = -156483.0 / 367429.0;
  check.matrix[2][0] = 30900.0 / 367429.0;
  check.matrix[2][1] = 84000.0 / 367429.0;
  check.matrix[2][2] = -51010.0 / 367429.0;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix3) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 1;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 0;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 3;

  A.matrix[3][0] = 4;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 3;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_inverse_matrix4) {
  matrix_t A = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &A);
  if (codec == 0) {
    A.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&A, &result);
    ck_assert_double_eq_tol(result.matrix[0][0], (1.0 / A.matrix[0][0]), 1e-06);
    ck_assert_int_eq(code, OK);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix5) {
  matrix_t A = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &A);
  if (!codec) {
    int code = s21_inverse_matrix(&A, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix6) {
  matrix_t A = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &A);
  if (!codec) {
    int code = s21_inverse_matrix(&A, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *inverse_matrix_suite(void) {
  Suite *s;
  TCase *tc_main;

  s = suite_create("inverse_matrix");
  tc_main = tcase_create("main");

  tcase_add_test(tc_main, test_inverse_matrix1);
  tcase_add_test(tc_main, test_inverse_matrix2);
  tcase_add_test(tc_main, test_inverse_matrix3);
  tcase_add_test(tc_main, test_inverse_matrix4);
  tcase_add_test(tc_main, test_inverse_matrix5);
  tcase_add_test(tc_main, test_inverse_matrix6);

  suite_add_tcase(s, tc_main);
  return s;
}