#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int i,m;
		string *s=new string [n];
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			if(s[i]=="bowl"||s[i]=="knife"
				||s[i]=="fork"||s[i]=="chopsticks")
			{
				cout<<s[i];
				break;
			}
		}		
		for(int m=i+1;m<n;m++)
		{
			cin>>s[m];
			if(s[m]=="bowl"||s[m]=="knife"
				||s[m]=="fork"||s[m]=="chopsticks")
			{
				cout<<' '<<s[m];
			}
		}
		cout<<endl;
	}
	return 0;
} 
