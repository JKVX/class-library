#include<iostream>
using namespace std;
int Fact(int n)
{
	if(n==0)return 1;
	else return n*Fact(n-1);
}
int main()
{
	int count;
	cin>>count;
	cout<<count<<"µÄ½×³ËÊÇ"<<Fact(count)<<endl;
	return 0;
}