#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int v[], int mid, int len)
{
    if (len < 2)
        return;

    int i=0, j=mid, k=0;
    int tmp[len];

    while (i < mid && j < len)
        tmp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];

    memcpy(tmp+k, v+i, (mid-i) * sizeof *v);
    memcpy(v, tmp, (k + (mid-i)) * sizeof *v);
}
void mersort(int v[], size_t len)
{
    if (len < 2)
        return;

    size_t mid = len/2;
    mersort(v, mid);
    mersort(v+mid, len-mid); // see here.
    merge(v, mid, len);
}
void mersort3(int v[], size_t len)
{
    if (len < 3)
    {
        mersort(v, len);
        return;
    }

    size_t m1 = len/3;
    size_t m2 = (2 * len)/3;
    mersort3(v, m1);
    mersort3(v+m1, m2-m1);   
    mersort3(v+m2, len-m2); 
    merge(v, m1, m2);
    merge(v, m2, len);
}
int main()
{
    int N ;
    scanf("%d",&N);
    int ar[N];
    for (int i=0; i<N; ++i)
    {
		scanf("%d",&ar[i]);
    }
    mersort3(ar, N);
    for (int i=0; i<N; ++i)
        printf("%d ", ar[i]);
}
