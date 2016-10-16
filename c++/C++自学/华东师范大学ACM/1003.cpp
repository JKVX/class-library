#include<iostream>
using namespace std;
int main()
{
	int a; 
	while(cin>>a)
	{
		if(a!=0)
		{
			int b,total=0,c;
			for(b=0;b<a;b++)
			{ 
				cin>>c;
				total=total+c;
			}
			cout<<total<<endl;
		}
		else break;
	}
	return 0; 
} 
