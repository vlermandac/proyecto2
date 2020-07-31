#include"List.h"
#include"MaxHeap.h"
#include<map>

struct info{
	Node *firstPair;
	Node *lastPair;
	hnode *pos;
	int frec = -1;
};

class RePairAdvance{
	private:
		List seq;
		std::map<std::pair<int,int>,int> symbols;
		std::map< std::pair<int, int>, info> pairs;
		MaxHeap hp;
		void init_pair(Node*, Node*);
	public:
		RePairAdvance();
		~RePairAdvance();
		void compress(List);
};
