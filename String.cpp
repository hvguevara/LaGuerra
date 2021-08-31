#include <iostream>
#include "String.h"

char* Create(int size){
	char* newWord=new char[size+1];
	return newWord;
}

char* Copy(char word[]){
	int size=CountChar(word);
	char* newWord=Create(size);
	for(int index=0;index<size;index++){
		newWord[index]=word[index];
	}
	return newWord;
}

int CountChar(char word[]){
	int size=0;
	while(word[size]!='\0'){
		size++;
	}
	return size;
}
