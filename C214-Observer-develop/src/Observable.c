#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Observable.h"
#include "Utils.h"

uint16_t Observable(char* phrase, char (*_words)[MAX_LEN_STRING])
{
    uint16_t j = 0, i = 0, wordLen;
    char* ptr = phrase;
    char (*words)[MAX_LEN_STRING] = _words;

    for(EVER)
    {
        if(*phrase++ == ' ')
        {//se encontrou um espaçoe ntão uma palavra foi identificada
        	wordLen = phrase - ptr;
            for(i = 0; (i < wordLen) && (*ptr != ' '); i++)
            {//Adiciona a palavra encontrada a matriz de palavras
                words[j][i] = *ptr++;
            }
            words[j][i] = '\0';
            ptr++;
            j++;
        }
        else if(*phrase == '\0')
        {//Se encontrou o final da string adiciona a ultima palavra e para o loop
        	wordLen = phrase - ptr;
            for(i = 0; i < wordLen; i++)
            {//Adiciona a palavra encontrada a matriz de palavras
                words[j][i] = *ptr++;
            }
            words[j][i] = '\0';
            j++;
            break;
        }
    }

    return j;
}