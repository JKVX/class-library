#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	for(b=0;b<a;b++)
	{
		int c,d,count,total=0;
		cin>>c>>d;
		int grade[c];
		for(count=0;count<c;count++)
		{
			cin>>grade[count];
		}
		for(count=0;count<c;count++)
		{
			if(grade[count]>grade[d-1])
			total++;
		}
		cout<<total<<endl;
	}
	return 0;
} 
