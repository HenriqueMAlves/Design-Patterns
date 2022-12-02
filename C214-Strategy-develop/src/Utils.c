#include <stdio.h>
#include <stdint.h>

void utils_printResult(int16_t* buf, uint8_t len, char* dataType)
{
	uint8_t i = 0;
	
	printf("\n\nresult --> ");
    for(i=0; i<len; i++)
		  printf(dataType, buf[i]);
    printf("\n\r\n\r");
}