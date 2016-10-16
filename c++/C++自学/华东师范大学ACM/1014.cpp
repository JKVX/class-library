#include<iostream>
using namespace std;
int main()
{
	int a,i,j,b[100],total;
	cin>>a;
	while(a!=0)
	{
		total=0;
	for(i=0;i<a;i++)
		cin>>b[i];
	for(i=0;i<a-1;i++)
	for(j=0;j<a-1-i;j++)
		if(b[j]>b[j+1])
		{
			int temp;
			temp=b[j+1];
			b[j+1]=b[j];
			b[j]=temp;
		}
	for(i=0;i<a/2+1;i++)
	total=total+b[i]/2+1;
	cout<<total<<endl;
	cin>>a;
	}
	return 0;	
} 
