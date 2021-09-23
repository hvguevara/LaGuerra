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

/*Pre: @list es una List valida
 * Post: Crea y retorna un @SpanishDeck con el contenido de @list en cada elemento
 */
SpanishDeck* AssembleDeck(List* list);

/*Pre:@playerOne representa el mazo y @newOne reprensenta el mazo de manos ganadas por @playerOne..
 * .. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de manos ganadas por @playerTwo, todo son List* validas
 * Post: si la cantidad de elemento de @playerOne + @newOne es igual o menor que 2, devuelve -1..
 * ..si la cantidad de elemento de @playerTwo + @newTwo es igual o menor que 2, devuelve 1 y..
 * .. si tanto en @playerOne + @newOne como en @playerTwo + @newTwo hay 3 o mas elemento, devuelve 0
 */
int IsPossibleTie(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

/*Pre: @playerWin representa un mazo, @playerLose representa un mazo y @newLose reprensenta el mazo..
 * ..de manos ganadas por @playerLose, todas son @List validas
 * Post: quita todos los elementos contenidos en  @playerLose y @newLose, y los agrega a @playerWin
 */
void Finish(List* playerWin,List* playerLose,List* newLose);

/* Pre:@playerOne representa el mazo y @newOne reprensenta el mazo de manos ganadas por @playerOne..
 * .. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de manos ganadas por @playerTwo..
 * ..@tie representa los elementos que se encuentran en round empate en juego..
 * .. tanto la cantidad de elementos de @playerOne+@newOne como @playerTwo+@newTwo debe ser mayor a..
 * ..3. todo son List* validas
 * Post: realiza la accion comprendida en la situacion de empate en el juego de "la guerra"..
 * ..quita los ultimos 2 elementos de @playerOne y @playerTwo y los agrega a @tie, si en algun..
 * .. caso @playerOne y @playerTwo, mezclara el mazo de manos ganas correspondiente al jugar sin elementos..
 * .. lo asignara nuevamente al mazo en juego y seguira con la accion
 */
void RoundTie(List* playerOne, List* newOne, List* playerTwo, List* newTwo,List* tie);

/* Pre:@playerOne representa el mazo y @newOne reprensenta el mazo de manos ganadas por @playerOne..
 * .. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de manos ganadas por @playerTwo..
 * ..@tie representa los elementos que se encuentran en round empate en juego..
 * .. tanto la cantidad de elementos de @playerOne+@newOne como @playerTwo+@newTwo debe ser mayor a..
 * ..3. todo son List* validas
 * Post: realiza la accion comprendida en la situacion de empate en el juego de "la guerra"..
 * .. se quitan las primeras dos cartas de las pilas @playerOne y @playerTwo, se las agrega a @tie, luego..
 * .. se vuelve a quitar y comparar la primera carta de @playerOne y @playerTwo y el que tenga la..
 * .. alta, se lleva esas dos, mas las cartas que se asignaron a @tie, si vuelve a ocurrir un empate..
 * .. se vuelve a repetir el proceso hasta que haya un desempate, o hasta que uno de los @player se quede..
 * .. sin cartas tanto el mazo principal como en el @new, en ese caso, automaticamente el que quede sin..
 * .. cartas en ambos mazos, pierde el juego y se le asigna todas las cartas al ganador..
 * .. Si en algun caso, @playerOne y/o @playerTwo se vacian, se mezclaran @newOne y/o @newTwo y se le..
 * .. asignara a player que corresponda, si al comienzo de un empate alguno de los @player tiene..
 * .. menos de 3 cartas en @player+@new, automaticamente pierde la partida y se le asignas todas las cartas..
 * .. al otro @player.
 */
void Tie(List* playerOne, List* newOne, List* playerTwo, List* newTwo,List* tie);

/* Pre: @playerWin representa el mazo ganador y @newPlayerWin reprensenta el mazo de manos ganadas por..
 * .. @playerWin. @playerLoser representa el mazo perdedor, todas son List* validas, tanto @playerWin..
 * ..como @playerLoser deben tener, al menos 1 elemento.
 * Post: Se quita de la pila @playerWin y @playerLoser el primer elemento y se las asigna a @newPlayerWin
 */
void RoundWin(List* playerWin, List* playerLoser, List* newPlayerWin);

/* Pre: @deckOne y @deckTwo reprensentan mazos de cartas, ambas son List* validas
 * Post: suma y devuelve la cantidad de elementos(cartas) que contienen @deckOne y @deckTwo
 */
int CountCardPlayer(List* deckOne, List* deckTwo);

/* Pre:@playerWin representa el mazo y @newWin reprensenta el mazo de manos ganadas por @playerWin..
 * .. @playerLoser representa el mazo y @newLoser  reprensenta el mazo de manos ganadas por @playerLoser..
 * ..@tie representa los elementos que se encuentran en round empate en juego. todas son List* validas
 * Post: se quitan todos los elementos(cartas) de @playerLoser, @newLoser, @tie y @newWin y se los..
 * .. asigna a @playerWin,
 */
void WinForTie(List* playerWin, List* newWin, List* playerLoser, List* newLoser,List* tie);

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
	TypeGame::TypeTry::Demo(deck,playerOne,playerTwo);
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
	SetReplaceList(player,newPlayer);
	if(GetCountNode(newPlayer)>1){
		SpanishDeck* newDeck=AssembleDeck(player);
		newDeck=MixCard(newDeck);
		SetToEmpty(player);
		ParserDeckInList(newDeck,player);
	}
	SetToEmpty(newPlayer);
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
}

