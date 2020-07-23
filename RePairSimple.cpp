#include"RePairSimple.h"

using namespace std;

RePairSimple::RePairSimple(){}

RePairSimple::~RePairSimple(){}

void RePairSimple::compress(List seq){
	map<pair<int,int>,int> pairs;
	int maxf = 0, max_i, max_j, key_name = 27;
	//Mientras las frecuencias sean mayor a 1
	while(maxf != 1){
		pairs.clear();
		//recorrer secuencia para encontrar par mas frecuente
		for(Node* it = seq.begin(); it->next != NULL; it = it->next)
			if(++pairs[{it->val, it->next->val}] > maxf){
				maxf = pairs[{it->val, it->next->val}];
				max_i = it->val;
				max_j = it->next->val;
			}
		//guardar clave del par
		keys[{max_i, max_j}] = key_name++;
		//recorrer secuencia para reemplazar pares por clave
		for(Node* it = seq.begin(); it->next != NULL; it = it->next)
			if(it->val == max_i && it->next->val == max_j){
				seq.remove(it->next);
				seq.replace(it, keys[{max_i, max_j}]);
			}
	}
}
