#include<iostream>
using namespace std;
void fun(int n)
{
	if(n<8)
		cout<<n;
	if(n>=8)
	{
		fun(n/8);
	cout<<n%8;
	}
}

int main()
{
	int n;
	cout<<"输入一个十进制数:";
	cin>>n;
	fun(n);
	cout<<endl;
	return 0;
}