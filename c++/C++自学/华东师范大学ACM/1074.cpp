#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int m=0;m<n;m++)
	{
		int i,j;
		cin>>i>>j;
		if(i<j)
		{
			cout<<0<<endl;
		}
		else 
		{
			if(j>i/2)
			{
				j=i-j;
			}
			if(j==0)
			{
				cout<<1<<endl;
			}
			else
			{
				double x=1;
				for(int k=i;k>i-j;k--)
				{
					x=x*k;
				}
				double y=1;
				for(int k=1;k<=j;k++)
				{
					y=y*k;
				}
				cout<<fixed<<setprecision(0)<<x/y<<endl;
			}
		}
	}
	return 0;
} 
