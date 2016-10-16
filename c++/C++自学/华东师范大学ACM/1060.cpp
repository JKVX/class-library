#include<iostream>
using namespace std;
int Count(int);
int main()
{
	int n;
	cin>>n;
	while(cin>>n)
	{
		cout<<Count(n)<<endl;
	}
	return 0;
} 
int Count(int n)
{
	if(n==1)
	{
		return 3;
	}
	else if(n==2)
	{
		return 7;
	}
	else
	{
		return 2*Count(n-1)+Count(n-2);
	}
}
