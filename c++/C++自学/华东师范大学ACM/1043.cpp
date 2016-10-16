#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	for(int b=0;b<a;b++)
	{
		int i;
		cin>>i;
		for(int j=0;j<i*3;j++)
		{
			for(int k=0;k<i;k++)
			{
				cout<<"ACM";
			}
			cout<<endl;
		} 
	}
	return 0;
} 
