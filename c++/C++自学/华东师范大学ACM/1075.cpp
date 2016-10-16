#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int m=0;m<n;m++)
	{
		int t,v=-1,total=0;
		cin>>t;
		for(int i=1;i<=t;i++)
		{
			v=v+2;
			total=total+v;
			if(total>=10000)
			{
				total=total%10000;
			}
		}
		cout<<total<<endl;
	}
	return 0;
} 
