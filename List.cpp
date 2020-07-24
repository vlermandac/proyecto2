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
	if(i != NULL) i->val = n;
}

void List::remove(Node *i){
	//casos bordes
	if(head == NULL) return;
	if(tail == NULL) return;
	if(i == NULL) return;
	if(head == i) head = i->next;
	if(tail == i) tail = i->prev;
	//caso general
	if(i->prev != NULL) i->prev->next = i->next;
	if(i->next != NULL) i->next->prev = i->prev;
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

Node* List::nd(){
	return tail;
}

