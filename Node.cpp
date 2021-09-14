#include "Node.h"
#include <iostream>
using TypeNode::Node;

struct TypeNode::Node{
	Card* card;
	Node* previous;
};

Node* TypeNode::CreateEmpty(){
	Node* newNode= new Node;
	newNode->card=NULL;
	newNode->previous=NULL;
}

Node* TypeNode::Create(Card* card){
	Node* newNode=CreateEmpty();
	newNode->card=card;
	return newNode;
}

void TypeNode::SetPrevious(Node* node, Node* newPrevious){
	node->previous=newPrevious;
}

Card* TypeNode::GetCard(Node* node){
	return node->card;
}

Node* TypeNode::GetPrevious(Node* node){
	return node->previous;
}

char* TypeNode::GetSuit(Node* node){
	return node->card->GetSuit();
}

int TypeNode::GetValues(Node* node){
	return node->card->GetValue();
}
void TypeNode::View(Node* node){
	node->card->ViewCard();
}

void TypeNode::Destroy(Node* node){
	node->card->~Card();
	delete node;
}
