#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int a=0;a<t;a++)
	{
		string s;
		int n,l,m;
		cin>>s>>n;
		l=s.length();
		for(m=0;m<l;m++)
		{
			if(s[m]=='.')
			break;
		}
		if(m+n<l)
		{
			cout<<s[m+n]<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
} 
