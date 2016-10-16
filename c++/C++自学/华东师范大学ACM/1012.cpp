#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a,b,c[12],max=0.0;
	int count=0;
	cin>>a;
	while(count<12)
	{
		cin>>c[count];
		if(c[count]>=max)max=c[count];
		count++;
	}
	cout<<fixed<<setprecision(2)<<a*max<<endl;
	return 0;
} 
