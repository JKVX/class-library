#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.get();
	for(int m=0;m<n;m++)
	{
		string s;
		int i,t=0,l;
		getline(cin,s);
		l=s.length();
		for(i=0;i<l;i++)
		{
			if(s[i]==' ')
			{
				for(int j=i-1;j>=t;j--)
				{
					cout<<s[j];
				}
				cout<<' ';
				t=i+1;
			}
		}
		for(int m=l-1;m>=t;m--)
		{
			cout<<s[m];
		}
		cout<<endl;
	}
	return 0;
} 
