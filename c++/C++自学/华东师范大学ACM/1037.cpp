#include<iostream>
using namespace std;
bool isLeap(int);
int main()
{
	int n;
	cin>>n;
	for(int t=0;t<n;t++)
	{
		int y,m,d,count=0;
		char a;
		cin>>y>>a>>m>>a>>d;
		if(isLeap(y)&&m==2&&d==29)
		{
			cout<<-1<<endl;
		}
		else 		
		{
			for(int i=0;i<=18;i++)
			{
				if(isLeap(i+y))
				{
					count++;
				}
			}
			if(isLeap(y))
			{
				if(m<=2&&d<=28)
				cout<<365*18+count<<endl;
				else cout<<count+365*18-1<<endl;
			}
			else 
			{
				cout<<365*18+count<<endl;
			}
		}
		
	}
	return 0;
}
bool isLeap(int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)
	{
		return true;
	}
	return false;
}
 
