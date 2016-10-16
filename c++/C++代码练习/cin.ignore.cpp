#include<iostream>
using namespace std;
int main()
{
	char a,b;
	cin>>a;
	cin.ignore(15,'A');
	cin>>b;
	cout<<a<<b;
	return 0;
}