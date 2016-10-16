#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int total=1,i;
		for(i=1;i<32;i++)
		{
			total=total*2;
			if(total%n==1)
			{
				cout<<"2^"<<i<<" mod "<<n<<" = 1"<<endl;
				break;
			}
		}
		if(i==32)cout<<"2^? mod "<<n<<" = 1"<<endl;
	}
	return 0;
} 
