#ifndef SPANISHDECK_H_
#define SPANISHDECK_H_

#include "Card.h"
using TypeCard::Card;

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

	//PreCondicion:
	//PostCondicion:
	void ViewDeck(SpanishDeck* deck);

	//PreCondicion:
	//PostCondicion:
	void MixCard(SpanishDeck* deck);

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
