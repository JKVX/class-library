#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double  a,b,c=0,d=0,total=0,s;
	int h,m;
	cin>>a>>b;
	while(cin>>a>>b>>c>>d)
	{
		total=total+(sqrt((a-c)*(a-c)+(b-d)*(b-d)))/1000;
	}
	total=total*2;
	h=int(total/20);
	m=(int)(total-h*20)*3;
	s=(total-h*20)*3-m;
	if(int(s+0.5))m++;//ÅÐ¶ÏÃëµÄ½øÎ»£» 
	if(h<10)cout<<0<<h<<':';
	else cout<<h<<':';
	if(m<10)cout<<0<<m;
	else cout<<m;
	return 0;
} 
