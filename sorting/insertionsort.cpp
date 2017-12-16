#include <iostream>
#define ll long long int
using namespace std;

void insertionSort( ll arr[], ll n)
{
    ll key, j;
    for(ll i=1; i<n; i++)
    {
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr, n);
    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}