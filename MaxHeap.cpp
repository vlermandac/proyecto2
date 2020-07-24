#include "MaxHeap.h"

MaxHeap::MaxHeap(){
	seq.push_back(hnode(0,ii(0,0)));
	hsize = 0;
}

MaxHeap::~MaxHeap(){}

int MaxHeap::parent(int i){
	return i>>1;
}

int MaxHeap::left(int i){
	return i<<1;
}

int MaxHeap::right(int i){
	return i<<1;
}

void MaxHeap::upheap(int i){
	if(i == 1) return;
	if(seq[i].key > seq[parent(i)].key) {
		swap(seq[i], seq[parent(i)]);
		upheap(parent(i));
	}
}

void MaxHeap::downheap(int i){
	if(i > hsize) return;
	int aux = i;
	if(left(i) <= hsize && seq[i].key < seq[left(i)].key)
		aux = left(i);
	if(right(i) <= hsize && seq[aux].key < seq[right(i)].key)
		aux = right(i);
	if(aux != i) {
		swap(seq[i], seq[aux]);
		downheap(aux);
	}

}

void MaxHeap::push(hnode x) {
	if(hsize + 1 >= (int)seq.size()) {
		seq.push_back(hnode(0, ii(0,0)));
	}
	seq[++hsize] = x;
	upheap(hsize);
}

void MaxHeap::pop() {
	swap(seq[1], seq[hsize--]);
	downheap(1);
}

hnode MaxHeap::top() {
	return seq[1];
}

bool MaxHeap::empty() {
	return hsize == 0;
}

