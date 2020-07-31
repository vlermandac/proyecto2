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
		else{

			//aumenta frecuencia del par
			hnode* poss = pairs[{it->val, it->next->val}].pos;
			hp.changeKey(poss, poss->key + 1);

			//setear ocurrencia previa y siguiente del par
			it->prevPair = pairs[{it->val, it->next->val}].lastPair;
			it->prevPair->nextPair = it;
			it->nextPair = NULL;

			//actualizar ultima ocurrencia del par
			pairs[{it->val, it->next->val}].lastPair = it;
		}
	}

	//Fase 2. comienza remplazo
	hnode* maxnode = hp.top();
	int symbol_number = 28;
	while(maxnode->key > 1){
		symbols[{maxnode->val.first, maxnode->val.second}] =symbol_number;
		Node* it = pairs[{maxnode->val.first, maxnode->val.second}].firstPair;
		cout<<"Maxnode: "<<maxnode->val.first<<" "<<maxnode->val.second<<" "<<maxnode->key<<endl;
		for(it; it != NULL; it = it->nextPair){

			cout<<"->>"<<it->val<<" "<<it->next->val<<endl;
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
	if(it->nextPair != NULL) cout<<"AA: "<<it->nextPair->val<<" "<<it->nextPair->next->val<<endl;

			//CREAR PARES ADJACENTES
		cout<<"1Elementos heap: ";
		hp.print();

			if(it != seq.begin()){
				if(pairs.find(ii(it->prev->val, it->next->val)) == pairs.end())
					init_pair(it->prev, it->next);

				else{
					//aumenta frecuencia del par
					hnode* poss = pairs[{it->prev->val, it->next->val}].pos;
					hp.changeKey(poss, poss->key + 1);

					//setear ocurrencia previa y siguiente del par
					it->prev->prevPair = pairs[{it->prev->val, it->next->val}].lastPair;
					it->prev->prevPair->nextPair = it->prev;
					it->prev->nextPair = NULL;

					//actualizar ultima ocurrencia del par
					pairs[{it->prev->val, it->next->val}].lastPair = it->prev;
				}
			}
			if(it->next != seq.nd()) {
	for(Node *itt = pairs[{maxnode->val.first, maxnode->val.second}].lastPair; itt != NULL; itt = itt->next) cout<<itt->val<<" ";
			cout<<endl;
				if(pairs.find(ii(it->next->val, it->next->next->val)) == pairs.end())
					init_pair(it->next, it->next->next);

				else{
						//aumenta frecuencia del par
						hnode* poss = pairs[{it->next->val, it->next->next->val}].pos;
						hp.changeKey(poss, poss->key + 1);

						//setear ocurrencia previa y siguiente del par
						it->next->prevPair = pairs[{it->next->val, it->next->next->val}].lastPair;
						it->next->prevPair->nextPair = it->next;
						it->next->nextPair = NULL;

						//actualizar ultima ocurrencia del par
						pairs[{it->next->val, it->next->next->val}].lastPair = it->next;
				}
			}
			seq.remove(it);
	for(Node *itt = seq.begin(); itt != NULL; itt = itt->next) cout<<itt->val<<" ";
			cout<<endl;
		cout<<"2Elementos heap: ";
		hp.print();

			cout<<endl;
		}
		cout<<"sali\n";
		hp.pop();

		maxnode = hp.top();
		symbol_number++;
	}
//	for(Node *itt = seq.begin(); itt != NULL; itt = itt->next) cout<<itt->val<<" ";
}
