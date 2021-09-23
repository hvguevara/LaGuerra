#ifndef NODE_H_
#define NODE_H_
#include "Card.h"
using TypeCard::Card;

namespace TypeNode{

	struct Node;

	/* Pre: -
	 * Pos: Crea y devuelve un @Node* vacio
	 */
	Node* CreateEmpty();

	//Pre: @card es una Card* valida no vacia
	//Pos: Crea y devuelve un @Node* con @card como contenido
	Node* Create(Card* card);

	//Pre: @node y @newPrevious son Node* validos no vacios
	//Pos: asigna en @Node como @previous a @newPrevious
	void SetPrevious(Node* node, Node* newPrevious);

	//Pre: @node es un Node* valido no vacio
	//Pos: devuelve lo contenido en @node como @card
	Card* GetCard(Node* node);

	//Pre: @node es un Node* valido no vacio
	//Pos: devuelve lo contenido en @node como @previous
	Node* GetPrevious(Node* node);

	//Pre: @node es un Node* valido no vacio
	//Pos: devuelve lo contenido en @node en @card como @suit
	char* GetSuit(Node* node);

	//Pre: @node es un Node* valido no vacio
	//Pos: devuelve lo contenido en @node en @card como @values
	int GetValues(Node* node);

	//Pre: @node es un Node* valido no vacio
	//Pos: muestra por pantalla el contenido de @node
	void View(Node* node);

	//Pre: @node es un Node*
	//Pos: libera todos los recursos utilizados por @node
	void Destroy(Node* node);
}

#endif /* NODE_H_ */
