#include<iostream>
using namespace std;
int main()
{
	char a;
	while(cin>>a)
	{
		if(a=='@')
		break;
		else 
		{
			int n;
			cin>>n;
			if(n==1)
			{
				cout<<a<<endl<<endl;
			}
			else 
			{
				for(int j=1;j<n;j++)
				{
					cout<<' ';
				}
				cout<<a<<endl;
				for(int i=2;i<n;i++)
				{
					for(int j=n-i;j>=1;j--)	
					{
						cout<<' ';
					}
					cout<<a;
					for(int j=1;j<=2*i-3;j++)
					{
						cout<<' ';
					}
					cout<<a<<endl;
				}
				for(int j=1;j<=2*n-1;j++)
				{
					cout<<a;
				}
				cout<<endl<<endl;
			}
		}
	}
	return 0; 
}
