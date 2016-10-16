#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;
int main()
{
	char c;
	string s;
	while(cin>>c>>s)
	{
		int l;
		double count=0;
		l=s.length();
		c=tolower(c);
		for(int i=0;i<l;i++)
		{
			s[i]=tolower(s[i]);
			if(s[i]==c)
			count++;
		}
		cout<<fixed<<setprecision(5)<<count/l<<endl;
	}
	return 0;
} 
