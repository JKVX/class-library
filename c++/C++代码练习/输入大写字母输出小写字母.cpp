#include<iostream>
using namespace std;

int main()
{
	char a='a';
	while(a!=-1)
	{
		cout<<"请输入一个大写字母：";
		cin>>a;
		if(a=='+')return 0;
		while(a<'A'||a>'Z')
		{
			cout<<"你输入的不是大写字母。"<<endl<<endl;
			cout<<"请你输入一个大写字母：";
			cin>>a;
		}
	
		a=a+'a'-'A';
		cout<<"它的小写字母是："<<a<<endl<<endl;
	}
}