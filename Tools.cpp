#include <time.h>
#include <stdlib.h>
#include "Tools.h"

#include <iostream>
using std::cout;
using std::endl;

//srand(time(NULL));

void CompleteVector(int vector[], int max){
	for (int index=0;index<max;index++){
		vector[index]=index;
	}
}
int* Mix(int maxPosition){
	int notMix=maxPosition, random, newPosition=0;
	int order[maxPosition];
	CompleteVector(order,maxPosition);
	int* position=new int[maxPosition];
	srand(time(NULL));
	while(newPosition<maxPosition){
		random=GetRandomPosition(maxPosition);
		if(order[random]==random){
			order[random]=-1;
			position[newPosition]=random;
			newPosition++;
		}
	}
	return position;
}

int GetRandomPosition(int maxPosition){
	return rand() % maxPosition;
}

