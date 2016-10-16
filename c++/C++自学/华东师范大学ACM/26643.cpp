#include<iostream>
using namespace std;
int a(int ,int);
int main()
{
	int x,y;
	while(cin>>x>>y)
	{
		cout<<a(x,y)<<endl;
	}
	return 0;
}
int a(int x,int y)
{
	int count=0;
	int arr[100000];
	for(int z=1;z<=y;z++)
		arr[z]=z;
	for(int i=2;i<=y;i++)
	{
		if(arr[i]!=0)
		{
			if(i>=x)
				count++;
			for(int m=i*2,t=3;m<=y;t++)
			{
				arr[m]=0;
				m=i*t;
			}
		}
	}
	return count;
}
