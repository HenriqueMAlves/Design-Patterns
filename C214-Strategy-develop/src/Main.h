
//Define para controlar o tipo de entrada: letras ("%c") ou n�meros ("%d") 
#define DATATYPE_STR "%c"
#define DATATYPE_INT "%d"

#define BUFFER_SORT_LEN 6

//Enum para definir tamanho máximo do vetor de algoritmos
typedef enum ENUM_SORT_ALGORITHM{
	BUBBLE_SORT,
	INSERTION_SORT,
	QUICK_SORT,
	NUM_MAX_ALGORITHM
}algorithm_t;