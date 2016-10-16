#include<iostream>
using namespace std;
bool isLeap(int year);
int main()
{
	int n;
	cin>>n;
	for(int m=0;m<n;m++)
	{
		int Y,N,count=0;
		cin>>Y>>N;
		if(isLeap(Y))
		{
			count++;
		}
		while(count<N)
		{
			Y=Y+(4-Y%4);
			if(isLeap(Y))
			{
				count++;
			}
		}
		cout<<Y<<endl;
	}
	return 0;
} 
bool isLeap(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	{
		return true;
	}
	return false;
}
