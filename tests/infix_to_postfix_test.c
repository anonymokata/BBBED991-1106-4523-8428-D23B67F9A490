#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include "../src/infix_to_postfix.h"
#include "infix_to_postfix_test.h"

START_TEST(should_convert_infix_with_addition_operator_to_postfix) {
  char *postfix = convert_to_postfix("a+b");
  ck_assert_str_eq(postfix, "ab+");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_subtract_operator_to_postfix) {
  char *postfix = convert_to_postfix("a-b");
  ck_assert_str_eq(postfix, "ab-");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_division_operator_to_postfix) {
  char *postfix = convert_to_postfix("a/b");
  ck_assert_str_eq(postfix, "ab/");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_multiplication_operator_to_postfix) {
  char *postfix = convert_to_postfix("a*b");
  ck_assert_str_eq(postfix, "ab*");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_exponant_operator_to_postfix) {
  char *postfix = convert_to_postfix("a^b");
  ck_assert_str_eq(postfix, "ab^");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_multiple_operands_with_equal_precedence) {
  char *postfix = convert_to_postfix("a+b-c");
  ck_assert_str_eq(postfix, "abc-+");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_addition_multiplication_and_division) {
  char *postfix = convert_to_postfix("a*b+c/d");
  ck_assert_str_eq(postfix, "ab*cd/+");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_exponents_and_addition) {
  char *postfix = convert_to_postfix("a^b+c");
  ck_assert_str_eq(postfix, "ab^c+");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_multiple_operands_with_different_precedence) {
  char *postfix = convert_to_postfix("l/m^n*o-p");
  ck_assert_str_eq(postfix, "lmn^/o*p-");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_respect_to_parenthesis) {
  char *postfix = convert_to_postfix("(a+b)-c");
  ck_assert_str_eq(postfix, "ab+c-");
  free(postfix);
}
END_TEST

START_TEST(should_convert_infix_with_multiple_parenthesis_and_operators) {
  char *postfix = convert_to_postfix("((v/w)^x)*(y-z)");
  ck_assert_str_eq(postfix, "vw/x^yz-*");
  free(postfix);
}
END_TEST

START_TEST(should_exit_with_status_1_upon_failure_of_validation) {
  char *invalid_infix = convert_to_postfix("(ab+)");
  free(invalid_infix);
}
END_TEST

Suite *infix_to_postfix_suite(void) {
  Suite *s;
  TCase *tc_convert_to_postfix;

  s = suite_create("infix to postfix converter");

  tc_convert_to_postfix = tcase_create("Convert to postfix");

  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_addition_operator_to_postfix);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_subtract_operator_to_postfix);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_division_operator_to_postfix);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_multiplication_operator_to_postfix);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_exponant_operator_to_postfix);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_multiple_operands_with_equal_precedence);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_addition_multiplication_and_division);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_exponents_and_addition);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_multiple_operands_with_different_precedence);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_respect_to_parenthesis);
  tcase_add_test(tc_convert_to_postfix, should_convert_infix_with_multiple_parenthesis_and_operators);
  tcase_add_exit_test(tc_convert_to_postfix, should_exit_with_status_1_upon_failure_of_validation, 23);

  suite_add_tcase(s, tc_convert_to_postfix);

  return s;
}
