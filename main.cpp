#include<iostream>
#include"List.h"

using namespace std;

int main(){
	List a;
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	for(Node *it = a.begin(); it != NULL; it = it->next)
		cout<<it->val<<endl;
	return 0;
}
