#include<iostream>
using namespace std;

int main()
{
	int n,m,a,b;
	a=0;
	b=1;
	cout<<"输入一个二进制数：";
	cin>>n;

	while(n>0)
	{
		m=n%10;
		a=a+m*b;
		b=b*2;
		n=n/10;
		if (m>1)
		{
			cout<<"你输入的不是二进制数！";
			return 0;
		}
	}
	cout<<"它的十进制是：";
	cout<<a<<endl;
	return 0;
}