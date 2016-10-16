#include<iostream>
#include<string>
using namespace std;
int main()
{
	int c;
	cin>>c;
	cin.get();
	for(int a=0;a<c;a++)
	{
		string s;
		getline(cin,s);
		int l;
		l=s.length();
		for(int i=0;i<l;i++)
		{
			if(isdigit(s[i]))
			{
				i++;
				if(i==l)cout<<char(s[i-1]-'1'+'A');
				else if(isdigit(s[i]))
				{
					if(s[i-1]=='1')
					{
						cout<<char(s[i]-'1'+'A'+10);
					}
					else 
					{
						cout<<char(s[i]-'1'+'A'+20);
					}	
				}
				else if(s[i]=='#')
				{
					cout<<char('A'+s[i-1]-'1')<<' ';
				}
				else cout<<char('A'+s[i-1]-'1');
			}
			else if(s[i]=='#')
			cout<<' ';
		}
		cout<<endl;
	}
	return 0;
} 
