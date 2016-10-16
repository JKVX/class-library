#include<iostream>
using namespace std ;
int main()
{
	int a,b,c;
	int number=10; 
	cout<<"输入三人一排排位人数（0-2）：";
	cin>>a;
	cout<<"输入五人一排排位人数（0-4）：";
	cin>>b;
	cout<<"输入七人一排排位人数（0-6）：";
	cin>>c;
	while(number<=100)
	{
		if(number%3==a)
			if(number%5==b)
				if(number%7==c)
				{
					cout<<"人数为："<<number;
					break;
					
				}
		number++;
	}
	return 0;
	
	 
} 
