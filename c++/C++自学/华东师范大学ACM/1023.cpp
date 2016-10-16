#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	for(b=0;b<a;b++)
	{
		int c;
		cin>>c;
		if(c>=300)
		c=c-c/50*50;
		else if(c>=200)c=c-200;
		else if(c>=150)c=c-150;
		cout<<c<<endl;
	}
	return 0;
} 
