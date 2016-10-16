#include<iostream>
using namespace std;
int main()
{
	int a,b=0,c1,c2,c3,d1,d2,d3;
	cin>>a;
	while(b<a)
	{
		cin>>c1>>c2>>c3>>d1>>d2>>d3;
		if(c1>d1)cout<<"First"<<endl;
		else if(c1<d1)cout<<"Second"<<endl;
		else if(c2>d2)cout<<"First"<<endl;
		else if(c1<d1)cout<<"Second"<<endl;
		else if(c3>d3)cout<<"First"<<endl;
		else if(c3<d3)cout<<"Second"<<endl;
		else cout<<"Same"<<endl;
		b++;
	}
	return 0;
} 
