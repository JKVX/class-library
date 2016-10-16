#include<iostream>
#include<string>
#include<fstream>
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include"Operator.h" 
using namespace std;
const string T="1.初始化  2.添加联系人  3.删除联系人  4.查找联系人\n\
5.修改联系人  6.显示所有联系人  7.退出\n请输入执行的操作：";
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
			default:cout<<"无效操作，重新输入。"<<endl;break;
		}
		cout<<endl<<T;
	}
	return 0;	
}

