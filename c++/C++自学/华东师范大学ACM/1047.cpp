#include<iostream>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="#")
			break;
		int l,count=0;
		l=s.length();
		for(int i=0;i<l-1;i++)
		{
			if(s[i]=='1')
			count++;
		}
		if(s[l-1]=='e')
		{
			if(count%2==0)
			s[l-1]='0';
			else s[l-1]='1';
		}
		else 
		{
			if(count%2==0)
			s[l-1]='1';
			else s[l-1]='0';
		}
		cout<<s<<endl;
	}
	return 0;
} 
