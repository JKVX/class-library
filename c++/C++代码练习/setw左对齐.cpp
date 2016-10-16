#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a;
	cin>>a;
	cout.setf(ios::left);
	cout<<fixed<<setw(12)<<setprecision(4)<<a<<0<<endl;
}
 
