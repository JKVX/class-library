#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	for(int b=0;b<a;b++)
	{
		int c;
		cin>>c;
		for(int i=1;i<=c/2;i++)
		{
			for(int j=1;j<=c+1-i;j++)
			{
				if(j==c+1-i||j==i)
					cout<<'X';
				else cout<<' ';
			}
			cout<<endl;
		}
		for(int i=c/2+1;i<=c;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(j==c+1-i||j==i)
					cout<<'X';
				else cout<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
} 
