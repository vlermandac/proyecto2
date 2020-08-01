#include"RePairAdvance.h"
#include<map>
#include<iostream>

using namespace std;

RePairAdvance::RePairAdvance(){}

RePairAdvance::~RePairAdvance(){}

//<++>
void RePairAdvance::init_pair(Node* n1, Node* n2){
	//inicializar HEAP
	hnode* aux_node = new hnode(1, ii(n1->val, n2->val));
	hp.push(aux_node);

	//inicializar MAP
	info aux;
	aux.firstPair = n1;
	aux.lastPair = n1;
	aux.pos = aux_node;
	pairs[{n1->val, n2->val}] = aux;

	//1ra ocurrencia del par
	n1->prevPair = NULL;
	n1->nextPair = NULL;
}

void RePairAdvance::increase_pair(Node* n1, Node* n2){

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
	pairs.clear();
	//CLEAR HP
	//Recorrer secuencia guardada en la lista
	//Primera pasada. Inicializacion.
	for(Node* it = seq.begin(); it->next != NULL; it = it->next){

		//par nuevo
		if(pairs.find(ii(it->val, it->next->val)) == pairs.end())
			init_pair(it, it->next);

		//par repetido
		else increase_pair(it, it->next);
	}

	//Fase 2. comienza remplazo
	hnode* maxnode = hp.top();
	int symbol_number = 28;
	while(maxnode->key > 1){
		hp.pop();
		Node* it = pairs[{maxnode->val.first, maxnode->val.second}].firstPair;
		for(it; it != NULL; it = it->nextPair){

			//disminuir frecuencia pares adyacentes
			//cambiar punteros pares adyacentes
			if(it != seq.begin()){
				hnode* poss = pairs[{it->prev->val, it->val}].pos;
				hp.changeKey(poss, poss->key - 1);
				if(it->prev->prevPair == NULL && it->prev->nextPair != NULL)
					pairs[{it->prev->val, it->next->val}].firstPair = it->prev->nextPair;
			}
			if(it->next != seq.nd()){
				hnode* poss = pairs[{it->next->val, it->next->next->val}].pos;
				hp.changeKey(poss, poss->key - 1);
				if(it->next->prevPair == NULL && it->next->nextPair != NULL)
					pairs[{it->next->val, it->next->next->val}].firstPair = it->next->nextPair;

			}

			seq.replace(it->next, symbol_number);

			//CREAR PARES ADJACENTES

			if(it != seq.begin()){
				if(pairs.find(ii(it->prev->val, it->next->val)) == pairs.end())
					init_pair(it->prev, it->next);

				else increase_pair(it->prev, it->next);
			}
			if(it->next != seq.nd()) {
				if(pairs.find(ii(it->next->val, it->next->next->val)) == pairs.end())
					init_pair(it->next, it->next->next);

				else increase_pair(it->next, it->next->next);

			}
			seq.remove(it);
		}

		maxnode = hp.top();

		symbol_number++;
	}
	for(Node *itt = seq.begin(); itt != NULL; itt = itt->next) cout<<itt->val<<" ";
	cout<<endl;


}
