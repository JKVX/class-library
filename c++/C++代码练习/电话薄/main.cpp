#include<iostream>
#include<string>
#include<fstream>
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include"Operator.h" 
using namespace std;
const string T="1.��ʼ��  2.�����ϵ��  3.ɾ����ϵ��  4.������ϵ��\n\
5.�޸���ϵ��  6.��ʾ������ϵ��  7.�˳�\n������ִ�еĲ�����";
int main()
{
	Operator ClassOne;
	ClassOne.Initialize();
	char chosen;
	cout<<T;
	while(1)
	{
		chosen=getch();
		system("cls");
		cout<<T;
		cout<<chosen<<endl;
		switch(chosen)
		{
			case '1':ClassOne.Initialize();break;
			case '2':ClassOne.Add();break;
			case '3':ClassOne.Delete();break;
			case '4':ClassOne.Search();break;
			case '5':ClassOne.Change();break;
			case '6':ClassOne.Print();break;
			case '7':ClassOne.FinialWrite();return 0;
			default:cout<<"��Ч�������������롣"<<endl;break;
		}
		cout<<endl<<T;
	}
	return 0;	
}

