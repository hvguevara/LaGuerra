#include <iostream>
#include "SpanishDeck.h"
#include "String.h"
#include "Tools.h"
#include "Node.h"

using namespace TypeSpanishDeck;
using namespace TypeNode;
using std::cout;
using std::endl;

typedef Node* Item;
#define ToExchange(itemA, itemB) {Item aux = itemA; itemA = itemB; itemB = aux;}

const int topeDeck=50;
const int topeTruco=40;

struct TypeSpanishDeck::SpanishDeck{
	Node* cards[topeDeck];
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
		newDeck->cards[index]= TypeNode::Create(new Card(DecideSuit(index),DecideValue(index)));
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

int TypeSpanishDeck::GetCountCard(SpanishDeck* deck){
	return deck->countCard;
}

Node* TypeSpanishDeck::GetNode(SpanishDeck* deck, int position){
	return deck->cards[position];
}

void TypeSpanishDeck::Add(SpanishDeck* deck, Node* newCard){
	deck->cards[deck->countCard]=newCard;//new Card(Copy(newCard->GetSuit()),newCard->GetValue());
	deck->countCard++;
}

void TypeSpanishDeck::Remove(SpanishDeck* deck, Node* removeCard){
	int position=SearchCard(deck,removeCard);
	if(position!=-1){
		deck->cards[position]=NULL;
		deck->countCard--;
		for(int index=position;index<deck->countCard;index++){
			deck->cards[position]=deck->cards[position+1];
		}
	}
}

int TypeSpanishDeck::SearchCard(SpanishDeck* deck, Node* card){
	for(int index=0;index<deck->countCard;index++){
		if(GetValues(deck->cards[index])==GetValues(card) and IsEqual(GetSuit(deck->cards[index]),GetSuit(card))){
			return index;
		}
	}
	return -1;
}
void TypeSpanishDeck::ViewDeck(SpanishDeck* deck){
	for(int index=0; index<deck->countCard; index++){
		View(deck->cards[index]);
	}
}

SpanishDeck* TypeSpanishDeck::MixCard(SpanishDeck* deck){
	int* position=Mix(deck->countCard);
	for(int index=0;index<deck->countCard;index++){
		if(position[index]!=-1){
			ToExchange(deck->cards[index],deck->cards[position[index]]);
			position[index]=-1;
		}
	}
	return deck;
}

void TypeSpanishDeck::DestroyDeck(SpanishDeck* deck){
	delete[] deck;
}

void TypeSpanishDeck::Destroy(SpanishDeck* deck){
	for(int index=0;index<topeDeck and deck->cards[index]!=NULL;index++){
		Destroy(deck->cards[index]);
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


