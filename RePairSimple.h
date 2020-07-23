#include<map>
#include<utility>
#include"List.h"

class RePairSimple{
	private:
		List seq;
		map<pair<int,int>,int> pairs;
	public:
		RePairSimple();
		~RePairSimple();
		void compress(List);
};
