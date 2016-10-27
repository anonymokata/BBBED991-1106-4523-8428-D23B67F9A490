#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/postfix_to_infix.h"
#include "postfix_to_infix_test.h"


static char* postfix_to_infix[2][2] = {
  {"ab+", "a+b"},
  {"ab-", "a-b"}
};

START_TEST (convert_postfix_to_infix)
{
  char* postfix = convert_to_infix(postfix_to_infix[_i][0]);

  ck_assert_str_eq(postfix, postfix_to_infix[_i][1]);
}
END_TEST

START_TEST (convert_a_b_minus_to_a_subtract_b)
{
  char* postfix = convert_to_infix("ab-");

  ck_assert_str_eq(postfix, "a-b");
}
END_TEST

Suite *postfix_to_infix_suite(void)
{
  Suite *s;
  TCase *tc_convert_to_infix;

  s = suite_create("postfix to infix converter");

  tc_convert_to_infix = tcase_create("Convert to infix");

  tcase_add_loop_test(tc_convert_to_infix, convert_postfix_to_infix, 0, 2);

  suite_add_tcase(s, tc_convert_to_infix);

  return s;
}
