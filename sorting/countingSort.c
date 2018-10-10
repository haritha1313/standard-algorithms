#include <stdio.h>
#include <string.h>
#define N 255
void countSort(char arr[])
{

	char output[strlen(arr)];
	int count[N + 1], i;
	memset(count, 0, sizeof(count));
	for(i = 0; arr[i]; ++i)
		++count[arr[i]];

	for (i = 1; i <= N; ++i)
		count[i] += count[i-1];

	for (i = 0; arr[i]; ++i)
	{
		output[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}


	for (i = 0; arr[i]; ++i)
		arr[i] = output[i];
}


int main()

{
    char arr[N];

	printf("Enter a string: ");
	scanf("%s",arr);

	countSort(arr);

	printf("Sorted character array is %s", arr);
	return 0;
}
