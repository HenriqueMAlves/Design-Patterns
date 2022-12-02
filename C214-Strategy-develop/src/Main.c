#include <stdio.h>
#include <stdint.h>
#include "BubbleSort.h"
#include "Main.h"
#include "Utils.h"
#include "QuickSort.h"
#include "InsertionSort.h"

//Definição de um novo "tipo" para guardar funções em um vetor de ponteiros
typedef void algorithmType(int16_t* data, uint16_t len, char* dataType);

//Vetor de ponteiro em que cada posição aponta para um algoritmo de ordenação diferente
algorithmType *sort[NUM_MAX_ALGORITHM] = {
	bubbleSortConstructor,
	insertionSortConstructor,
	quickSortConstructor
};

#ifndef TEST //Necessário para utilizar o ceedling
int main(void)
{
	algorithm_t selectedAlgorithm[4] = {QUICK_SORT, INSERTION_SORT, BUBBLE_SORT};
	uint8_t i;
    int16_t numbers[BUFFER_SORT_LEN] = { 5, 3, 2, 4, 0, 1 };
    int16_t letters[BUFFER_SORT_LEN] = { 'F', 'Z', 'K', 'B', 'S', 'H'};
	
	for(i=0; i<3; i++)
	{//Ordena letras
		sort[selectedAlgorithm[i]](letters, BUFFER_SORT_LEN, DATATYPE_STR);
    	utils_printResult(letters, BUFFER_SORT_LEN, DATATYPE_STR);
	}
	
	for(i=0; i<3; i++)
	{//Ordena n�meros
		sort[selectedAlgorithm[i]](numbers, BUFFER_SORT_LEN, DATATYPE_INT);
    	utils_printResult(numbers, BUFFER_SORT_LEN, DATATYPE_INT);
	}
    	

    return 0;
}
#endif
