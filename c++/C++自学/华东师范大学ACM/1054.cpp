#include<iostream>
#include<string>
using namespace std;
bool hello(string); 
int main()
{
	string s;
	while(cin>>s)
	{
		int l,total;
		l=s.length();
		total=l;
		string s2;
		bool b=1;
		for(int j=0;j<l;j++)
		{
			if(s[j]!=s[0])
			{
				b=0;
				break;
			}
		}
		if(b)cout<<(1+l)*l/2<<endl;
		else
		{
			for(int i=2;i<=l;i++)
			{
				for(int j=0;j<=l-i;j++)
				{
					s2=s.substr(j,i);
					if(hello(s2))
					total++;
				}
			
			}
			cout<<total<<endl;
		}
	}
	return 0;
}
bool hello(string s)
{
	int l;
	l=s.length();
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		return false;
	}
	return true;
}
