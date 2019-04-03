#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int flag=1,count=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(a[i][j-1]==1 && a[i][j]==0 ||
				a[i][j-1]==0 && a[i][j]==1)
				flag=1;
			else
			{
				flag=0;
				break;
			}
		}
	}

	for(int j=0;j<n;j++)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i-1][j]==1 && a[i][j]==0 ||
				a[i-1][j]==0 && a[i][j]==1)
				count=1;
			else
			{
				count=0;
				break;
			}
		}
	}
	if(flag==1&&count==1)
		cout<<"valid";
	else
		cout<<"invalid";
}
