#define first key
#define second val
MaxHeap::MaxHeap(){
	seq.push_back(pair<int,ii>(-1,ii(0,0)));
	hsize = 0;
}

~MaxHeap::MaxHeap(){}

int MaxHeap::parent(int){
	return i>>1;
}

int MaxHeap::left(int i){
	return i<<1;
}

int MaxHeap::right(int i){
	return i<<1;
}

void MaxHeap::upheap(int i){
	if(i == 1) return;
	if(seq[i] > seq[parent(i)]) {
		swap(seq[i], seq[parent(i)]);
		upheap(parent(i));
	}
}

void MaxHeap::downheap(int i){
	if(i > hsize) return;
	int aux = i;
	if(left(i) <= hsize && seq[i] < seq[left(i)])
		aux = left(i);
	if(right(i) <= hsize && seq[aux] < seq[right(i)])
		aux = right(i);
	if(aux != i) {
		swap(seq[i], seq[aux]);
		downheap(aux);
	}

}
