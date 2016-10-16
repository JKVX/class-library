#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m,count=0;
		cin>>m;
		if(m%2==1&&m!=1)
		{
			cout<<m;
			count++;
		}
		while(m!=1)
		{
			if(m%2==0)
			{
				m=m/2;
				if(m%2==1&&m!=1)
				{
					
					if(count==0)
					{
						cout<<m;
					}
					else
					{
						cout<<' '<<m;
					}
					count++;
				}
			}
			else 
			{
				m=m*3+1;
			}
		}
		if(count==0)cout<<"No number can be output !"
							<<endl;
		else cout<<endl;
	}
	return 0;
} 
