#include<vector>
typedef std::pair<int,int> ii;

struct hnode{
	int key;
	ii val;
	hnode(int a, ii b){ key = a; val = b; }
};


class MaxHeap{
	private:
		int hsize;
		hnode* lastpush;
		int parent(int);
		int left(int);
		int right(int);
		void upheap(int);
		void downheap(int);
	public:
		std::vector<hnode> seq;
		MaxHeap();
		~MaxHeap();
		void push(hnode);
		void pop();
		hnode top();
		bool empty();
		void changeKey(hnode*, int);
		hnode *lastNode();
		void print();
};

