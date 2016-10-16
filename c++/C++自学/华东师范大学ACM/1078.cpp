#include<iostream>
using namespace std;
int main()
{
	int n,m,c=0;
	cin>>n>>m;
	while(n!=0&&m!=0)
	{
		int count=0;
		for(int b=2;b<n;b++)
		{
			for(int a=1;a<b;a++)
			if((a*a+b*b+m)%(a*b)==0)
			{
				count++;
			}			
		}
		c++;
		cout<<"Case "<<c<<": "<<count<<endl;
		cin>>n>>m;
	}
	return 0;
} 
