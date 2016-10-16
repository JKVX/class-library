#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break; 
		int a=0;
		int b;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b);
			a^=b;
		}
		cout<<a<<endl;
	} 
	return 0;
} 
