#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		int a1,b1,c,d,e;
			a1=b;
			b1=a;
		while(a1%b1!=0)
		{
			e=a1%b1;
			a1=b1;
			b1=e;
		}
		d=b1;
		c=a*b/d;
		cout<<c<<' '<<d<<endl;
	}
	return 0;
}
