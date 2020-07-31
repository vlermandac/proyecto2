#include<vector>
typedef std::pair<int,int> ii;

struct hnode{
	int key;
	ii val;
	int idx;
	hnode(int a, ii b){ key = a;
		val.first = b.first;
		val.second = b.second;
	}
};


class MaxHeap{
	private:
		std::vector<hnode*> seq;
		int hsize;
		hnode* lastpush;
		int parent(int);
		int left(int);
		int right(int);
		void upheap(int);
		void downheap(int);
	public:
		MaxHeap();
		~MaxHeap();
		void push(hnode*);
		void pop();
		hnode* top();
		bool empty();
		void changeKey(hnode*, int);
		hnode *lastNode();
		void print();
		int getIndex(hnode*);
};

