#include"Operator.h"
#include<fstream>
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
void Operator::Initialize()
{
	ifstream MyInput;
	ofstream MyOutput;
	MyInput.open("输入信息.txt");
	MyOutput.open("输出信息.txt");
	NODE *now,*pre;
	head=NULL;
	while(MyInput)
	{
		now=new NODE;
		MyInput>>now->KEY.Num
				>>now->KEY.Name
				>>now->KEY.PhoneNum
				>>now->KEY.Dorm;
		if(!MyInput)	break;
		if(head==NULL)
		{
			head=now;
			pre=head;
		}
		pre->next=now;
		now->next=NULL;
		pre=now;
	} 
	delete now;
	Sort();
	Write();
}
//*************************************************
void Operator::Add()
{
	NODE*p,*now;
	now=head;
	p=new NODE;
	cout<<"输入你想添加的联系人信息。"<<endl;
	cout<<"学号：";
	cin>>p->KEY.Num;
	while(now)
	{
		if(p->KEY.Num==now->KEY.Num)
		{
			cout<<"联系人已存在。"<<endl;
			return;
		}
		now=now->next; 
	}
	cout<<"姓名：";
	cin>>p->KEY.Name; 
	cout<<"联系电话：" ;
	cin>>p->KEY.PhoneNum;
	cout<<"寝室:";
	cin>>p->KEY.Dorm;
	p->next=head;
	head=p;
	cout<<"添加成功！"<<endl;
	cout<<"学号："<<p->KEY.Num<<' ' 
		<<"姓名:"<<p->KEY.Name<<' '
		<<"联系电话:"<<p->KEY.PhoneNum<<' '
		<<"寝室:"<<p->KEY.Dorm<<endl;
	Sort();
	Write();
} 
//*************************************************
void Operator::Delete()
{
	NODE*pre,*now; 
	now=head;
	string s;
	cout<<"输入你想删除的联系人姓名或学号：";
	cin>>s;
	while(now)
	{
		if(now->KEY.Name==s||now->KEY.Num==s)
		{
			cout<<"学号："<<now->KEY.Num<<' ' 
				<<"姓名:"<<now->KEY.Name<<' '
				<<"联系电话:"<<now->KEY.PhoneNum<<' '
				<<"寝室:"<<now->KEY.Dorm<<endl;
			cout<<"确认删除请输入1，取消请输入除1以外任意键:";
			char a;
			a=getch();
			cout<<a<<endl;
			if(a=='1')
			{
				if(now==head)
				{
					head=head->next;
					delete now;
				}
				else if(now->next==NULL)
				{
					pre->next=NULL;
					delete now;
				}
				else 
				{
					pre->next=now->next;
					delete now;
				}
				cout<<"删除成功！"<<endl<<endl; 
				Write();
				return; 
			}
			else  return;
		}
		pre=now;
		now=now->next;	
	} 	
	cout<<"没有找到该联系人。"<<endl<<endl;
} 
//**************************************************
void Operator::Search()
{
	NODE*p;
	p=head;
	string s;
	cout<<"输入你想查找的联系人姓名或学号：";
	cin>>s;
	while(p)
	{
		if(p->KEY.Name==s||p->KEY.Num==s)
		{
			cout<<"学号："<<p->KEY.Num<<' ' 
				<<"姓名:"<<p->KEY.Name<<' '
				<<"联系电话:"<<p->KEY.PhoneNum<<' '
				<<"寝室:"<<p->KEY.Dorm<<endl<<endl;
			return;
		}
		p=p->next;	
	}
	cout<<s<<" can't be found."<<endl<<endl;
	Write();
}
//*******************************************************
void Operator::Write()
{
	NODE *p;
	ofstream MyOutput;
	MyOutput.open("输出信息.txt");
	p=head;
	while(p)
	{
		MyOutput.setf(ios::left);
		MyOutput<<setw(18)<<p->KEY.Num
			<<setw(16)<<p->KEY.Name
			<<setw(26)<<p->KEY.PhoneNum
			<<p->KEY.Dorm<<endl;
		p=p->next; 
	}
}
//**************************************************
void Operator::Sort()
{
	NODE *pre,*now;
	pre=head;
	while(pre)
	{
		now=head;
		while(now->next)
		{
			if(now->KEY.Num>now->next->KEY.Num)
			{
				NODE *temp;
				temp=new NODE;
				temp->KEY=now->KEY;
				now->KEY=now->next->KEY;
				now->next->KEY=temp->KEY;
				delete temp;
			}
			now=now->next; 
		}
		pre=pre->next;
	} 
}
//**************************************************
void Operator::Change()
{
	cout<<"输入你想修改的联系人姓名或学号：";
	string a;
	cin>>a;
	NODE *p;
	p=head;
	while(p)
	{
		if(a==p->KEY.Name||a==p->KEY.Num)
		{
			cout<<"学号："<<p->KEY.Num<<' ' 
				<<"姓名:"<<p->KEY.Name<<' '
				<<"联系电话:"<<p->KEY.PhoneNum<<' '
				<<"寝室:"<<p->KEY.Dorm<<endl;
			cout<<"修改为：";
			cout<<"学号：";
			cin>>p->KEY.Num; 
			cout<<"姓名： ";
			cin>>p->KEY.Name;
			cout<<"联系电话： " ;
			cin>>p->KEY.PhoneNum;
			cout<<"寝室: ";				
			cin>>p->KEY.Dorm;
			Write();
			cout<<"修改成功！"<<endl;
			cout<<"学号："<<p->KEY.Num<<' ' 
			<<"姓名:"<<p->KEY.Name<<' '
			<<"联系电话:"<<p->KEY.PhoneNum<<' '
			<<"寝室:"<<p->KEY.Dorm<<endl;//显示刚刚添加的联系人。 
			return; 
		}
		p=p->next;
	} 
	cout<<"没有找到该联系人。"<<endl<<endl;
}
//************************************************
void Operator::Print()
{
	NODE*p;
	p=head;
	cout<<"学号              姓名            \
联系电话                  寝室" <<endl; 
	while(p)
	{
		cout.setf(ios::left);
		cout<<setw(18)<<p->KEY.Num
			<<setw(16)<<p->KEY.Name
			<<setw(26)<<p->KEY.PhoneNum
			<<p->KEY.Dorm<<endl;
		p=p->next; 
	}
}
//*******************************************
void Operator::FinialWrite()
{
	NODE *p;
	ofstream MyOutput;
	MyOutput.open("输入信息.txt");
	p=head;
	while(p)
	{
		MyOutput.setf(ios::left);
		MyOutput<<setw(18)<<p->KEY.Num
			<<setw(16)<<p->KEY.Name
			<<setw(26)<<p->KEY.PhoneNum
			<<p->KEY.Dorm<<endl;
		p=p->next; 
	}
}
//*****************************************************
Operator::~Operator()
{
	NODE*p;
	p=head;
	while(p)
	{
		head=head->next;
		delete p;
		p=head;
	}
}


 