void TypeGame::TypeTry::Demo(SpanishDeck* deck, List* playerOne, List* playerTwo){
	int round=1;
	List* newOne=TypeList::CreateEmpty();
	List* newTwo=TypeList::CreateEmpty();
	while(IsEmpty(playerOne)==false and IsEmpty(playerTwo)==false){
		OtraPrueba(playerOne,newOne,playerTwo,newTwo);
		Round(playerOne,newOne,playerTwo,newTwo);
		DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
		round++;
	}
	cout<<"fin del juego"<<endl;
	DecideWin(playerOne,newOne,playerTwo,newTwo);
	cout<<"Victoria en "<<round<<" batallas"<<endl;
}

//
//

void RoundWin(List* playerWin, List* playerLoser, List* newPlayerWin){
	Node* one=UnStack(playerWin);
	Node* two=UnStack(playerLoser);
	SetPrevious(one,NULL);
	SetPrevious(two,NULL);
	Stack(newPlayerWin,one);
	Stack(newPlayerWin,two);
}

int CountCardPlayer(List* deckOne, List* deckTwo){
	if(GetCountNode(deckOne)>0){
		if(GetCountNode(deckTwo)>0){
			return GetCountNode(deckOne)+GetCountNode(deckTwo);
		}
		else{
			return GetCountNode(deckOne);
		}
	}
	else{
		if(GetCountNode(deckTwo)>0){
			return GetCountNode(deckTwo);
		}
		else{
			return 0;
		}
	}
}

int IsPossibleTie(List* playerOne, List* newOne, List* playerTwo, List* newTwo){
	if(CountCardPlayer(playerOne,newOne)>2 and CountCardPlayer(playerTwo,newTwo)>2){
		return 0;
	}
	else if(CountCardPlayer(playerOne,newOne)>2 and CountCardPlayer(playerTwo,newTwo)<3){
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

void TypeGame::Round(List* playerOne, List* newOne, List* playerTwo, List* newTwo){
	int result=IsMajor(GetCard(GetLast(playerOne)),GetCard(GetLast(playerTwo)));
	//WinRound(result);
	if(result==1){
		RoundWin(playerOne,playerTwo,newOne);
	}
	else if(result==-1){
		RoundWin(playerTwo,playerOne,newTwo);
	}
	else{
		List* tie=TypeList::CreateEmpty();
		Tie(playerOne,newOne,playerTwo,newTwo,tie);
		DestroyOnlyList(tie);
	}
}

void RoundTie(List* playerOne, List* newOne, List* playerTwo, List* newTwo,List* tie){
	DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
	OtraPrueba(playerOne,newOne,playerTwo,newTwo);
	RoundWin(playerTwo,playerOne,tie);
	DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
	OtraPrueba(playerOne,newOne,playerTwo,newTwo);
	RoundWin(playerTwo,playerOne,tie);
}

void WinForTie(List* playerWin, List* newWin, List* playerLoser, List* newLoser,List* tie){
	newWin=Concatenate(newWin, tie);
	newWin=Concatenate(newWin, playerLoser);
	newWin=Concatenate(newWin, newLoser);
	Concatenate(playerWin, newWin);
	SetToEmpty(playerLoser);
	SetToEmpty(newLoser);
	SetToEmpty(newWin);
}

void Tie(List* playerOne, List* newOne, List* playerTwo, List* newTwo,List* tie){
	int result=0;
	while(result==0){
		DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
		result=IsPossibleTie(playerOne,newOne,playerTwo,newTwo);
		if(result==1){
			WinForTie(playerOne, newOne,playerTwo, newTwo, tie);
		}
		else if(result==-1){
			WinForTie(playerTwo, newTwo,playerOne, newOne, tie);
		}
		else{
			RoundTie(playerOne,newOne,playerTwo,newTwo,tie);
			DecideResetDeck(playerOne,newOne,playerTwo,newTwo);
			result=IsMajor(GetCard(GetLast(playerOne)),GetCard(GetLast(playerTwo)));
			if(result==1){
				newOne=Concatenate(newOne, tie);
				RoundWin(playerOne, playerTwo, newOne);
			}
			else if(result==-1){
				newTwo=Concatenate(newTwo, tie);
				RoundWin(playerTwo, playerOne, newTwo);
			}
			else{
				OtraPrueba(playerOne,newOne,playerTwo,newTwo);
				RoundWin(playerOne, playerTwo,tie);
			}
		}
	}
}

void WinRound(int result){
	if(result==1){
		cout<<"Round Win Player One"<<endl;
	}
	else if(result==-1){
		cout<<"Round Win Player Two"<<endl;
	}
	else{
		cout<<" TIE ";
	}
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
