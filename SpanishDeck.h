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
	 * Post: retorna el valor correspondiente segun el orden de una baraja de cartas espaniolas ordenadas
	 */
	int DecideValue(int OrderCard);

	/* Pre: @deck es una SpanishDeck* valida
	 * Post: retorna la cantidad de elementos(cartas) de @deck
	 */
	int GetCountCard(SpanishDeck* deck);

	/* Pre: @deck es una SpanishDeck* valida y @position es una posicion valida de @deck
	 * Post:devuelve el Node* de alojado en la posicion @position  de @deck
	 */
	Node* GetNode(SpanishDeck* deck, int position);

	/* Pre: @deck es una SpanishDeck* valida y @card es un Node* valido no vacio
	 * Post: Si @card existe dentro de @deck, devuelve la posicion, sino devuelve -1
	 */
	int SearchCard(SpanishDeck* deck, Node* card);

	/* Pre: @deck es una SpanishDeck* valida y @newCard es un Node* valido no vacio
	 * Post: Si hay espacio disponible en @deck, agrega a @newCard en la primer posicion vacia que se encuentre
	 */
	void Add(SpanishDeck* deck, Node* newCard);

	/* Pre: @deck es una SpanishDeck* valida y @removeCard es un Node* valido no vacio
	 * Post: Si existe @removeCard en @deck, solamente lo remueve y si a continuacion habian mas elementos..
	 * .. los reordena para que no queden espacio vacio en medio. si no existe, no hace nada.
	 */
	void Remove(SpanishDeck* deck, Node* removeCard);

	/* Pre: @deck es una SpanishDeck* valida
	 * Post: Muestra por pantalla todo el contenido de @deck
	 */
	void ViewDeck(SpanishDeck* deck);

	/* Pre: @deck es una SpanishDeck* valida
	 * Post: devuelve @deck con todos sus elementos mezclados al azar
	 */
	SpanishDeck* MixCard(SpanishDeck* deck);

	/* Pre: @deck es una SpanishDeck* valida
	 * Post: solamente libera los recursos utilizados por @deck, no libera los recursos de su contenido
	 */
	void DestroyDeck(SpanishDeck* deck);

	/* Pre: @deck es una SpanishDeck* valida
	 * Post: libera todos los recursos utilizados por @deck
	 */
	void Destroy(SpanishDeck* deck);

	namespace TypeCheck{

		/* Pre: @deck es una SpanishDeck* valida
		 * Post: si no hay ningun elemento repetido dentro de @deck, devuelve true. sino false
		 */
		bool NotRepeatCard(SpanishDeck* deck);

		/* Pre: @deck es una SpanishDeck* valida. @origin y @destiny son posiciones validas de @deck
		 * Post: si @origin y @destiny se encuentran dentro del rango permitido, pisa lo que habia en la..
		 * posicion @destiny de @deck, con lo que se encuentra en la posicion @origin de @deck
		 */
		void RepeatCard(SpanishDeck* deck,int origin, int destiny);
	}
}

#endif /* SPANISHDECK_H_ */
