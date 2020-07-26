#include"List.h"
#include"MaxHeap.h"

struct info{
	Node *firstPair;
	Node *lastPair;
	hnode *pos;
};

class RePairAdvance{
	private:
		List seq;
	public:
		RePairAdvance();
		~RePairAdvance();
		void compress(List);
};
