#ifndef STRING_H_
#define STRING_H_

//Pre: @size es un entero distindo mayor que 0
//Pos: crea y devuelve una cadena de caractes de tamaño @size+1 contando '\0'
char* Create(int size);

//Pre: @word es una cadena de caracteres valida
//Pos: crea y devuelve una copia de @word
char* Copy(char word[]);

//Pre: @word es una cadena de caracteres valida
//Pos: devuelve la cantidad de caracteres que tiene @word
int CountChar(char* word);

//Pre: @origin y @compare son cadenas de caracteres validas
//Pos: si @origin y @compare son iguales, devuelve true, de lo contrario, devuelve false
bool IsEqual(char* origin, char* compare);


#endif /* STRING_H_ */
