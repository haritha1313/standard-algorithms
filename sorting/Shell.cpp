/* Shell Sort implementation in C;
 * Author : Felipe Gabriel;
 * Input : Array lenght and elements;
 * Output : Sorted array elements;
*/

#include <stdio.h>

//function that swap the numbers in the vector and ordain
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
	/*
	k is a counting variable
	'size' is the size of the vector
	v is the vector that receive the numbers
	*/
	int size,k;
	scanf("%d",&size);
	int v[size];

	//looping structure to insert numbers in the vector
	for(k = 0; k < size; k++){
		scanf("%d",&v[k]);
	}
	//calling the function that realize the sorting
	Shell_sort(v,size);

	//looping structure to print in the screen the vector already sorted
	for(k = 0; k < size; k++){
		if(k != size-1){
			printf("%d ",v[k]);
		}
		else{
			printf("%d\n",v[k]);
		}
	}
	//end of program
	return 0;
}
