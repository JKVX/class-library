#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	for(b=0;b<a;b++)
	{
		int n,m,i,j,count=0;
		cin>>n>>m;
		for(i=m/5;i>=0;i--)
			for(j=(m-5*i)/2;j>=0;j--)
			{
				if((i*5+j*2+(n-i-j)*1)==m)
				count++;
			}
			cout<<count<<endl;		
	}
	return 0;
} 
