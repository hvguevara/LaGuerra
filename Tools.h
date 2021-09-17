#ifndef TOOLS_H_
#define TOOLS_H_

//Pre: @maxPosition es un entero mayor que 0
//Post: crea y devuelve un vector de enteros con la cantidad de @maxPosition, con el orden de numeros mezclado al azar
int* Mix(int maxPosition);

//Pre: @max es un entero mayor que 0
//Post: devuelve un entero aleatorio entre 0 y @max
int GetRandom(int max);

#endif /* TOOLS_H_ */
