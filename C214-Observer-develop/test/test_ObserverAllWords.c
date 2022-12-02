#include <stdio.h>
#include <stdint.h>
#include "unity.h"
#include "Main.h"
#include "Observer.h"
#include "Utils.h"

typedef uint16_t ObserverType(char* phrase, int active);

ObserverType *selectObserver[MAX_OBSERVERS] = {
	ObserverAllWords,
	ObserverEvenWords,
	ObserverUppercaseWords
};

typedef struct{
	int active;
	ObserverType *observer;
}ObserverInterface;


// every test file requires this function
// setUp() is called by the generated runner before each test case function
void setUp(void){} //Não será usado pois não é uma aplicação para microcontroladores   
                       
// every test file requires this function
// tearDown() is called by the generated runner before each test case function
void tearDown(void){}

void test_ActiveObserver(void)
{
    uint16_t numWordsReceived;
    uint16_t numWords = 2;
    char phrase[MAX_LEN_STRING] = {"Running test"};

    //Criando Observador
    ObserverInterface observer;
    observer.active = TRUE;
    observer.observer = selectObserver[ALL_WORDS];
	
	//Notifica Observador
	numWordsReceived = observer.observer(phrase, observer.active);

    /* Verify test results */
    TEST_ASSERT_UINT16_WITHIN(0.1f, numWords, numWordsReceived);
}

void test_InactiveObserver(void)
{
    uint16_t numWordsReceived;
    uint16_t numWords = 0;
    char phrase[MAX_LEN_STRING] = {"Running test"};

    //Criando Observador
    ObserverInterface observer;
    observer.active = FALSE;
    observer.observer = selectObserver[ALL_WORDS];
	
	//Notifica Observador
	numWordsReceived = observer.observer(phrase, observer.active);

    /* Verify test results */
    TEST_ASSERT_UINT16_WITHIN(0.1f, numWords, numWordsReceived);
}