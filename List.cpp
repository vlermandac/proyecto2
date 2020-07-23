#include"List.h"
#include<stddef.h>

List::List(){
	head = NULL;
	tail = NULL;
	lsize = 0;
}

List::~List(){}

void List::insert(int n){
	//Se crea nodo con valor "n"
	Node* nuevo = new Node;
	nuevo->val = n;
	nuevo->next = NULL;

	//Primer elemento
	if(head == NULL){
		nuevo->prev = NULL;
		head = nuevo;
		tail = head;
	}

	//Mas de un elemento
	else{
		tail->next = nuevo;
		nuevo->prev = tail;
		tail = nuevo;
	}
	lsize++;
}

void List::replace(Node *i, int n){
	i->val = n;
}

void List::remove(Node *i){
	i->prev->next = i->next;
	i->next->prev = i->prev;
	delete i;
}

int List::size(){
	return lsize;
}

bool List::empty(){
	return lsize == 0;
}

Node* List::begin(){
	return head;
}

Node* List::next(Node* i){
	return i->next;
}

Node* List::prev(Node* i){
	return i->prev;
}
