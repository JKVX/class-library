#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	for(b=0;b<a;b++)
	{
		int c;
		cin>>c;
		int i,j;
		for(i=1;i<=c;i++)
		{
			for(j=1;j<c;j++)
				cout<<i*j<<" ";
			cout<<i*j<<endl;
		}
	}
	return 0;
} 
