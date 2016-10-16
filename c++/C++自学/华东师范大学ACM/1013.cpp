#include<iostream>
using namespace std;
int main()
{
	int a,count,ave,total;
	cin>>a;
	while(a!=0)
	{
		int b[a];
		count=0;
		total=0;
		while(count<a)
		{
			cin>>b[count];
			total=total+b[count];
			count++;
		}
		ave=total/a;
		count=0;
		total=0;
		while(count<a)
		{
			if(b[count]>ave)total=total+b[count]-ave;
			count++;
		}
		cout<<total<<endl<<endl;
		cin>>a;
	}
	return 0;
}
 
