#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int m=0;m<n;m++)
	{
		int a,b,c,x;
		cin>>a>>b>>c;
		for(x=1000;x<=9999;x++)
		{
			if(x%a==0&&(x+1)%b==0&&(x+2)%c==0)
			{
				cout<<x<<endl;
				break;
			}
		}
		if(x==10000)cout<<"Impossible"<<endl;
	}
	return 0;
} 
