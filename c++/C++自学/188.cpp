#include<iostream>
using namespace std ;
int main()
{
	int a,b,c;
	int number=10; 
	cout<<"��������һ����λ������0-2����";
	cin>>a;
	cout<<"��������һ����λ������0-4����";
	cin>>b;
	cout<<"��������һ����λ������0-6����";
	cin>>c;
	while(number<=100)
	{
		if(number%3==a)
			if(number%5==b)
				if(number%7==c)
				{
					cout<<"����Ϊ��"<<number;
					break;
					
				}
		number++;
	}
	return 0;
	
	 
} 
