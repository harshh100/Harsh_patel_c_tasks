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
    TEST_ASSERT_EQUAL(-2, add(-1, -1));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_AddFunction);
    return UNITY_END();
}

