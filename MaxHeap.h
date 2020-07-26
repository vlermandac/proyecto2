#include<vector>
typedef std::pair<int,int> ii;

struct hnode{
	int key;
	ii val;
	hnode(int a, ii b){ a = key; b = val; }
};


class MaxHeap{
	private:
		std::vector<hnode> seq;
		int hsize;
		int parent(int);
		int left(int);
		int right(int);
		void upheap(int);
		void downheap(int);
	public:
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

