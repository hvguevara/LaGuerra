#include <iostream>
#include "PlayWar.h"
#include "Card.h"
#include "Node.h"
#include "List.h"
#include "SpanishDeck.h"
using std::cout;
using std::endl;
using namespace TypeCard;
using namespace TypeCard::TypePlayWar;
using namespace TypeSpanishDeck;
using namespace TypeGame;
using namespace TypeNode;
using namespace TypeGame::TypeTry;
using namespace TypeList;

//Pre:
//Post:
SpanishDeck* AssembleDeck(List* list);

//Pre:
//Post:
int IsPossibleTie(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

//
//
void Finish(List* playerWin,List* playerLose,List* newLose);

//
//
void RoundTie(List* playerOne, List* newOne, List* playerTwo, List* newTwo,List* tie);

void OtraPrueba(List* playerOne, List* newOne, List* playerTwo, List* newTwo){
	cout<<"One("<<GetCountNode(playerOne)<<"+"<<GetCountNode(newOne)<<"): ";
	GetCard(GetLast(playerOne))->ViewCard();
	cout<<" <-> ";
	GetCard(GetLast(playerTwo))->ViewCard();
	cout<<"Two("<<GetCountNode(playerTwo)<<"+"<<GetCountNode(newTwo)<<"): ";
	cout<<"  -----> Total "<<GetCountNode(playerOne)+GetCountNode(newOne)+GetCountNode(playerTwo)+GetCountNode(newTwo);
	if(GetCountNode(playerOne)>1 and GetCountNode(playerTwo)>1){
		GetCard(GetPrevious(GetLast(playerOne)))->ViewCard();
		cout<<" - ";
		GetCard(GetPrevious(GetLast(playerTwo)))->ViewCard();
		cout<<endl;
	}
	else if(GetCountNode(playerOne)==1 and GetCountNode(playerTwo)>1){
		cout<<" NULL - ";
		GetCard(GetPrevious(GetLast(playerTwo)))->ViewCard();
		cout<<endl;
	}
	else if(GetCountNode(playerTwo)==1 and GetCountNode(playerOne)>1){
		GetCard(GetPrevious(GetLast(playerOne)))->ViewCard();
		cout<<" - NULL"<<endl;
	}
	else{
		cout<<" NULL - NULL"<<endl;
	}
}

void TypeGame::Play(){
	SpanishDeck* deck = Create();
	List* playerOne=TypeList::CreateEmpty();
	List* playerTwo=TypeList::CreateEmpty();
	deck=MixCard(deck);
	Distribute(deck, playerOne, playerTwo);
	//cout<<"paso"<<endl;
	//Prueba(playerOne,playerTwo);
	TypeGame::TypeTry::Demo(deck,playerOne,playerTwo);
	//TypeGame::TypeTry::Prueba(deck, playerOne,playerTwo);
}

void TypeGame::Distribute(SpanishDeck* deck, List* playerOne, List* playerTwo){
	int distribute=0;
	for(int index=0;index<GetCountCard(deck);index++){
		if(distribute==0){
			Stack(playerOne,GetNode(deck,index));
			distribute=1;
		}
		else{
			Stack(playerTwo,GetNode(deck,index));
			distribute=0;
		}
	}
}

void TypeGame::ParserDeckInList(SpanishDeck* deck, List* player){
	for(int index=0;index<GetCountCard(deck);index++){
		SetPrevious(GetNode(deck,index),NULL);
		TypeList::Stack(player,GetNode(deck,index));
	}
}

void ResetDeck(List* player, List* newPlayer){
	//cout<<"entro a ResetDeck"<<endl;
	Prueba(player,newPlayer);
	SetReplaceList(player,newPlayer);
	if(GetCountNode(newPlayer)>1){
		SpanishDeck* newDeck=AssembleDeck(player);
		newDeck=MixCard(newDeck);
		SetToEmpty(player);
		ParserDeckInList(newDeck,player);
	}
	SetToEmpty(newPlayer);
	Prueba(player,newPlayer);
	//cout<<"Salio de ReserDeck"<<endl;
}

SpanishDeck* AssembleDeck(List* list){
	Node* iterator=GetLast(list);
	SpanishDeck* newDeck=TypeSpanishDeck::CreateEmpty();
	while(iterator!=NULL){
		Add(newDeck,iterator);
		iterator=GetPrevious(iterator);
	}
	return newDeck;
}

void TypeGame::DecideResetDeck(List* playerOne, List* newOne, List* playerTwo, List* newTwo){
	//cout<<"entro a DecideResetDeck"<<endl;
	if(GetCountNode(playerOne)==0 and GetCountNode(newOne)!=0 and GetCountNode(playerTwo)==0 and GetCountNode(newTwo)!=0){
		ResetDeck(playerOne, newOne);
		ResetDeck(playerTwo, newTwo);
	}
	else if(GetCountNode(playerOne)==0 and GetCountNode(newOne)!=0){
		ResetDeck(playerOne, newOne);
	}
	else if(GetCountNode(playerTwo)==0 and GetCountNode(newTwo)!=0){
		ResetDeck(playerTwo, newTwo);
	}
	//cout<<"salio de DecideResetDeck"<<endl;
}

void TypeGame::TypeTry::Demo(SpanishDeck* deck, List* playerOne, List* playerTwo){
	int round=1;
	List* newOne=TypeList::CreateEmpty();
	List* newTwo=TypeList::CreateEmpty();
	while(IsEmpty(playerOne)==false and IsEmpty(playerTwo)==false){
		//Prueba(newOne,newTwo);
		//cout<<round<<" ";
		OtraPrueba(playerOne,newOne,playerTwo,newTwo);
		Round(playerOne,newOne,playerTwo,newTwo);
		DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
		round++;
		cout<<endl;
	}
	cout<<"fin del juego"<<endl;
	DecideWin(playerOne,newOne,playerTwo,newTwo);
	cout<<"Victoria en "<<round<<" batallas"<<endl;
}

//
//

void win(List* playerOne, List* playerTwo, List* newOne){
	Node* one=UnStack(playerOne);
	Node* two=UnStack(playerTwo);
	SetPrevious(one,NULL);
	SetPrevious(two,NULL);
	Stack(newOne,one);
	Stack(newOne,two);
}

int IsPossibleTie(List* playerOne, List* newOne, List* playerTwo, List* newTwo){
	if(GetCountNode(playerOne)+GetCountNode(newOne)>2 and GetCountNode(playerTwo)+GetCountNode(newTwo)>2 ){
		return 0;
	}
	else if(GetCountNode(playerOne)+GetCountNode(newOne)<3){
		return -1;
	}
	else{
		return 1;
	}
}

void Finish(List* playerWin,List* playerLose,List* newLose){
	if(IsEmpty(playerLose)!=true){
		Concatenate(playerWin, playerLose);
		SetToEmpty(playerLose);
		if(IsEmpty(newLose)!=true){
			Concatenate(playerWin, newLose);
			SetToEmpty(newLose);
		}
	}
	else if(IsEmpty(newLose)!=true){
		Concatenate(playerWin, newLose);
		SetToEmpty(newLose);
	}
}

void RoundTie(List* playerOne, List* newOne, List* playerTwo, List* newTwo,List* tie){
	DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
	win(playerTwo,playerOne,tie);
	DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
	win(playerTwo,playerOne,tie);
}

void Tie(List* playerOne, List* newOne, List* playerTwo, List* newTwo,List* tie){
	//cout<<"entro a Tie"<<endl;/*IsMajor(GetCard(GetLast(playerOne)),GetCard(GetLast(playerTwo)));OtraPrueba(playerOne,newOne,playerTwo,newTwo);*/OtraPrueba(playerOne,newOne,playerTwo,newTwo);
	bool finish=false;
	int result;
	win(playerOne,playerTwo,newOne);
	/*
	while(finish!=true){
		DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
		result=IsPossibleTie(playerOne,newOne,playerTwo,newTwo);
		if(result==0){
			RoundTie(playerOne,newOne,playerTwo,newTwo,tie);
			result=IsMajor(GetCard(GetLast(playerOne)),GetCard(GetLast(playerTwo)));
			if(result==1){
				win(playerTwo,playerOne,tie);
				Concatenate(newOne,tie);
				SetToEmpty(tie);
				finish=true;
			}
			else if(result==-1){
				win(playerTwo,playerOne,tie);
				Concatenate(newTwo,tie);
				SetToEmpty(tie);
				finish=true;
			}
		}
		else if(result==1){
			Concatenate(newOne,tie);
			Finish(playerOne,playerTwo,newTwo);
			finish=true;
			cout<<"WIN ONE"<<endl;
		}
		else{
			Concatenate(newTwo,tie);
			Finish(playerTwo,playerOne,newOne);
			finish=true;
			cout<<"WIN TWO"<<endl;
		}
	}*/

	//cout<<"Salio de Tie"<<endl;
}

void WinRound(int result){
	if(result==1){
		//cout<<"Round Win Player One"<<endl;
	}
	else if(result==-1){
		//cout<<"Round Win Player Two"<<endl;
	}
	else{
		//cout<<" TIE ";
	}
}

void TypeGame::Round(List* playerOne, List* newOne, List* playerTwo, List* newTwo){
	//cout<<"entro a Round"<<endl;
	int result=IsMajor(GetCard(GetLast(playerOne)),GetCard(GetLast(playerTwo)));
	WinRound(result);
	if(result==1){
		win(playerOne,playerTwo,newOne);
	}
	else if(result==-1){
		win(playerTwo,playerOne,newTwo);
	}
	else{
		List* tie=TypeList::CreateEmpty();
		Tie(playerOne,newOne,playerTwo,newTwo,tie);
		DestroyList(tie);
		//Prueba(playerOne,playerTwo);
	}
	//cout<<"salio de Round"<<endl;
}

void TypeGame::DecideWin(List* playerOne, List* newOne, List* playerTwo, List* newTwo){
	if(IsEmpty(playerOne)==false or IsEmpty(newOne)==false){
		Concatenate(playerOne,newOne);
		cout<<"----- PLAYER ONE WIIIIN -----"<<endl;
		View(playerOne);
		cout<<endl<<GetCountNode(playerOne);
		cout<<" cartas"<<endl;
	}
	else{
		Concatenate(playerTwo,newTwo);
		cout<<"----- PLAYER TWO WIIIIN -----"<<endl;
		View(playerTwo);
		cout<<endl<<GetCountNode(playerTwo);
		cout<<" cartas"<<endl;
	}
}

void TypeGame::TypeTry::Prueba(List* playerOne, List* playerTwo){
	cout<<"playerOne ("<<GetCountNode(playerOne)<<" cartas)"<<endl;
	View(playerOne);
	cout<<endl<<"playerTwo ("<<GetCountNode(playerTwo)<<" cartas)"<<endl;
	View(playerTwo);
	cout<<endl<<"------------"<<endl;
}
