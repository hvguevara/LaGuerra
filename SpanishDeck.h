#ifndef SPANISHDECK_H_
#define SPANISHDECK_H_

#include "Node.h"
using TypeNode::Node;

namespace TypeSpanishDeck{
	struct SpanishDeck;

	/* Pre: -
	 * Post: Crea y devuelve un vector SpanishDeck* con la cantidad de elementos vacios de una mazo de cartas espaniolas
	 */
	SpanishDeck* CreateEmpty();

	/* Pre: -
	 * Post: Crea y devuelve un vector SpanishDeck* con la cantidad de elementos(cartas) de una mazo ..
	 * ..de cartas espaniolas ordenados y 50 cartas
	 */
	SpanishDeck* Create();

	/* Pre: @OrderCard es una entero valido <=50
	 * Post: si @OrderCard es menor a 12, devuelve un char* con "Espada" como contenido..
	 * .. si @OrderCard es menor a 24, devuelve un char* con "Basto" como contenido..
	 * .. si @OrderCard es menor a 36, devuelve un char* con "Oro" como contenido..
	 * .. si @OrderCard es menor a 48, devuelve un char* con "Copa" como contenido..
	 * .. sino devuelve un char* con "Comodin" como contenido
	 */
	char* DecideSuit(int OrderCard);

	/* Pre: @OrderCard es una entero valido <=50
	 * Post: si @OrderCard es menor a 12, devuelve @OrderCard+1..
	 * .. si @OrderCard es mayor a 12 pero menor a 48, resta..
	 * .. sino devuelve 13
	 */
	int DecideValue(int OrderCard);

	/* Pre:
	 * Post:
	 */
	int GetCountCard(SpanishDeck* deck);

	/* Pre:
	 * Post:
	 */
	Node* GetNode(SpanishDeck* deck, int position);

	/* Pre:
	 * Post:
	 */
	int SearchCard(SpanishDeck* deck, Node* card);

	/* Pre:
	 * Post:
	 */
	void Add(SpanishDeck* deck, Node* newCard);

	/* Pre:
	 * Post:
	 */
	void Remove(SpanishDeck* deck, Node* newCard);

	/* Pre:
	 * Post:
	 */
	void ViewDeck(SpanishDeck* deck);

	/* Pre:
	 * Post:
	 */
	SpanishDeck* MixCard(SpanishDeck* deck);

	/* Pre:
	 * Post:
	 */
	void DestroyDeck(SpanishDeck* deck);

	/* Pre:
	 * Post:
	 */
	void Destroy(SpanishDeck* deck);

	namespace TypeCheck{

		/* Pre:
		 * Post:
		 */
		bool NotRepeatCard(SpanishDeck* deck);

		/* Pre:
		 * Post:
		 */
		void RepeatCard(SpanishDeck* deck,int origin, int destiny);
	}
}

#endif /* SPANISHDECK_H_ */
