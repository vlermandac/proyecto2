struct Node{
		Node *prev;
		Node *next;
		Node *prevPair;
		Node *nextPair;
		int val;
};

class List{
	private:
		Node *head;
		Node *tail;
		int lsize;

	public:
		List();
		~List();
		void insert(int);
		void replace(Node*,int);
		void remove(Node*);
		int size();
		bool empty();
		Node* begin();
		Node* nd();

};
