#include<iostream>
using namespace std;
int main()
{
	int a[4];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3])
	{
		int count;
		for(count=0;count<4;count++)
		{
			if(a[count]==1||a[count]==4)
			cout<<"   ";
			else cout<<" _ ";	 
		}
		cout<<endl;
		for(count=0;count<4;count++)
		{
			switch(a[count])
			{
				case 1:cout<<"  |";break;
				case 2:
				case 3:cout<<" _|";break;
				case 4:
				case 8:
				case 9:cout<<"|_|";break;
				case 5:
				case 6:cout<<"|_ ";break;
				case 7:cout<<"  |";break;
				case 0:cout<<"| |";break;
			}
		}
		cout<<endl;
		for(count=0;count<4;count++)
		{
			switch(a[count])
			{
				case 1:
				case 4:
				case 7:cout<<"  |";break;
				case 2:cout<<"|_ ";break;
				case 3:
				case 5:
				case 9:cout<<" _|";break;
				case 6:
				case 8:
				case 0:cout<<"|_|";break;
			}
		}
		cout<<endl;
	}
	return 0;
} 
