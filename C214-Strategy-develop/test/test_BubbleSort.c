#include <stdio.h>
#include <stdint.h>
#include "unity.h"
#include "BubbleSort.h"

// every test file requires this function
// setUp() is called by the generated runner before each test case function
void setUp(void){} //Não será usado pois não é uma aplicação para microcontroladores   
                       
// every test file requires this function
// tearDown() is called by the generated runner before each test case function
void tearDown(void){}

void test_BubbleSortWhitNumbers(void)
{
    uint16_t len = 6;
    uint16_t correctSort[6] = {0, 1, 2, 3, 4, 5};
    int16_t numbers[6] = { 5, 3, 2, 4, 0, 1 };
    bubbleSortConstructor(numbers, len);

    /* Verify test results */
    UNITY_TEST_ASSERT_INT16_ARRAY_WITHIN(0.1f, correctSort, numbers, 6, "Test Numbers", 1);
}

void test_BubbleSortWhitLetters(void)
{
    uint16_t len = 6;
    uint16_t correctSort[6] = {'B', 'F', 'H', 'K', 'S', 'Z'};
    uint16_t letters[6] = { 'F', 'Z', 'K', 'B', 'S', 'H'};

    bubbleSortConstructor(letters, len);

    /* Verify test results */
    UNITY_TEST_ASSERT_EQUAL_CHAR_ARRAY(correctSort, letters, 6, 1, "Test Letters");
}