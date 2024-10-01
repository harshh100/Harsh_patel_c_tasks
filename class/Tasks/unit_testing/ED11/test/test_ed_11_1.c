#include "unity.h"
#include "ed_11_1.h"

void setUp(void) {
    // Set up code here (if needed)
}

void tearDown(void) {
    // Tear down code here (if needed)
}

void test_case1(void) {
    int stack[] = {0, 1, 1}; 
    int queue[] = {1, 0, 1};
    TEST_ASSERT_EQUAL(0, count_unmatched_employees(stack, 2, queue, 2));
}

void test_case2(void) {
    int stack[] = {1, 0, 0, 1, 0}; 
    int queue[] = {0, 0, 1, 1, 1}; 
    TEST_ASSERT_EQUAL(1, count_unmatched_employees(stack, 4, queue, 4));
}

void test_case3(void) {
    int stack[] = {0, 1, 0, 0, 0}; 
    int queue[] = {1, 0, 0, 0, 0};
    TEST_ASSERT_EQUAL(0, count_unmatched_employees(stack, 4, queue, 4));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_case1);
    RUN_TEST(test_case2);
    RUN_TEST(test_case3);
    UNITY_END();
    return 0;
}

