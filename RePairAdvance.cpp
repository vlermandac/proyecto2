#include"RePairAdvance.h"
#include<map>

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
			pairs[{it->val, it->next->val}] =info(it, it, hp.lastNode());
			it->prevPair = NULL;
			it->nextPair = NULL;
		}
		else{
			int vl = pair[{it->val, it->next->val}]->pos->key;
			hp.changeKey(pairs[{it->val, it->next->val}]->pos, ++vl);
			it->prevPair = pairs[{it->val, it->next->val}]->lastPair;
			it->nextPair = NULL;
			it->prev->nextPair = it;
			pairs[{it->val, it->next->val}]->lastPair = it;
		}
	}
	hp.print();

}
