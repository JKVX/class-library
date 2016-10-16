#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,j;
	while(cin>>i>>j)
	{
		int *p;
		p=new int[i+j];
		for(int n=0;n<i+j;n++)
		{
			cin>>p[n];
		}
		sort(p,p+i+j);
		for(int m=0;m<i+j-1;m++)
		{
			if(p[m]!=p[m+1])
			cout<<p[m]<<' ';
		}
		cout<<p[i+j-1]<<endl;
	}
	return 0;
} 
