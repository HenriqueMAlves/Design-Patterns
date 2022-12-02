#include <stdio.h>
#include <stdint.h>
#include "Main.h"
#include "QuickSort.h"

/*********************************************************************************
 * Adapta a função de ordenação para o formato de "algorithmType"
 * 
 * @param data: ponteiro para o buffer que deve ser ordenado
 * @param len: Tamanho do buffer que será ordenado
 ********************************************************************************/
void quickSortConstructor(int16_t* data, uint16_t len, char* dataType)
{
	printf("Quick Sort selected...\n");
	quickSort(data, 0, len-1, len, dataType);
}

/*********************************************************************************
 * Ordena um vetor de inteiros ou caracteres utilizando o algoritmo quick sort
 * 
 * @param data: ponteiro para o buffer que deve ser ordenado
 * @param len: Tamanho do buffer que será ordenado
 ********************************************************************************/
void quickSort(int16_t* data, uint16_t left, uint16_t right, uint16_t len, char* dataType)
{
    static uint8_t turn = 0;
	int16_t pivot = left;
	uint16_t i,ch,j;
    
	         
    for(i = left + 1; i <= right; i++)
	{        
        j = i;                      
        if(data[j] < data[pivot])
		{     
            ch = data[j];               
            while(j > pivot)
			{           
                data[j] = data[j-1];      
                j--;                    
            }
            data[j] = ch;               
            pivot++;                    
        }
    }
    
    turn++;
    printf("[%d] ", turn);
    for(i=0; i<len; i++)
	{
		printf(dataType, data[i]);
		printf(" ");
	}
	printf("\n");
    
    if(pivot-1 >= left)
	{              
        quickSort(data, left, pivot-1, len, dataType);      
    }
    if(pivot+1 <= right)
	{              
        quickSort(data, pivot+1, right, len, dataType);      
    }
 }