#include"RePairAdvance.h"
#include<map>
#include<iostream>

using namespace std;

RePairAdvance::RePairAdvance(){}

RePairAdvance::~RePairAdvance(){}

//inicializa par nuevo en el MAP y el HEAP
void RePairAdvance::init_pair(Node* n1, Node* n2){
	//setear valores iniciales y agregar par al HEAP
	hnode* aux_node = new hnode(1, ii(n1->val, n2->val));
	hp.push(aux_node);

	//setear valores iniciales y agregar par al MAP
	info aux;
	aux.firstPair = n1;
	aux.lastPair = n1;
	aux.pos = aux_node;
	pairs[{n1->val, n2->val}] = aux;

	//1ra ocurrencia del par; no tiene ocurrencia previa ni siguiente
	n1->prevPair = NULL;
	n1->nextPair = NULL;
}

//aumenta frecuencia de para existente y adjunta sus punteros asociados
void RePairAdvance::increase_pair(Node* n1, Node* n2){
	//caso cuando hay mas de 2 elementos iguales seguidos
	if(pairs[{n1->val, n2->val}].lastPair->next == n1) return;

	//aumenta frecuencia del par
	hnode* poss = pairs[{n1->val, n2->val}].pos;
	hp.changeKey(poss, poss->key + 1);

	//setear ocurrencia previa y siguiente del par
	n1->prevPair = pairs[{n1->val, n2->val}].lastPair;
	n1->prevPair->nextPair = n1;
	n1->nextPair = NULL;

	//actualizar ultima ocurrencia del par
	pairs[{n1->val, n2->val}].lastPair = n1;
}

void RePairAdvance::compress(List seq){
	//limpiar estructuras a utilizar
	pairs.clear();
	//hp.clear();

	//Recorrer secuencia guardada en la lista
	//Primera pasada. Inicializacion.
	for(Node* it = seq.begin(); it->next != NULL; it = it->next){

		//par nuevo
		if(pairs.find(ii(it->val, it->next->val)) == pairs.end())
			init_pair(it, it->next);

		//par repetido
		else increase_pair(it, it->next);
	}

	//Fase 2. comienza remplazo de pares

	//obtenemos par de mayor frecuencia
	hnode* maxnode = hp.top();

	//simbolo por el que se remplazara el par
	int symbol_number = 28;

	//iteracion siga mientras la frecuencia de los pares sea mayor a 1
	while(maxnode->key > 1){

		//Se elimina par con frecuencia mayor del HEAP
		hp.pop();

		//se itera desde la primera ocurrencia del par, a traves de las
		//ocurrencias siguientes del mismo, hasta llegar a la ultima
		Node* it = pairs[{maxnode->val.first, maxnode->val.second}].firstPair;
		for(it; it != NULL; it = it->nextPair){

			//se disminuye en 1 la frecuencia de pares adyacentes al par actual
			//se cambian punteros de pares adyacentes

			//caso cuando tiene par adyacente a la izquierda
			if(it != seq.begin()){
				hnode* poss = pairs[{it->prev->val, it->val}].pos;
				hp.changeKey(poss, poss->key - 1);

				//si el par ady izq corresponde a la primer ocurrencia,
				//esta ultima se asinga a la ocurrencia siguiente
				if(it->prev->prevPair == NULL && it->prev->nextPair != NULL)
					pairs[{it->prev->val, it->next->val}].firstPair = it->prev->nextPair;
			}

			//caso cuando tiene par adyacente a la derecha
			if(it->next != seq.nd()){
				hnode* poss = pairs[{it->next->val, it->next->next->val}].pos;
				hp.changeKey(poss, poss->key - 1);

				//si el par ady izq corresponde a la primer ocurrencia,
				//esta ultima se asinga a la ocurrencia siguiente
				if(it->next->prevPair == NULL && it->next->nextPair != NULL)
					pairs[{it->next->val, it->next->next->val}].firstPair = it->next->nextPair;

			}

			//se remplaza el valor del 2do elemento del par por la nueva clave
			seq.replace(it->next, symbol_number);

			//se ignora la presencia del primer elemento del par por el momento
			//con el fin de no perder la referencia a este nodo

			//se agregan o se aumenta frecuencia pares creados a partir del nuevo valor que remplazo al par actual

			//caso cuando tiene par adyacente a la izquierda
			if(it != seq.begin()){

				//par nuevo
				if(pairs.find(ii(it->prev->val, it->next->val)) == pairs.end())
					init_pair(it->prev, it->next);

				//par repetido
				else increase_pair(it->prev, it->next);
			}

			//caso cuando tiene par adyacente a la derecha
			if(it->next != seq.nd()) {

				//par nuevo
				if(pairs.find(ii(it->next->val, it->next->next->val)) == pairs.end())
					init_pair(it->next, it->next->next);

				//par repetido
				else increase_pair(it->next, it->next->next);

			}

			//se elimina el primer elemento del par de la secuencia
			seq.remove(it);
		//hp.print(); cout<<endl;
		}
		//se obtiene el nuevo par con frecuencia mayor
		maxnode = hp.top();

		//se aumenta en 1 el simbolo que remplazara a los pares
		symbol_number++;
	}

	//se entrega la secuencia comprimida
	for(Node *itt = seq.begin(); itt != NULL; itt = itt->next) cout<<itt->val<<" ";
	cout<<endl;

	//destructor
	//hp.~MaxHeap();

}
