#include<iostream>
//#include"RePairSimple.h"
#include"RePairAdvance.h"

using namespace std;

int main(){
	List seq;
	int n, a; cin>>n;
	while(n--){ cin>>a; seq.insert(a); }
/*	RePairSimple rp;
	rp.compress(seq);
	rp.print();
	*/
	RePairAdvance rpa;
	rpa.compress(seq);
	return 0;
}
