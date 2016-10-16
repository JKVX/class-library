#include<iostream> 
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int *p;
		int lostNum=0;
		p=new int [n*2-1];
		for(int m=0;m<n*2-1;m++)
		{
			cin>>p[m];
			lostNum=lostNum^p[m];
		}
		cout<<lostNum<<endl;
	}
	return 0;
} 
