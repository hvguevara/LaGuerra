#include <iostream>
#include "List.h"
#include "Node.h"

using std::endl;
using std::cout;
using TypeNode::Node;
using namespace TypeList;

struct TypeList::List{
	Node* first;
	Node* last;
	int countNode;
};

List* TypeList::CreateEmpty(){
	List* newList= new List;
	newList->first=NULL;
	newList->last=NULL;
	newList->countNode=0;
	return newList;
}

List* Create(Node* newNode){
	List* newList= CreateEmpty();
	if(newNode!=NULL){
		TypeList::Stack(newList, newNode);
	}
	return newList;
}

void TypeList::Stack(List* list, Node* newNode){
	if(newNode!=NULL){
		if(list->first==NULL){
			list->first=list->last=newNode;
		}
		else{
			SetPrevious(newNode,list->last);
			list->last=newNode;
		}
		list->countNode++;
	}

}

Node* TypeList::UnStack(List* list){
	Node* unStack=list->last;
	list->last=GetPrevious(unStack);
	list->countNode--;
	return unStack;
}

void TypeList::SetFirst(List* list, Node* newNode){
	list->first=newNode;
}

void TypeList::SetLast(List* list, Node* newNode){
	list->last=newNode;
}

void TypeList::SetCountNode(List* list, int newCount){
	list->countNode=newCount;
}

void TypeList::SetToEmpty(List* list){
	list->countNode=0;
	list->first=NULL;
	list->last=NULL;
}

void TypeList::SetReplaceList(List* list, List* replace){
	SetFirst(list,replace->first);
	SetLast(list,replace->last);
	SetCountNode(list,replace->countNode);
}

Node* TypeList::GetFirst(List* list){
	return list->first;
}

Node* TypeList::GetLast(List* list){
	return list->last;
}

int TypeList::GetCountNode(List* list){
	return list->countNode;
}

void TypeList::View(List* list){
	Node* iterator=list->last;
	while(iterator!=NULL){
		View(iterator);
		iterator=GetPrevious(iterator);
	}
}

bool TypeList::IsEmpty(List* list){
	return list->countNode==0 ? true : false;
}

List* TypeList::Concatenate(List* list, List* concatenate){
	if(concatenate->countNode>0){
		SetPrevious(concatenate->first, list->last);
		list->last=concatenate->last;
		list->countNode+=concatenate->countNode;
	}
	return list;
}

void TypeList::DestroyList(List* list){
	delete list;
}

void TypeList::Destroy(List* list){
	Node* destroy=list->last;
	Node* iterator=destroy;
	while(destroy!=NULL){
		iterator=GetPrevious(iterator);
		Destroy(destroy);
		destroy=iterator;
	}
	delete list;
}


