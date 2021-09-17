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

	//Pre: Programa Raiz
	//Pos: es la programa principal, encargado de controlar la funciones del juego
	void Play();

	//Pre: @deck es un SpanishDeck valido y @player es una List* valida vacia
	//Pos: carga en @player todo el contenido de @deck
	void ParserDeckInList(SpanishDeck* deck, List* player);

	//Pre: @deck es un SpanishDeck valido. @playerOne y @playerTwo son List* validas y vacia
	//Pos: Distribuye el contenido de @deck en @playerOne y en @playerTwo, alternando un elemento..
	//..para @playerOne y otro para @playerTwo hasta que se agote el contenido de @deck
	void Distribute(SpanishDeck* deck, List* playerOne, List* playerTwo);//Distribute(SpanishDeck* deck, SpanishDeck* playerOne, SpanishDeck* playerTwo);

	//Pre: @playerOne representa el mazo y @newOne reprensenta el mazo de mano ganadas por @playerOne..
	//.. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de mano ganadas por @playerTwo, todo son List* validas
	//Pos: funcion encargada de realizar un mano de la partida entre los jugadores @playerOne y @playerTwo
	void Round(List* playerOne, List* newOne, List* playerTwo, List* newTwo);//Round(SpanishDeck* playerOne, int indexOne, SpanishDeck* playerTwo, int indexTwo);

	//Pre: @playerOne representa el mazo y @newOne reprensenta el mazo de mano ganadas por @playerOne..
	//.. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de mano ganadas por @playerTwo, todo son List* validas
	//Pos: si @playerOne esta vacio y @newOne no lo esta, reemplaza @playerOne por @newOne mezclado..
	//.. y/o si @playerTwo esta vacio y @newTwo no lo esta, reemplaza @playerTwo por @newTwo mezclado..
	//.. para el resto de los casos, no hace nada
	void DecideResetDeck(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

	//Pre: @playerOne representa el mazo y @newOne reprensenta el mazo de mano ganadas por @playerOne..
	//.. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de mano ganadas por @playerTwo, todo son List* validas
	//Pos: si @playerOne o @newOne o ambos no estan vacios, muestra por pantalla como ganador a @playerOne..
	//.. sino muestra por pantalla como ganador a @playerTwo
	void DecideWin(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

	namespace TypeTry{

		//Pre:
		//Pos:
		void Prueba(List* playerOne, List* playerTwo);//Prueba(SpanishDeck* deck, SpanishDeck* playerOne, SpanishDeck* playerTwo);

		void Demo(SpanishDeck* deck, List* playerOne, List* playerTwo);//Demo(SpanishDeck* deck, SpanishDeck* playerOne, SpanishDeck* playerTwo);
	}

}




#endif /* PLAYWAR_H_ */
