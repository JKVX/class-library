#include<iostream>
using namespace std;
int main()
{
	int a,b,c,temp;
	while(cin>>a>>b)
	{
		if(a<=b) 
		{
			temp=b;
			b=a;
			a=temp;
		}
		c=a%b;
		while(c!=0)
		{
			a=b;
			b=c;
			c=a%b;
		}
		cout<<b<<endl;
	}
} 
