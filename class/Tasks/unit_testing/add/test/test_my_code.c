#include "unity.h"
#include "my_code.h"

void setUp(void) {
    // Set up code here (if needed)
}

void tearDown(void) {
    // Tear down code here (if needed)
}

void test_AddFunction(void) {
    TEST_ASSERT_EQUAL(3, add(1, 2));
    TEST_ASSERT_EQUAL(0, add(-1, 1));
    TEST_ASSERT_EQUAL(-1, add(-2, 1));

}

/*
void test_AddFunction(void) {
    TEST_ASSERT(add(1, 2) == 3);              
    TEST_ASSERT(add(-1, 1) == 6);            
    TEST_ASSERT(add(-2, 1) == 6);            
    TEST_ASSERT(add(-3, 1) == 6);             
    TEST_ASSERT(add(-4, 1) == 6);             
    TEST_ASSERT(add(-1, -1) == -2);           
}*/


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_AddFunction);
    UNITY_END();
    return 0;
}

