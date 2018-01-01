#define MAX_N 10000

struct Heap{
	int data[MAX_N];
	int last = 0;
};

void insert(Heap &heap, int val){
	heap.data[++heap.last] = val;
	int node = heap.last;
	while(node){
		int parent = (node-2)/2;
		if(heap.data[node] < heap.data[parent]){
			swap(heap.data[node], heap.data[parent]);
			node = parent;
		} else {
			return;
		}
	}
}

void deletemin(Heap &heap){
	int res = heap.data[0];
	heap.data[0] = heap.data[last--];
	int node = 0;
	while(node*2+1 <= last){
		int left = node*2+1;
		int right = node*2+2;
		if(heap.data[left] < heap.data[right]){
			if(heap.data[node] < heap.data[left]){
				swap(heap.data[node], heap.data[left]);
				node = left;
			} else {
				break;
			}
		} else {
			if(heap.data[node] < heap.data[right]){
				swap(heap.data[node], heap.data[right]);
				node = right;
			} else {
				break;
			}
		}
	}
	
	return res;
}

