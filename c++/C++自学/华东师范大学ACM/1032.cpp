#include<iostream>
using namespace std;
int main()
{
	int a;
	int b1,b2,b3,c1,c2,c3;
	int count,count1,count2;
	while(cin>>a)
	{
		cin>>b1>>c1;
		cin>>b2>>c2; 
		
		for(count=2,count1=0,count2=0;count<a;count++)
		{
			cin>>b3>>c3;
			if(b3==c1)
			{
				b1=b3;
				c1=c3;
				count1++;
			}
			else 
			{
				b2=b3;
				c2=c3;
				count2++;
			}
			if(c1==c2)
			{
				break;
			}
		}
		if(count1<count2)
		cout<<"You are my younger"<<endl;
		else if(count1==count2)
		cout<<"You are my brother"<<endl;
		else cout<<"You are my elder"<<endl;
	}
	return 0;
} 
