#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a,b;
	int l1,l2;
	while(cin>>a>>b)
	{
		l1=a.length();
		l2=b.length();
		string s[100];
		bool c;
		int count=0,position=0;
		for(int m=0;m<l2;m++)
		{
			c=1;
			position=0;
			for(int j=0;j<m;j++)
			{
				if(b==s[j])
				{
					c=0;
					break;
				}
			}
			if(c==1)
			{
				while(position<=l1-l2)
				{
					position=a.find(b,position);
					if(position!=-1)
					{
						count++;
					}
					else 
					{
						break;
					}
					position++;
				}
			}
			s[m]=b;
			char d;
			d=b[0];
			for(int k=0;k<l2-1;k++)
			{
				b[k]=b[k+1];
			}
			b[l2-1]=d;
				
		}
		cout<<count<<endl;
	}
	return 0;
} 
