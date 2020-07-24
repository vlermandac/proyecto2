#include <bits/stdc++.h>
typedef pair<int,int> ii;
using namespace std;

class MaxHeap{
	private:
		vector<pair<int,ii>> seq;
		int hsize;
		int parent(int);
		int left(int);
		int right(int);
		void upheap(int);
		void downheap(int);
	public:
		binary_heap();
		void insert(int x) {
			if (hsize+1 >= (int)seq.size()) {
				seq.push_back(0);
			}
			seq[++hsize] = x;
			upheap(hsize);
		}

		int extract_max() {
			int taken = seq[1];
			swap(seq[1], seq[hsize--]);
			downheap(1);
			return taken;
		}

		int get_max() {
			return seq[1];
		}

		bool empty() {
			return hsize == 0;
		}
};

