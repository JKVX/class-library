#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[1]*a[1]+a[0]*a[0]==a[2]*a[2])
		{
			cout<<"good"<<endl;
		} 
		else if(a[1]==a[0]||a[2]==a[1])
		{
			cout<<"perfect"<<endl;
		}
		else cout<<"just a triangle"<<endl;
	}
	return 0;
} 
