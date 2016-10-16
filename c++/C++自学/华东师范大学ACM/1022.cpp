#include<iostream>
using namespace std;
int main()
{
	double a,b;
	while(cin>>a>>b)
	{
		int c,d,e=0;
		c=d=a/b;
		if(c*b!=a)
		{
			c++;
			d++;
		}
		while(c>0)
		{
			e++;
			c=c-e;
		} 
		cout<<d+e-1<<endl;
	}
	return 0;
} 
