#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	int a;
	cin>>a;
	for(int b=0;b<a;b++)
	{
		string a;
		cin>>a;
		int l;
		l=a.length();
		for(int i=0;i<l;i++)
		{
			switch(a[i])
			{
				case 'a':
				case 'A':
				case 'e':
				case 'E':
				case 'i':
				case 'I':
				case 'o':
				case 'O':
				case 'u':
				case 'U':a[i]=toupper(a[i]);break;
				default:a[i]=tolower(a[i]);break;
			}
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
} 
