#include "test.h"

int main(void) {
  int failed_count;
  SRunner *sr;

  sr = srunner_create(NULL);

  srunner_add_suite(sr, eq_matrix_suite());
  srunner_add_suite(sr, sum_suite());
  srunner_add_suite(sr, sub_suite());
  srunner_add_suite(sr, mult_number_suite());
  srunner_add_suite(sr, mult_matrix_suite());
  srunner_add_suite(sr, transpose_suite());
  srunner_add_suite(sr, determinant_matrix_suite());
  srunner_add_suite(sr, calc_complements_suite());
  srunner_add_suite(sr, inverse_matrix_suite());

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  failed_count = srunner_ntests_failed(sr);

  srunner_free(sr);

  return !failed_count ? EXIT_SUCCESS : EXIT_FAILURE;
}