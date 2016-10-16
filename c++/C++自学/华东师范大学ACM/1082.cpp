#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		if(n%2==1)cout<<1<<endl;
		else if(n%4==2)cout<<2<<endl;
		else if(n%8==4)cout<<4<<endl;
		else if(n%16==8)cout<<8<<endl;
		else if(n%32==16)cout<<16<<endl;
		else if(n%64==32)cout<<32<<endl;
		else cout<<64<<endl;
		cin>>n;
	}
	return 0;
}

