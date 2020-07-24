#include"RePairSimple.h"
#include<iostream>

using namespace std;

RePairSimple::RePairSimple(){}

RePairSimple::~RePairSimple(){}

void RePairSimple::compress(List seq){
	map<pair<int,int>,int> pairs;
	int maxf = 0, max_i, max_j, key_name = 28, cont = 1, frec, i, j;
	//Mientras las frecuencias sean mayor a 1
	while(maxf != 1){
		pairs.clear();
		maxf = 1;
		//recorrer secuencia para encontrar par mas frecuente
		for(Node* it = seq.begin(); it->next != NULL; it = it->next){
			//actualizar frecuencia maxima
			//mayor estricto para seleccionar primer par frecuente encontrado
			if(it->val == it->next->val){
				cont++;
				if(it->next != seq.nd()) continue;
			}
			if(cont > 1){
				i = j = it->val;
				pairs[{i, j}] += cont/2;
				frec = pairs[{i, j}];
				cont = 1;
			}
			if(frec > maxf){
				maxf = frec;
				max_i = i;
				max_j = j;
			}

			i = it->val;
			j = it->next->val;
			pairs[{i, j}]++;
			frec = pairs[{i, j}];

			if(frec > maxf){
				maxf = frec;
				max_i = i;
				max_j = j;
			}
		}
		//guardar clave del par
		keys[{max_i, max_j}] = key_name++;
		//recorrer secuencia para reemplazar pares por clave
		for(Node* it = seq.begin(); it->next != NULL; it = it->next)
		if(it->val == max_i && it->next->val == max_j){
				seq.replace(it->next, keys[{max_i, max_j}]);
				seq.remove(it);
			}

	}
	sequence = seq;
}

void RePairSimple::print(){
	for(Node* it = sequence.begin(); it != NULL; it = it->next)
		cout<<it->val<<" ";
	cout<<endl;
}
