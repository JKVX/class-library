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
	
	cout<<"���������Ҹ��˿͵�Ǯ����";
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
	cout<<"50Ԫ"<<fifty<<"�š�"<<endl;
	cout<<"20Ԫ"<<twenty<<"�š�"<<endl;
	cout<<"10Ԫ"<<ten<<"�š�"<<endl;
	cout<<"5Ԫ"<<five<<"�š�"<<endl;
	cout<<"1Ԫ"<<one<<"�š�"<<endl;
	 
	return 0;
	 
	
}
