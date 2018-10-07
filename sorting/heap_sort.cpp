/*
*	Heapsort based on the CLRS Introduction to Algorithms book.
*	Use freely
*	Implemented by joaobnetto
*/

#include <bits/stdc++.h>
#define MAXN 10010

using namespace std;

// this is my heap structure.
int heap[MAXN];

// Swap the two elements located at i and j
void swap(int i, int j){
	int tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
}

// Returns the parent of the node
int parent(int i){
	return i/2;
}

// Returns the node i left child
int left(int i){
	return 2*i;
}

// Returns the node i right child.
int right(int i){
	return 2*i+1;
}


/*
*	Function that mantains the heap property.
*	If one of the childs of the node is larger than the node, then we have to swap them
*	and call the function to the node until the property is not violated.
*/

void max_heapify(int i, int n){

	int l = left(i), r = right(i), largest;
	
	// If the left child is bigger than the father, it becomes the largest.
	if(l <= n && heap[l] > heap[i]) largest = l;

	// Else the father is still the largest.
	else largest = i;

	// If the right child is bigger than the largest, then the largest is the right child.
	if(r <= n && heap[r] > heap[largest]) largest = r;

	// If there's a violation, we swap and call max_heapify to the node changed.
	if(largest != i){
		swap(i, largest);
		max_heapify(largest, n);
	}
}

// Builds a max_heap coming from n/2 to 1.

void build_max_heap(int n){
		for(int i = n/2; i >= 1;--i){
			max_heapify(i, n);
		}
}

/*
*	Sorts the vector acording to the heap.
*	By definition of heap, the largest element is always located at the top.
*	At each iteration we put the largest element in the last position of the heap and we diminish its size
*	by one. Then we call the max_heapify to fix the heap and get the largest element from 1 to i-1 on the
*	top of the heap.
*	So after n-1 iterations, we have the n-1 largests elements sorted in the array.
*	Thus its ordered.
*/ 

void heap_sort(int n){
	build_max_heap(n);
	for(int i = n;i >= 2;i--){
		swap(1, i);
		n--;
		max_heapify(1, n);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> heap[i];
	}
	heap_sort(n);
	for(int i = 1;i<= n;++i) cout << heap[i] << " \n"[i==n];
}