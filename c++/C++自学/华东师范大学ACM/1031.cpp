#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int h1,m1,h2,m2,count;
	double a,b,t;
	cout<<"Initial time  Final time  Passes"<<endl;
	while(cin>>h1>>m1>>h2>>m2)
	{
		count=0;
		t=(h2-h1)*60+m2-m1;//��ʱ�䡣
		if(t<=0)t=t+720; 
		a=(h1*60+m1)/2.0;//ʱ��ĽǶȡ� 
		b=m1*6.0;//����ĽǶȡ� 
		b=a-b;//ʱ�������ĽǶȲ 
		if(b<0) b=b+360.0;
		t=t-b/(5.5);//��һ��������ʱ�䡣 
		while(t>0)
		{
			count++;
			t=t-360.0/5.5;
		}
		cout<<"       ";
		if(h1<10)cout<<0<<h1<<':';
		else cout<<h1<<':';
		if(m1<10)cout<<0<<m1;
		else cout<<m1; 
		cout<<"       ";
		if(h2<10)cout<<0<<h2<<':';
		else cout<<h2<<':';
		if(m2<10)cout<<0<<m2;
		else cout<<m2;
		cout<<"      "<<setw(2)<<count<<endl;	
	}
	return 0;
} 
