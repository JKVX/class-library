#include<iostream>
#include<string>
using  namespace std;
int main()
{
	int a;
	cin>>a;
	cin.get();
	for(int b=0;b<a;b++)
	{
		string s;
		getline(cin,s);
		int l,M,total=0;
		l=s.length();
		for(int i=0;i<l;i++)
		{
			if(s[i]=='H')M=1;
			else if(s[i]=='C')M=12;
			else if(s[i]=='N')M=14;
			else if(s[i]=='O')M=16;
			else if(s[i]=='F')M=19;
			else if(s[i]=='P')M=31;
			else if(s[i]=='S')M=32;
			else M=39;
			int t,count=1,n=0;
			t=i+1;
			if(t==l)
			{	
				n=1;
			}
			else
			{
				while(isdigit(s[t]))
				{
					t++;
				}
				if(t==i+1)n=1;
				else
				{
					for(int j=t-i-2;j>=0;j--)
					{
						n=n+(s[i+1+j]-'0')*count;
						count=count*10; 
					}
				}
			}
			i=t-1;
			total=total+n*M;		
		}
		cout<<total<<endl;
	}
	return 0;
} 
