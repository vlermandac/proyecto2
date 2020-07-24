#include<map>
#include<utility>
#include"List.h"

class RePairSimple{
	private:
		//secuencia comprimida
		List sequence;

		//claves para descomprimir
		std::map<std::pair<int,int>,int> keys;
	public:
		RePairSimple();
		~RePairSimple();
		void compress(List);
		void print();
};
