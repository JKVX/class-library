#include<iostream>
using namespace std;

int main()
{
	char a='a';
	while(a!=-1)
	{
		cout<<"������һ����д��ĸ��";
		cin>>a;
		if(a=='+')return 0;
		while(a<'A'||a>'Z')
		{
			cout<<"������Ĳ��Ǵ�д��ĸ��"<<endl<<endl;
			cout<<"��������һ����д��ĸ��";
			cin>>a;
		}
	
		a=a+'a'-'A';
		cout<<"����Сд��ĸ�ǣ�"<<a<<endl<<endl;
	}
}