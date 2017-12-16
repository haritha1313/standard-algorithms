#include <iostream>
#define ll long long int
using namespace std;

void merge(ll arr[], ll l, ll m, ll r)
{
    ll n1, n2, i, j, k;
    n1 = m-l+1;
    n2 = r-m;
    
    ll temp1[n1], temp2[n2];
    
    for(i=0; i<n1; i++)
        temp1[i] = arr[l+i];
    for(i=0; i<n2; i++)
        temp2[i] = arr[m+1+i];
        
    i=0;
    j=0;
    k=l;
    
    while(i<n1 && j<n2)         //fill the array from l to r with elements in ascending order
    {
        if(temp1[i]<=temp2[j])
        {
            arr[k]=temp1[i];
            i++;
        }
        else
        {
            arr[k]=temp2[j];
            j++;
        }
        k++;
    }
    while(i<n1)                 //elements remain in left subarray
    {
        arr[k++]=temp1[i++];
    }
    while(j<n2)                 //elements remain in right subarray
    {
        arr[k++]=temp2[j++];
    }
}

void mergeSort( ll arr[], ll l, ll r)
{
    ll m;
    if(l<r)
    {
        m = l + (r-l)/2;
        mergeSort(arr, l, m);       //Sort the two halves
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);        //merge the halves
    }
}

int main()
{
    ll n;
    cout<<"Enter size of array\n";
    cin>>n;
    ll arr[n];
    cout<<"Enter elements of array to be sorted\n";
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr, 0, n-1);
    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}