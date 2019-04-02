#include <iostream>
using namespace std;

struct a{
int data;
int index;
};



void quick_s(int start,int end, int *arr,int n)
{
//cout<<endl<<end<<endl<<endl;
if(start<end)
{
	int pivot=arr[end];
	int t;

	 
	int i=start-1;
	//int j=start;

	for(int j=start;j<end;j++)
	{
		if(arr[j]<=pivot)
		{
			//cout<<"Hello";
			i++;
			t=arr[j];
			arr[j]=arr[i];
			arr[i]=t;
		}
	}


t=arr[i+1];
arr[i+1]=arr[end];
arr[end]=t;
quick_s(start,i,arr,n);
quick_s(i+2,end,arr,n);
}

}
			
			
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

	int s=0;
	int e=n-1;

	quick_s(s,e,arr,n);

for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<endl;

return 0;
}
