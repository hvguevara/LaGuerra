#include <iostream>
#include "SpanishDeck.h"
#include "Card.h"
#include "String.h"
#include "Tools.h"

using namespace TypeSpanishDeck;
using namespace TypeSpanishDeck::TypePlayWar;
using TypeCard::Card;
using std::cout;
using std::endl;

typedef Card* Item;
#define ToExchange(itemA, itemB) {Item aux = itemA; itemA = itemB; itemB = aux;}

const int topeDeck=50;
const int topeTruco=40;

struct TypeSpanishDeck::SpanishDeck{
	Card* cards[topeDeck];
	int countCard;
};

SpanishDeck* TypeSpanishDeck::CreateEmpty(){
	SpanishDeck* newDeck=new SpanishDeck;
	for(int index=0;index<topeDeck;index++){
		newDeck->cards[index]=NULL;
	}
	newDeck->countCard=0;
	return newDeck;
}

SpanishDeck* TypeSpanishDeck::Create(){
	SpanishDeck* newDeck=CreateEmpty();
	for(int index=0;index<topeDeck;index++){
		newDeck->cards[index]= new Card(DecideSuit(index),DecideValue(index));
	}
	newDeck->countCard=topeDeck;
	return newDeck;
}

char* TypeSpanishDeck::DecideSuit(int OrderCard){
	if(OrderCard<12){
		return Copy("Espada");
	}
	else if(OrderCard<24){
		return Copy("Basto");
	}
	else if(OrderCard<36){
		return Copy("Oro");
	}
	else if(OrderCard<48){
		return Copy("Copa");
	}
	else{
		return Copy("Comodin");
	}
}

int TypeSpanishDeck::DecideValue(int OrderCard){
	if(OrderCard<48){
		while(OrderCard>11){
			OrderCard-=12;
		}
		OrderCard++;
	}
	else{
		OrderCard=13;
	}
	return OrderCard;
}

void TypeSpanishDeck::ViewDeck(SpanishDeck* deck){
	for(int index=0; index<deck->countCard; index++){
		deck->cards[index]->ViewCard();
	}
}


void TypeSpanishDeck::MixCard(SpanishDeck* deck){
	int* position=Mix(deck->countCard);
	for(int index=0;index<deck->countCard;index++){
		if(position[index]!=-1){
			ToExchange(deck->cards[index],deck->cards[position[index]]);
			position[index]=-1;
		}
	}
}

void TypeSpanishDeck::Destroy(SpanishDeck* deck){
	for(int index=0;index<topeDeck and deck->cards[index]!=NULL;index++){
		deck->cards[index]->~Card();
	}
	delete[] deck;
}

// TypeCheck

bool TypeSpanishDeck::TypeCheck::NotRepeatCard(SpanishDeck* deck){
	int init=1;
	for(int origin=0; origin<deck->countCard; origin++){
		for(int compare=init; compare<deck->countCard;compare++){
			if(deck->cards[origin]==deck->cards[compare]){
				return false;
			}
		}
		init++;
	}
	return true;
}

void TypeSpanishDeck::TypeCheck::RepeatCard(SpanishDeck* deck,int origin, int destiny){
	deck->cards[destiny]=deck->cards[origin];
}


