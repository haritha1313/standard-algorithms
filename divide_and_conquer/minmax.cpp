#include <iostream>
#include <utility>
using namespace std;

pair<int,int> minmax(int arr[], int low, int high)
{
  pair <int, int> mmx, mml, mmr;
  int mid;

  if (low == high)
  {
      mmx.first = arr[low];
      mmx.second = arr[low];
      return mmx;
  }
  if(low == high-1)
  {
      if(arr[low]<arr[high])
      {
          mmx.first = arr[low];
          mmx.second = arr[high];
      }
      else
      {
          mmx.first = arr[high];
          mmx.second = arr[low];
      }
      return mmx;
  }
  mid = (low+high)/2;
  
  mml = minmax(arr, low, mid);
  mmr = minmax(arr, mid+1, high);
  
  if(mml.first < mmr.first)
  {
      mmx.first = mml.first;
  }
  else
  {
      mmx.first = mmr.first;
  }
  if(mml.second > mmr.second)
  {
      mmx.second = mml.second;
  }
  else
  {
      mmx.second = mmr.second;
  }
  return mmx;
}

int main() 
{
  int n;
  cout<<"Enter size of array\n";
  cin>>n;
  int arr[n];
  cout<<"Enter elements of array \n";
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  
  pair <int, int> q = minmax(arr, 0, n-1);
  
  cout<<"Minimum: "<<q.first<<" Maximum: "<<q.second<<"\n";
  return 0;
}