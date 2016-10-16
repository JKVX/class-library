#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	for(b=0;b<a;b++)
	{
		int c,d,e,total=0;
		cin>>c;
		for(d=0;d<c;d++)
		{
			cin>>e;
			total=total+e;
		}
		cout<<total<<endl<<endl;	
	}
	return 0;
} 
