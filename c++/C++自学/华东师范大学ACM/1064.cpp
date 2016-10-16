#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int m=0;m<n;m++)
	{
		int i,p0=1,p1=0,temp;
		cin>>i;
		for(int j=2;j<=i;j++)
		{
			temp=p1;
			p1=p0;
			p0=temp+p0;
		}
		cout<<p0+p1<<endl;
	}
	return 0;
} 
