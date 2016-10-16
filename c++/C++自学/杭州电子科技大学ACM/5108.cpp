#include<iostream>
#include<cmath>
using namespace std;
int prime(int a)
{	
	for(int m=2;m<=(int)sqrt(a);m++)
		if(a%m==0) return m;
	return 0;
}
int main()
{
	int n,m,t;
	while(cin>>n)
	{
		m=1;
		if(n==1)cout<<0<<endl;
		else if(!prime(n))cout<<1<<endl;
		else 
		{
			while(t=prime(n))
			{
				m=m*t;
				n=n/t;	
			}
			cout<<m<<endl;
		}
	}
	return 0;
}
