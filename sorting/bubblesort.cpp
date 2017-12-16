#include <iostream>
#define ll long long int
using namespace std;

void bubbleSort( ll arr[], ll n)
{
    ll temp;
    for(ll i=1; i<n; i++)
    {
        for(ll j=0; j<n-i; j++)       //highest gets accumulated towards right end
        {
            if(arr[j]>arr[j+1])       //swap is lower index number is greater than higher index number
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    bubbleSort(arr, n);
    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}