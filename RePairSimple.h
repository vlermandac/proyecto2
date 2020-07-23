#include<map>
#include<utility>
#include"List.h"

class RePairSimple{
	private:
		List sequence;
		std::map<std::pair<int,int>,int> keys;
	public:
		RePairSimple();
		~RePairSimple();
		void compress(List);
		void print();
};
