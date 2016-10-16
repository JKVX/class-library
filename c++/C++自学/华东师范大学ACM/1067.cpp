#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)break;
		double total=0;
		for(double i=n,j=2;i>1;i--,j=j+2)
		{
			total=total+1/i*j;
		}
		cout<<fixed<<setprecision(2)<<total+n<<endl;
		
	}
	return 0;
}
