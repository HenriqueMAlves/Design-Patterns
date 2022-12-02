#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Observable.h"
#include "Utils.h"

uint16_t ObserverAllWords(char* phrase, int active)
{
	uint16_t numWords = 0, i, j;
	char words[MAX_LEN_STRING][MAX_LEN_STRING];
	
	if(active == TRUE)
	{
		numWords = Observable(phrase, &(*words));
		
		for(i = 0; i < numWords; i++)
	    {//Printa as palavras
	    	for(j = 0; words[i][j] != '\0'; j++)
	        	printf("%c", words[i][j]);
	        printf("\n");
	    }		
	}
	
	return numWords;
}

uint16_t ObserverEvenWords(char* phrase, int active)
{
	uint16_t numWords = 0, numEvenWords = 0, i, j;
	char words[MAX_LEN_STRING][MAX_LEN_STRING];
	char evenWords[MAX_LEN_STRING][MAX_LEN_STRING];
	
	if(active == TRUE)
	{
		numWords = Observable(phrase, words);
		
		for(i = 0; i < numWords; i++)
		{
			if((strlen(words[i])%2) == 0)
			{//Se numero de caracteres for par
				strcpy(evenWords[numEvenWords], words[i]);
				numEvenWords++;
			}
		}
		
		for(i = 0; i <= numEvenWords; i++)
	    {//Printa as palavras
	    	for(j = 0; evenWords[i][j] != '\0'; j++)
	        	printf("%c", evenWords[i][j]);
	        printf("\n");
	    }		
	}
	
	return numWords;
}

uint16_t ObserverUppercaseWords(char* phrase, int active)
{
	uint16_t numWords = 0, numEvenWords = 0, i, j;
	char words[MAX_LEN_STRING][MAX_LEN_STRING];
	char evenWords[MAX_LEN_STRING][MAX_LEN_STRING];
	
	if(active == TRUE)
	{
		numWords = Observable(phrase, words);
		
		for(i = 0; i < numWords; i++)
		{
			if(words[i][0] <= 'Z')//Considerando que na tabela ASCII as letras maiúsculas tem valor menor que as minúsculas
			{//Se numero de caracteres for par
				strcpy(evenWords[numEvenWords], words[i]);
				numEvenWords++;
			}
		}
		
		for(i = 0; i < numEvenWords; i++)
	    {//Printa as palavras
	    	for(j = 0; evenWords[i][j] != '\0'; j++)
	        	printf("%c", evenWords[i][j]);
	        printf("\n");
	    }		
	}
	
	return numWords;
}