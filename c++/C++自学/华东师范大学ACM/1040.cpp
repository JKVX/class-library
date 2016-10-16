#include<iostream>
using namespace std;
int main()
{
	string s1,s2;
	int n;
	cin>>n;
	for(int m=0;m<n;m++)
	{
		cin>>s1>>s2;
		int l1,l2;
		l1=s1.length();
		l2=s2.length();
		for(int i=1;i<=l1/2;i++)
		{
			cout<<s1[i-1];
		}
		for(int j=l1/2+1;j<=l1/2+l2;j++)
		{
			cout<<s2[j-l1/2-1];
		}	
		for(int k=l1/2+l2+1;k<=l1+l2;k++)
		{
			cout<<s1[k-l2-1];
		}
		cout<<endl;
	}
	return 0;
} 
