#ifndef LIST_H_
#define LIST_H_
#include "Node.h"
using TypeNode::Node;

namespace TypeList{

	struct List;

	/* Pre: -
	 * Pos: Crea y devuelve una @List vacia.
	 */
	List* CreateEmpty();

	/* Pre: @newNode es un Node* valido
	 * Pos: Crea y devuelve una @List con lo contenido en @newNode
	 */
	List* Create(Node* newNode);

	/* Pre: @list es una List* valida, @newNode es un Node* valido
	 * Pos: si @newNode no esta vacio, apila en @list a @newNode. De lo contrario, no hace nada
	 */
	void Stack(List* list, Node* newNode);

	//Pre: @list es una List* valida
	//Pos: si @list no esta vacia, desapila el ultimo elemento de @list y lo devuelve. De lo contrario, devuelve NULL
	Node* UnStack(List* list);

	//Pre: @list es una List* valida, @newNode es un Node* valido,
	//Pos: Setea como @first elemento de @list a @newNode
	void SetFirst(List* list, Node* newNode);

	//Pre: @list es una List* valida, @newNode es un Node* valido,
	//Pos: Setea como @last elemento de @list a @newNode
	void SetLast(List* list, Node* newNode);

	//Pre: @list es una List* valida, @newNode es un Node* valido,
	//Pos: Setea como @countNode elemento de @list a newCount
	void SetCountNode(List* list, int newCount);

	//Pre: @list es una List* valida
	//Pos: Setea todo el contenido de @list como NULL o 0 segun corresponda
	void SetToEmpty(List* list);

	//Pre: @list y @replace son List* validas
	//Pos: Setea todo el contenido de @list con el contenido de @replace
	void SetReplaceList(List* list, List* replace);

	//Pre: @list es una List* valida
	//Pos: devuelve el @first Node* de @list
	Node* GetFirst(List* list);

	//Pre: @list es una List* valida
	//Pos: devuelve el @last Node* de @list
	Node* GetLast(List* list);

	//Pre: @list es una List* valida
	//Pos: devuelve la cantidad de @Node contenidos en @list
	int GetCountNode(List* list);

	//Pre: @list es una List* valida
	//Pos: Muestra por salida standar todos el contenido de @list
	void View(List* list);

	//Pre: @list es una List* valida
	//Pos: si @list esta vacia, devuelve true, de lo contrario, devuelve false
	bool IsEmpty(List* list);

	//Pre: @list y @concatenate son List* validas
	//Pos: si @list y @concatenate no estan vacios, concatena @concatenate en @list y la devuelve..
	//..si @list esta vacia y @concatenate no lo esta, reemplaza el contenido de @list por @concatenate y la devuelve..
	//..si @concatenate esta vacia y @list no lo esta, o si ambas estan vacias, devuelve @list sin modificar
	List* Concatenate(List* list, List* concatenate);

	//Pre: @list es una List* valida
	//Pos: Libera solamente los recursos utilizados por @list, NO libera los recursos utilizados por el contenido de @list
	void DestroyOnlyList(List* list);

	//Pre: @list es una List* valida
	//Pos: Libera todos los recursos utilizados por @list
	void Destroy(List* list);
}




#endif /* LIST_H_ */
