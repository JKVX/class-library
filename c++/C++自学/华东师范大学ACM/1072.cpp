#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a[10];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4])
	{
		if(a[0]==0&&a[1]==0
			&&a[2]==0&&a[3]==0&&a[4]==0)
			break;
		else if(a[0]-a[1]==a[1]-a[2]
			&&a[1]-a[2]==a[2]-a[3]
			&&a[2]-a[3]==a[3]-a[4])
		{
			for(int i=5;i<9;i++)
			{
				a[i]=2*a[i-1]-a[i-2];
				cout<<a[i]<<' ';
			}
			cout<<2*a[8]-a[7]<<endl;
		} 
		else if(a[1]*a[1]==a[0]*a[2]
				&&a[2]*a[2]==a[1]*a[3]
				&&a[3]*a[3]==a[2]*a[4])
		{
			for(int i=5;i<9;i++)
			{
				a[i]=a[i-1]*a[i-1]/a[i-2];
				cout<<fixed<<setprecision(0)<<a[i]<<' ';
			}
			cout<<fixed<<setprecision(0)<<a[8]*a[8]/a[7]<<endl;
		}
		else 
		{
			for(int i=5;i<9;i++)
			{
				a[i]=a[i-1]+a[i-2];
				cout<<a[i]<<' ';
			}
			cout<<a[8]+a[7]<<endl;
		}
	}
	return 0;
} 
