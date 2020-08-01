#include"List.h"
#include"MaxHeap.h"
#include<map>

//estructura que correspondera al valor del map
struct info{
	Node *firstPair;
	Node *lastPair;
	hnode *pos;
};

class RePairAdvance{
	private:
		List seq;
		std::map< std::pair<int, int>, info> pairs;
		MaxHeap hp;
		void init_pair(Node*, Node*);
		void increase_pair(Node*, Node*);
	public:
		RePairAdvance();
		~RePairAdvance();
		void compress(List);
};
