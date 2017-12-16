#include <iostream>
#define ll long long int
using namespace std;

void swap(ll* a, ll* b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}

ll partition(ll arr[], ll low, ll high)
{
    ll piv = arr[high];                         //setting pivot as the right most element
    ll i = low-1;
    
    for(ll j = low; j<high; j++)
    {
        if(arr[j]<arr[piv])
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[high]);         
    /*
    keep pivot in right position(elements to the left are 
    smaller than the pivot and elements to the right are greater than it)
    */
    
    return (i+1);                               //position of chosen pivot
}

void quickSort( ll arr[], ll low, ll high)
{
    if(low<high)
    {
        ll pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);           //quicksort left of pivot
        quickSort(arr, pivot+1, high);          //quicksort right of pivot
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
    quickSort(arr, 0, n-1);
    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}