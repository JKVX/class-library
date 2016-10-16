#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a;
	cin>>a;
	for(int b=0;b<a;b++)
	{
		string s;
		int l;
		cin>>s;
		l=s.length();
		for(int i=0;i<l-1;i=i+2)
		{
			cout<<s[i+1]<<s[i];
		}
		cout<<endl;
	}
	return 0;
} 
