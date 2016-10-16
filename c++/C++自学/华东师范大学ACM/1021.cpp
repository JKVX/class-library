#include<iostream>
using namespace std;
int main()
{
	char a;
	int i=0,j=0;
	while(cin>>a)
	{
		if(a=='(')i++;
		else if(a==')')j++;
		else 
		{
			cout<<i-j<<endl;
			i=0;
			j=0;
			cin.ignore(1000,'\n');
		}
	}
	return 0;
} 
