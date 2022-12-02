#include <stdio.h>
#include <stdint.h>
#include "BubbleSort.h"
#include "Main.h"

/*********************************************************************************
 * Adapta a função de ordenação para o formato de "algorithmType"
 * 
 * @param data: ponteiro para o buffer que deve ser ordenado
 * @param len: Tamanho do buffer que será ordenado
 ********************************************************************************/
void bubbleSortConstructor(int16_t* data, uint16_t len, char* dataType)
{
	printf("Bubble Sort selected...\n");
	bubbleSort(data, len, dataType);
}

/*********************************************************************************
 * Ordena um vetor de inteiros ou caracteres utilizando o algoritmo bubble sort
 * 
 * @param data: ponteiro para o buffer que deve ser ordenado
 * @param len: Tamanho do buffer que será ordenado
 ********************************************************************************/
void bubbleSort(int16_t* data, uint16_t len, char* dataType) 
{
    uint16_t i, j, aux;

    for(i = 1; i < len; i++) 
    {
        printf("\n[%d] ", i);

        for(j = 0; j < len - 1; j++) 
        {

            if(data[j] > data[j + 1]) 
            {
                aux = data[j];
                data[j] = data[j + 1];
                data[j + 1] = aux;
            }
            printf(dataType, data[j]);
            printf(", ");
        }
        printf(dataType, data[j]);
    }
}