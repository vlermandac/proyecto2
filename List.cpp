#include"List.h"

List::List(int n){}

List::~List(){}

void List::insert(int n){}

void List::replace(Node i, int n){}

void List::remove(Node i){}

int List::size(){
	return lsize;
}

bool List::empty(){
	return lsize == 0;
}

Node List::next(Node i){
	return i.next;
}

Node List::prev(Node i){
	return i.prev;
}
