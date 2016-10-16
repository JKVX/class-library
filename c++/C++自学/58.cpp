#include<iostream> 
using namespace std;
int main()
{
	int money;
	int fifty=0;
	int twenty=0;
	int ten=0;
	int five=0;
	int one=0;
	
	cout<<"输入你想找给顾客的钱数：";
	cin>>money;
	
	if(money>=50)
	{
		fifty=money/50;
		money=money-fifty*50;
	}
	if(money>=20)
	{
		twenty=money/20;
		money=money-twenty*20;
	}
	if(money>=10)
	{
		ten=money/10;
		money=money-ten*10;
	}
	if(money>=5)
	{
		five=money/5;
		money=money-five*5;
	}
	if(money>=1)
		one=money/1;
	cout<<"50元"<<fifty<<"张。"<<endl;
	cout<<"20元"<<twenty<<"张。"<<endl;
	cout<<"10元"<<ten<<"张。"<<endl;
	cout<<"5元"<<five<<"张。"<<endl;
	cout<<"1元"<<one<<"张。"<<endl;
	 
	return 0;
	 
	
}
