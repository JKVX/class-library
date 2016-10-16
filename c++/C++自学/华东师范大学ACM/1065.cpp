#include<iostream>
using namespace std;
int Count(int);
int main()
{
	int n;
	cin>>n;
	while(cin>>n)
	{
		if(n==0)cout<<0<<endl;
		else
		{
			cout<<Count(n)<<endl;
		}
	}
	return 0;
} 
int Count(int n)
{
	if(n==1)
	{
		return 1;
	}
	else if(n==2)
	{
		return 3;
	}
	else
	{
		return Count(n-1)+2*Count(n-2);
	}
}
