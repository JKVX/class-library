#include<iostream>
using namespace std;

int main()
{
	int n,m,a,b;
	a=0;
	b=1;
	cout<<"����һ������������";
	cin>>n;

	while(n>0)
	{
		m=n%10;
		a=a+m*b;
		b=b*2;
		n=n/10;
		if (m>1)
		{
			cout<<"������Ĳ��Ƕ���������";
			return 0;
		}
	}
	cout<<"����ʮ�����ǣ�";
	cout<<a<<endl;
	return 0;
}