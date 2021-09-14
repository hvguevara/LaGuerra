#ifndef PLAYWAR_H_
#define PLAYWAR_H_

#include "Card.h"
#include "Node.h"
#include "SpanishDeck.h"
#include "List.h"
using TypeCard::Card;
using TypeSpanishDeck::SpanishDeck;
using TypeNode::Node;
using TypeList::List;

namespace TypeGame{

	//Pre:
	//Pos:
	void Play();

	//Pre:
	//Pos:
	void ParserDeckInList(SpanishDeck* deck, List* player);

	//Pre:
	//Pos:
	void Distribute(SpanishDeck* deck, List* playerOne, List* playerTwo);//Distribute(SpanishDeck* deck, SpanishDeck* playerOne, SpanishDeck* playerTwo);

	//Pre:
	//Pos:
	void Round(List* playerOne, List* newOne, List* playerTwo, List* newTwo);//Round(SpanishDeck* playerOne, int indexOne, SpanishDeck* playerTwo, int indexTwo);

	void DecideResetDeck(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

	void DecideWin(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

	namespace TypeTry{
		//Pre:
		//Pos:
		void Prueba(List* playerOne, List* playerTwo);//Prueba(SpanishDeck* deck, SpanishDeck* playerOne, SpanishDeck* playerTwo);

		void Demo(SpanishDeck* deck, List* playerOne, List* playerTwo);//Demo(SpanishDeck* deck, SpanishDeck* playerOne, SpanishDeck* playerTwo);
	}

}




#endif /* PLAYWAR_H_ */
