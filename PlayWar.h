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

	/* Pre: -
	 * Post: programa encargado de controlar y garantizar la jugabilidad de "LaGuerra"
	 */
	void TheWar(SpanishDeck* deck, List* playerOne, List* playerTwo);

	//Pre: @deck es un SpanishDeck valido y @player es una List* valida vacia
	//Pos: carga en @player todo el contenido de @deck
	void ParserDeckInList(SpanishDeck* deck, List* player);

	//Pre: @deck es un SpanishDeck valido. @playerOne y @playerTwo son List* validas y vacia
	//Pos: Distribuye el contenido de @deck en @playerOne y en @playerTwo, alternando un elemento..
	//..para @playerOne y otro para @playerTwo hasta que se agote el contenido de @deck
	void Distribute(SpanishDeck* deck, List* playerOne, List* playerTwo);

	//Pre: @playerOne representa el mazo y @newOne reprensenta el mazo de mano ganadas por @playerOne..
	//.. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de mano ganadas por @playerTwo, todo son List* validas
	//Pos: funcion encargada de realizar un mano de la partida entre los jugadores @playerOne y @playerTwo
	void Round(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

	/* Pre: @playerWin representa el mazo ganador y @newPlayerWin reprensenta el mazo de manos ganadas por..
	 * .. @playerWin. @playerLoser representa el mazo perdedor, todas son List* validas, tanto @playerWin..
	 * ..como @playerLoser deben tener, al menos 1 elemento.
	 * Post: Se quita de la pila @playerWin y @playerLoser el primer elemento y se las asigna a @newPlayerWin
	 */
	void RoundWin(List* playerWin, List* playerLoser, List* newPlayerWin);

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

	/* Pre: @playerOne representa el mazo y @newOne reprensenta el mazo de manos ganadas por @playerOne..
	 * .. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de manos ganadas por @playerTwo..
	 * .. todas son List* validas
	 * Post: muestra por pantalla el Round en juego
	 */
	void ViewRound(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

	/* Pre: @player representa el mazo y @newPlayer reprensenta el mazo de manos ganadas por @player..
	 * .. ambos son List* validas y solo @player puede esta vacio, @newPlayer tiene que contener al menos..
	 * .. un elemento
	 * Post: Mezcla todos los elementos(cartas) de @newPlayer luego se los asigna a @player y se vacia @newPlayer
	 */
	void ResetDeck(List* player, List* newPlayer);

	//Pre: @playerOne representa el mazo y @newOne reprensenta el mazo de mano ganadas por @playerOne..
	//.. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de mano ganadas por @playerTwo, todo son List* validas
	//Pos: si @playerOne esta vacio y @newOne no lo esta, reemplaza @playerOne por @newOne mezclado..
	//.. y/o si @playerTwo esta vacio y @newTwo no lo esta, reemplaza @playerTwo por @newTwo mezclado..
	//.. para el resto de los casos, no hace nada
	void DecideResetDeck(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

	/* Pre: @deckOne y @deckTwo reprensentan mazos de cartas, ambas son List* validas
	 * Post: suma y devuelve la cantidad de elementos(cartas) que contienen @deckOne y @deckTwo
	 */
	int CountCardPlayer(List* deckOne, List* deckTwo);

	//Pre: @playerOne representa el mazo y @newOne reprensenta el mazo de mano ganadas por @playerOne..
	//.. @playerTwo representa el mazo y @newTwo  reprensenta el mazo de mano ganadas por @playerTwo, todo son List* validas
	//Pos: si @playerOne o @newOne o ambos no estan vacios, muestra por pantalla como ganador a @playerOne..
	//.. sino muestra por pantalla como ganador a @playerTwo
	void DecideWin(List* playerOne, List* newOne, List* playerTwo, List* newTwo);

	/*Pre: @playerWin representa un mazo, @playerLose representa un mazo y @newLose reprensenta el mazo..
	 * ..de manos ganadas por @playerLose, todas son @List validas
	 * Post: quita todos los elementos contenidos en  @playerLose y @newLose, y los agrega a @playerWin
	 */
	void Finish(List* playerWin,List* playerLose,List* newLose);

	namespace TypeTry{

		//Pre:
		//Pos:
		void Prueba(List* playerOne, List* playerTwo);

		void Demo(SpanishDeck* deck, List* playerOne, List* playerTwo);
	}

}


#endif /* PLAYWAR_H_ */
