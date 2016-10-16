#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream outData;
	outData.open("data.dat");
	int a;//a为你想要输入的那个正整数。 
	int b; //b为任意1到9的数。 
	int total=0;//total为平方和； 
	int count=1; //计数器。 
	int number;//中间量。 
	char YorN='Y';//用于判断用户是否想要继续程序。 
	while(YorN=='Y')
	{
		cout<<"输入一个你想要进行计算的正整数：";
		cin>>a;
		while(a<=0)
		{
			cout<<"你输入的不是正整数请重新输入。"<<endl;
			cin>>a;
		}
		cout<<"输入你想要与之无关的数:";
		cin>>b;
		while(b<1||b>9)
		{
			cout<<"该数必须为0到9，请重新输入：";
			cin>>b;
		}
		
		
		count=1;
		total=0;
		while(count<=a)
		{
			number=count;
			if(number%b!=0)
				{
				
					while(number>0)
					{
						if(number-number/10*10==b)
							{
								outData<<count<<endl;
								break;
							}
						number=number/10;
						if(number==0)
						total=total+count*count;
					}
				}
			else outData<<count<<endl;
			count++;
		}
		cout<<"小于等于"<<a<<"的所有与"<<b
			<<"无关的数的平方和为：" <<total<<endl;
		cout<<"继续请输入Y，结束请输入N。";
		cin>>YorN;
	}
		 
	return 0; 
} 
