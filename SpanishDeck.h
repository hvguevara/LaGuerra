#ifndef SPANISHDECK_H_
#define SPANISHDECK_H_

#include "Node.h"
using TypeNode::Node;

namespace TypeSpanishDeck{
	struct SpanishDeck;

	//PreCondicion:
	//PostCondicion:
	SpanishDeck* CreateEmpty();

	//PreCondicion:
	//PostCondicion:
	SpanishDeck* Create();

	//PreCondicion:
	//PostCondicion:
	char* DecideSuit(int OrderCard);

	//PreCondicion:
	//PostCondicion:
	int DecideValue(int OrderCard);

	//Pre:
	//Pos:
	int GetCountCard(SpanishDeck* deck);

	//Pre:
	//Pos:
	Node* GetNode(SpanishDeck* deck, int position);

	//Pre:
	//Pos:
	int SearchCard(SpanishDeck* deck, Node* card);

	//Pre:
	//Pos:
	void Add(SpanishDeck* deck, Node* newCard);

	//Pre:
	//Pos:
	void Remove(SpanishDeck* deck, Node* newCard);

	//PreCondicion:
	//PostCondicion:
	void ViewDeck(SpanishDeck* deck);

	//PreCondicion:
	//PostCondicion:
	SpanishDeck* MixCard(SpanishDeck* deck);

	void DestroyDeck(SpanishDeck* deck);

	//PreCondicion:
	//PostCondicion:
	void Destroy(SpanishDeck* deck);

	namespace TypeCheck{

		//PreCondicion:
		//PostCondicion:
		bool NotRepeatCard(SpanishDeck* deck);

		//PreCondicion:
		//PostCondicion:
		void RepeatCard(SpanishDeck* deck,int origin, int destiny);
	}

}


#endif /* SPANISHDECK_H_ */
