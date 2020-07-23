RePairSimple::RePairSimple(){}

RePairSimple::~RePairSimple(){}

//FALTA CASO MAS DE UNA FREC MAX
void RePairSimple::compress(List seq){
	int maxf = 0;
	bool max_pair_found = false;
	for(Node* it = seq.begin(); it->next != NULL; it = it->next){
		if(
		maxf = max(maxf, ++pairs[{*it, *it->next}]);
	for(Node* it = seq.begin(); it->next != NULL; it = it->next)
		if(pairs[{*it, *it->next}] == maxf && !max_pair_found){

		}
}
