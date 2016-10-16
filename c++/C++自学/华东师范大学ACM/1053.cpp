#include<iostream>
#include<string>
using namespace std;
int hello(int,int);
int main()
{
	string s;
	while(cin>>s)
	{
		if(s==".")break;
		int l,n=1,count=1;
		l=s.length();
		for(int i=0;i<l;i++)
		{
			if(s[i]!=s[0])
			{
				n=hello(l,n);
				break;
			} 
		}
		if(n==1)cout<<l<<endl;
		else
		{
			while(n<=l)
			{
				int m=n;
				bool b=1;
				for(int i=n;i<l;i=i+n)
				{
					for(int j=0;j<n;j++)
					{
						if(s[i+j]!=s[j])
						{
							n=hello(l,n);
							b=0;
							break;
						}
					}
					if(b==0)
					break;
				}
				if(n==m)
				{
					cout<<l/n<<endl;
					break;
				}
			}
		}
	}
	return 0;
} 
int hello(int s,int count) 
{
	count++;
	while(count<=s)
	{
		if(s%count==0)return count;
		count++;
	}
	return s;
}
