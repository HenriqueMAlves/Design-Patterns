#include <stdio.h>
#include <stdint.h>
#include "Main.h"
#include "Observable.h"
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

#ifndef TEST //Necessário para utilizar o ceedling
int main(void)
{
    char phrase[MAX_LEN_STRING] = {"Party at the Goat house"}; 
    
    //Criando Observador 1
    ObserverInterface observer1;
    observer1.active = TRUE;
    observer1.observer = selectObserver[ALL_WORDS];
    
    //Criando Observador 2
    ObserverInterface observer2;
    observer2.active = TRUE;
    observer2.observer = selectObserver[EVEN_LEN_WORDS];
    
    //Criando Observador 3
    ObserverInterface observer3;
    observer3.active = TRUE;
    observer3.observer = selectObserver[UPPERCASE_WORDS];
	
	//Notifica Observadores
	printf("Observador 1 - observa todas as palavras\n");
	observer1.observer(phrase, observer1.active);
	printf("\n");
	printf("Observador 2 - observa palavras pares\n");
	observer2.observer(phrase, observer2.active);
	printf("\n");
	printf("Observador 3 - observa palavras maiusculas\n");
	observer3.observer(phrase, observer3.active);
	printf("\n");
	

    return 0;
}
#endif
