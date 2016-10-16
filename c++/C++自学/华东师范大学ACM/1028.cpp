#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int h,m,s,v,h1=0,m1=0,s1=0,v1=0;
	double total=0,total1=0;
	char a;
	while(cin>>h>>a>>m>>a>>s)
	{
		cin.get(a);
		if(a=='\n')
		{
			total=total1+((h-h1)+(m-m1)/60.0+(s-s1)/3600.0)*v1;
			if(h<10)
			cout<<0<<h<<':';
			else cout<<h<<':';
			if(m<10)
			cout<<0<<m<<':';
			else cout<<m<<':';
			if(s<10)
			cout<<0<<s<<' ';
			else cout<<s<<' ';
			cout<<fixed<<setprecision(2)<<total<<" km"<<endl;
				
		}
		else 
		{
			cin>>v;
			total1=total1+((h-h1)+(m-m1)/60.0+(s-s1)/3600.0)*v1; 
			h1=h;
			m1=m;
			s1=s;
			v1=v;
		}
	}
	return 0;
} 
