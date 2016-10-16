#include<stdio.h>
#include<iostream>
using namespace std;
int f(int x)
{
	int k=x;
	if(x==1) return 0;
	for(int i=2;i<=x;i++)
	{
		if(x%i==0)
		{
			k=k/i*(i-1);
			while(x%i==0)
			{
				x/=i;
			}
		}
	}
	return k;
}
int main()
{
	int m,n;
	cin>>n;
	while(n--)
	{
		cin>>m;
		cout<<f(m)<<endl;
	}
	return 0;
}
