#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,total;
	cin>>a;
	while(a!=0)
	{
		c=0;
		total=0;
		for(b=0;b<a;b++)
		{
			cin>>d;
			if(d>c)total=total+6*(d-c)+5;
			else total=total+4*(c-d)+5;
			c=d;
		}
		cout<<total<<endl;
		cin>>a;
	}
	return 0;
} 
