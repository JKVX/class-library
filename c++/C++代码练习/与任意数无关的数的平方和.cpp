#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream outData;
	outData.open("data.dat");
	int a;//aΪ����Ҫ������Ǹ��������� 
	int b; //bΪ����1��9������ 
	int total=0;//totalΪƽ���ͣ� 
	int count=1; //�������� 
	int number;//�м����� 
	char YorN='Y';//�����ж��û��Ƿ���Ҫ�������� 
	while(YorN=='Y')
	{
		cout<<"����һ������Ҫ���м������������";
		cin>>a;
		while(a<=0)
		{
			cout<<"������Ĳ������������������롣"<<endl;
			cin>>a;
		}
		cout<<"��������Ҫ��֮�޹ص���:";
		cin>>b;
		while(b<1||b>9)
		{
			cout<<"��������Ϊ0��9�����������룺";
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
		cout<<"С�ڵ���"<<a<<"��������"<<b
			<<"�޹ص�����ƽ����Ϊ��" <<total<<endl;
		cout<<"����������Y������������N��";
		cin>>YorN;
	}
		 
	return 0; 
} 
