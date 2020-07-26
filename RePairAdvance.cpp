#include"RePairAdvance.h"
#include<map>
#include<iostream>

using namespace std;

RePairAdvance::RePairAdvance(){}

RePairAdvance::~RePairAdvance(){}

void RePairAdvance::compress(List seq){
	map< pair<int, int>, info> pairs;
	MaxHeap hp;
	for(Node* it = seq.begin(); it->next != NULL; it = it->next){
		if(pairs.find(ii(it->val, it->next->val)) == pairs.end()){
			hnode hn(1, ii(it->val, it->next->val));
			hp.push(hn);
			cout<<hp.lastNode()->key<<"\n";
			info aux;
			aux.firstPair = it;
			aux.lastPair = it;
			aux.pos = hp.lastNode();
			pairs[{it->val, it->next->val}] = aux;
			it->prevPair = NULL;
			it->nextPair = NULL;
		}
		else{
			int vl = pairs[{it->val, it->next->val}].pos->key;
			hp.changeKey(pairs[{it->val, it->next->val}].pos, ++vl);
			it->prevPair = pairs[{it->val, it->next->val}].lastPair;
			it->nextPair = NULL;
			it->prev->nextPair = it;
			pairs[{it->val, it->next->val}].lastPair = it;
		}
	}
	hp.print();

}
