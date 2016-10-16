#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	int a[1000001];
	a[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		a[i]=(a[int(i-sqrt(i))]+a[int(log(i))]+a[int(i*sin(i)*sin(i))])%1000000;
	}
	cin>>n;
	while(n!=-1)
	{
		cout<<a[n]<<endl;
		cin>>n;
	}
	return 0;
} 
