#include "MaxHeap.h"
using namespace std;

//constructor
MaxHeap::MaxHeap(){
	//consideramos a la posicion 1 como el inicio
	hnode *dummy = new hnode(0,ii(0,0));
	seq.push_back(dummy);
	hsize = 0;
}

//destructor
MaxHeap::~MaxHeap(){
	for(auto p : seq) delete p;
}

//metodos auxiliares
int MaxHeap::parent(int i){
	return i>>1;
}
int MaxHeap::left(int i){
	return i*2;
}
int MaxHeap::right(int i){
	return (i*2)+1;
}


void MaxHeap::upheap(int i){
	//si llegamos a "head", termina
	if(i == 1) return;

	//si parent es menor, intercambiamos posicion
	if(seq[i]->key > seq[parent(i)]->key) {
		swap(seq[i]->idx, seq[parent(i)]->idx);
		swap(seq[i], seq[parent(i)]);

		//continuamos el upheap recursivamente
		upheap(parent(i));
	}
}

void MaxHeap::downheap(int i){
	//si llegamos al ultimo nodo, termina
	if(i > hsize) return;

	//obtenemos el hijo mayor para intercambiar posicion con el
	int aux = i;
	if(left(i) <= hsize && seq[i]->key < seq[left(i)]->key)
		aux = left(i);
	if(right(i) <= hsize && seq[aux]->key < seq[right(i)]->key)
		aux = right(i);
	if(aux != i) {
		swap(seq[i]->idx, seq[aux]->idx);
		swap(seq[i], seq[aux]);

		//continuamos el downheap recursivamente
		downheap(aux);
	}
}

void MaxHeap::push(hnode* x) {
	//asignamos al nuevo nodo x el indice que le corresponde
	x->idx = seq.size();

	//agregamos el nodo al vector y hacemos upheap para mantener el orden
	seq.push_back(x);
	hsize++;
	upheap(hsize);
}

void MaxHeap::pop() {
	//intercambiamos "top" con el nodo mas reciente
	swap(seq[1]->idx, seq[hsize]->idx);
	swap(seq[1], seq[hsize--]);

	//eliminamos top
	seq.erase(seq.begin() + hsize +1);

	//hacemos downheap para mantener el orden
	downheap(1);
}

hnode* MaxHeap::top() {
	return seq[1];
}

void MaxHeap::changeKey(hnode* x, int n){
	//se cambia la frecuencia del nodo x
	int aux = x->key;
	x->key = n;

	//si la frecuencia aumento, se hace upheap
	if(x->key > aux)
		upheap(x->idx);
	//si la frecuencia disminuyo, se hace downheap
	if(x->key < aux)
		downheap(x->idx);
}

void MaxHeap::clear(){
	seq.clear();
}

