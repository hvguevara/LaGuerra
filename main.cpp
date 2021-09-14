#include <iostream>
#include "SpanishDeck.h"
#include "PlayWar.h"
using namespace std;
using namespace TypeSpanishDeck;
using namespace TypeCheck;
using namespace TypeGame;

int main() {
	/*
	SpanishDeck* deck=Create();
	ViewDeck(deck);
	cout<<endl<<"ahora mezclar"<<endl;
	MixCard(deck);
	if(NotRepeatCard(deck)==true){
		cout<<"Not repet card"<<endl;
	}
	else{
		cout<<"FFFF"<<endl;
	}
	cout<<"Otro"<<endl;
	RepeatCard(deck, 1,3);
	if(NotRepeatCard(deck)==false){
		cout<<"ok"<<endl;
	}
	else{
		cout<<"FFFF"<<endl;
	}
	ViewDeck(deck);*/
	Play();
	return 0;
}
