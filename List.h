class Node{
	public:
		Node prev;
		Node next;
		int val;
};

class List{
	private:
		Node root;
		Node tail;
		int lsize;

	public:
		List(int);
		~List();
		void insert(int);
		void replace(Node,int);
		void remove(Node);
		int size();
		bool empty();
		Node next(Node);
		Node prev(Node);

};
