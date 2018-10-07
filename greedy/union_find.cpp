#include<bits/stdc++.h>

/**
*	MAXN: The maximum number of nodes possible.
*/
#define MAXN 100010
using namespace std;	

/**
*	parent: Array that stores the parent of a node.
*	size: Array that stores the size of tree at a node.
*/
int parent[MAXN], size[MAXN];	

void init(int num){
	for(int i=0;i<num;i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int node){
	if(parent[node] == node)
		return node;
	return parent[node] = find(parent[node]);
}

void merge(int node_1, int node_2){
	int par_1 = find(node_1);
	int par_2 = find(node_2);
	if(par_1 != par_2){
		if(size[par_1] < size[par_2]){
			swap(par_1, par_2);
		}
		parent[par_2] = par_1;
		size[par_1] += size[par_2];
	}
}

int main(){
	
	/**
	*	n: The number of initial nodes.
	*	m: The number of merge operations.
	*/
	int n,m;
	cin>>n>>m;
	
	init(n);
	
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		merge(u,v);
	}
	
	return 0;
}
