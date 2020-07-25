#include"RePairAdvance.h"

using namespace std;

RePairAdvance::RePairAdvance(){}

RePairAdvance::~RePairAdvance(){}

RePairAdvance::compress(List seq){
	map( pair<int, int>, info) pairs;
	MaxHeap hp;
	for(Node* it = seq.begin(); it->next != NULL; it = it->next){
		if(pairs.find(ii(it->val, it->next->val)) == seq.end()){
			hnode hn(1, ii(it->val, it->next->val));
			hp.push(hn);
			pairs[{it->val, it->next->val}] = info(it, it, hn);
		}
		else{
			int vl = pair[{it->val, it->next->val}]->pos->key;
			hp.changeKey(pairs[{it->val, it->next->val}]->pos, ++vl);
		}
	}

}
