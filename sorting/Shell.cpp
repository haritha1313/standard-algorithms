/* Shell Sort implementation in C;
 * Author : Felipe Gabriel;
 * Input : Array lenght and elements;
 * Output : Sorted array elements;
*/

#include <stdio.h>

void Shell_sort(int v[], int size){
	int i, j , value;
	int gap = 1;
	while(gap < size){
		gap = 3 * gap + 1;
	}
	while(gap > 1){
		gap = gap/3;
		for(i = gap; i < size; i++){
			value = v[i];
			j = i - gap;
			while(j >= 0 && value < v[j]){
				v[j + gap] = v[j];
				j -= gap;
			}
			v[j + gap] = value;
		}
	}
}

int main(){
	int size,k;
	scanf("%d",&size);
	int v[size];

	for(k = 0; k < size; k++){
		scanf("%d",&v[k]);
	}
	Shell_sort(v,size);

	for(k = 0; k < size; k++){
		if(k != size-1){
			printf("%d ",v[k]);
		}
		else{
			printf("%d\n",v[k]);
		}
	}

	return 0;
}