#include<iostream>
using namespace std;
int main()
{
	long  total;
	int a,n,m;
	
	while(cin>>a)
	{
		long arr[100000];
		total=0;
		for(n=0;n<a;n++)
			cin>>arr[n];
		for(m=0;m<a;m++)
			total=total+arr[m]*arr[m];
		cout<<total<<endl;
	}
	return 0;
}
