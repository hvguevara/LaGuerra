#ifndef NODE_H_
#define NODE_H_
#include "Card.h"
using TypeCard::Card;

namespace TypeNode{

	struct Node;

	Node* CreateEmpty();

	Node* Create(Card* card);

	void SetPrevious(Node* node, Node* newPrevious);

	Card* GetCard(Node* node);

	Node* GetPrevious(Node* node);

	char* GetSuit(Node* node);

	int GetValues(Node* node);

	void View(Node* node);

	void Destroy(Node* node);

}

namespace Pruebas{

}

#endif /* NODE_H_ */
