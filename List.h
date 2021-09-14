#ifndef LIST_H_
#define LIST_H_
#include "Node.h"
using TypeNode::Node;

namespace TypeList{

	struct List;

	List* CreateEmpty();

	List* Create(Node* newNode);

	void Stack(List* list, Node* newNode);

	Node* UnStack(List* list);

	void SetFirst(List* list, Node* newNode);

	void SetLast(List* list, Node* newNode);

	void SetCountNode(List* list, int newCount);

	void SetToEmpty(List* list);

	void SetReplaceList(List* list, List* replace);

	Node* GetFirst(List* list);

	Node* GetLast(List* list);

	int GetCountNode(List* list);

	void View(List* list);

	bool IsEmpty(List* list);

	List* Concatenate(List* list, List* concatenate);

	void DestroyList(List* list);

	void Destroy(List* list);
}




#endif /* LIST_H_ */
