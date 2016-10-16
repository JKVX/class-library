#include<iostream>
using namespace std;
int main()
{
	int h1,h2,m1,m2;
	char a;
	while(cin>>h1>>a>>m1>>h2>>a>>m2)
	{
		int h3,m3;
		bool t=0;
		m3=m1-m2;
		if(m3<0)
		{
			t=1;
			m3=m3+60;
		}
		h3=h1-h2-t;
		if(h3<0)
			h3=h3+24;
		if(h3<10)
			cout<<0<<h3<<':';
		else cout<<h3<<':';
		if(m3<10)
			cout<<0<<m3<<endl;
		else cout<<m3<<endl;
	}
	return 0;
}
