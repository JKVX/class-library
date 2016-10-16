#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	for(b=0;b<a;b++)
	{
		int c,d,count=0,count1=0;
		cin>>c;
		for(d=0;d<c;d++)
		{
			char first,second;
			cin>>first>>second;
			if(first=='R'&&second=='S'
			||first=='S'&&second=='P'
			||first=='P'&&second=='R') count++;
			if(first=='S'&&second=='R'
			||first=='P'&&second=='S'
			||first=='R'&&second=='P') count1++;
		}
		if(count==count1)cout<<"TIE"<<endl;
		else if(count<count1)cout<<"Player 2"<<endl;
		else cout<<"Player 1"<<endl; 
	}
	return 0;
}
