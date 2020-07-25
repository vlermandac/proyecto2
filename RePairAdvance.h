#include"List.h"
#include"MaxHeap.h"

struct info{
	Node *firstPair;
	Node *lastPair;
	hnode *pos;
	info(Node *a, Node *b, hnode *c){
		firstPair = a;
		lastPair = b;
		pos = c;
	}
};

class RePairAdvance{
	private:
		List seq;
	public:
		RePairAdvance();
		~RePairAdvance();
		void compress(List);
};
