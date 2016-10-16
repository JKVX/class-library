#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	for(b=0;b<a;b++)
	{
		double Y,e,Q,f,g;
		cin>>Y>>Q>>e>>f>>g;
		cout<<fixed<<setprecision(1)
			<<(Y*(1+e/100*Q/365))*(1+g/100)<<endl;
		cout<<Y*(1+f/100*(Q+365)/365)<<endl;
	}
	return 0;
} 
