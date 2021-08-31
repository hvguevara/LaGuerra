#include <iostream>
#include "Card.h"
using std::cout;
using std::endl;
using namespace TypeCard;

TypeCard::Card::Card(char* newSuit,int newValue){
	suit=newSuit;
	value=newValue;
}

TypeCard::Card::~Card(){
	delete[] suit;
}

void TypeCard::Card::ViewCard(){
	cout<<"["<<value<<" "<<suit<<"]";
}

char* TypeCard::Card::GetSuit(){
	return suit;
}

int TypeCard::Card::GetValue(){
	return value;
}

//
int TypeCard::TypePlayWar::IsMajor(Card* origin, Card* compare){
	if(origin->GetValue()==compare->GetValue()){
		return 0;
	}
	else{
		if(origin->GetValue()==1){
			return 1;
		}
		else if(compare->GetValue()==1){
			return -1;
		}
		else if(origin->GetValue()>compare->GetValue()){
			return 1;
		}
		else{
			return -1;
		}
	}
}
