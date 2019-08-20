#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "CUnit.h"
//#include "Automated.h"
#include "Basic.h"
#include "schemeValidator.h"

void test01(void) {
  int expected = -1;
  int actual = schemeValidator("4");
  CU_ASSERT_EQUAL(expected,actual);
}

void test02(void) {
  int expected = 0;
  int actual = schemeValidator("http");
  CU_ASSERT_EQUAL(expected,actual);
}

void test03(void) {
  int expected = 1;
  int actual = schemeValidator("HTTP");
  CU_ASSERT_EQUAL(expected,actual);
}

void test04() {
  int expected = 1;
  int actual = schemeValidator("Http");
  CU_ASSERT_EQUAL(expected,actual);
}

void test05() {
  int expected = -1;
  int actual = schemeValidator("hTTP");
  CU_ASSERT_EQUAL(expected,actual);
}


void test06(void) {
  int expected = 0;
  int actual = schemeValidator("ftp");
  CU_ASSERT_EQUAL(expected,actual);
}

void test07(void) {
  int expected = 0;
  int actual = schemeValidator("telnet://192.0.2.16:80/");
  CU_ASSERT_EQUAL(expected,actual);
} 
void test08(void){
  int expected = 0;
  int actual = schemeValidator("http+");
  CU_ASSERT_EQUAL(expected,actual);
}

int main() {
  CU_pSuite Suite = NULL;
  if (CUE_SUCCESS != CU_initialize_registry()) { return CU_get_error(); }
  Suite = CU_add_suite("Suite_of_tests_with_valid_inputs", NULL, NULL);
  if (NULL == Suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if ( (    NULL == CU_add_test(Suite, "messagetest01", test01) 
	 || NULL == CU_add_test(Suite, "messagetest02", test02) 
	 || NULL == CU_add_test(Suite, "messagetest03", test03)
	 || NULL == CU_add_test(Suite, "test04", test04) 
         || NULL == CU_add_test(Suite, "test05", test05) 
	 || NULL == CU_add_test(Suite, "ftpTesttest06", test06)
         || NULL == CU_add_test(Suite, "telnetTesttest07", test07)
	 || NULL == CU_add_test(Suite, "+test08", test08)
     
	) ) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  //  CU_set_output_filename("test");
  //  CU_automated_run_tests();
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
