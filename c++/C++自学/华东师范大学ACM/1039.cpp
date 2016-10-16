#include<iostream>
#include<cctype>
using namespace std;
int main()
{
	int a;
	cin>>a;
	cin.get();
	for(int b=0;b<a;b++)
	{
		string s;
		char c;
		int n;
		int m=0;
		getline(cin,s);
		n=s.length();
		while(m<n)
		{
			while(!isalpha(s[m]))
			{
				m++;
			}
			if(m>=n)
			break;
			c=toupper(s[m]);
			cout<<c;
			while(isalpha(s[m]))
			{
				m++;
			}
		}
		cout<<endl;
	}
	return 0;
} 
