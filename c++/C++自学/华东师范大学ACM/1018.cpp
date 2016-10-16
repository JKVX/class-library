#include<iostream>
using namespace std;
int main()
{
	int a;
	while(cin>>a)
	{
		int b,total;
		total=0;
		while(a!=0)
		{
			b=a%10;
			if(b%2==0)total=total+b;
			a=a/10;
		}
		if(a%2==0)total=total+a;
		cout<<total<<endl<<endl;
	}
	return 0;
} 
