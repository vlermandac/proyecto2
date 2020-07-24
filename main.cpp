#include<iostream>
#include"RePairSimple.h"

using namespace std;

int main(){
	List seq;
	int n, a; cin>>n;
	while(n--){ cin>>a; seq.insert(a); }
	RePairSimple rp;
	rp.compress(seq);
	rp.print();
	return 0;
}
