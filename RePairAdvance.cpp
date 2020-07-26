#include"RePairAdvance.h"
#include<map>
#include<iostream>

using namespace std;

RePairAdvance::RePairAdvance(){}

RePairAdvance::~RePairAdvance(){}

void RePairAdvance::compress(List seq){
	map< pair<int, int>, info> pairs;
	MaxHeap hp;
	int a = 0;
	for(Node* it = seq.begin(); it->next != NULL; it = it->next){
		cout<<"iteracion"<<a++<<":\n";
		if(pairs.find(ii(it->val, it->next->val)) == pairs.end()){
			if(pairs.find(ii(1,2)) != pairs.end())
				cout<<"->"<<pairs[{1, 2}].pos->key<<endl;
			cout<<"Par: "<<it->val<<" "<<it->next->val<<endl;
			hnode hn(1, ii(it->val, it->next->val));
			if(pairs.find(ii(1,2)) != pairs.end())
				cout<<"->"<<pairs[{1, 2}].pos->key<<endl;

			hp.push(hn);
			if(pairs.find(ii(1,2)) != pairs.end())
				cout<<"->"<<pairs[{1, 2}].pos->key<<endl;

			cout<<"Nodo agregado al heap: ";
			cout<<hp.lastNode()->key<<" "<<hp.lastNode()->val.first<<" ";
			cout<<hp.lastNode()->val.second<<endl;
			info aux;
			aux.firstPair = it;
			aux.lastPair = it;
			aux.pos = hp.lastNode();
			pairs[{it->val, it->next->val}] = aux;
			cout<<"info agregada al map: ";
			cout<<pairs[{it->val, it->next->val}].pos->key<<" ";
			cout<<pairs[{it->val, it->next->val}].pos->val.first<<" ";
			cout<<pairs[{it->val, it->next->val}].pos->val.second<<"\n";
			it->prevPair = NULL;
			it->nextPair = NULL;

		}

		else{

			cout<<"Par: "<<it->val<<" "<<it->next->val<<endl;
			int vl = pairs[{it->val, it->next->val}].pos->key;
			cout<<"Frec: "<<pairs[{it->val, it->next->val}].pos->key;
			cout<<endl;
			vector<hnode>::iterator bg = hp.seq.begin();
			hnode *ini = &*bg;
			int i = pairs[{it->val, it->next->val}].pos - ini;
			//cout<<"->"<<i<<endl;

			hp.changeKey(pairs[{it->val, it->next->val}].pos, ++vl);
			it->prevPair = pairs[{it->val, it->next->val}].lastPair;
			it->nextPair = NULL;
			it->prev->nextPair = it;
			pairs[{it->val, it->next->val}].lastPair = it;
		}
/*	for(auto i : pairs){
		cout<<i.second.pos->val.first<<" ";
		cout<<i.second.pos->val.second<<" : ";
		cout<<i.second.pos->key<<"\n";
	}
	*/
			cout<<endl;
	}
	hp.print();

}
