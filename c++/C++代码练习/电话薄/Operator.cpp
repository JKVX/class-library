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
	MyInput.open("������Ϣ.txt");
	MyOutput.open("�����Ϣ.txt");
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
	cout<<"����������ӵ���ϵ����Ϣ��"<<endl;
	cout<<"ѧ�ţ�";
	cin>>p->KEY.Num;
	while(now)
	{
		if(p->KEY.Num==now->KEY.Num)
		{
			cout<<"��ϵ���Ѵ��ڡ�"<<endl;
			return;
		}
		now=now->next; 
	}
	cout<<"������";
	cin>>p->KEY.Name; 
	cout<<"��ϵ�绰��" ;
	cin>>p->KEY.PhoneNum;
	cout<<"����:";
	cin>>p->KEY.Dorm;
	p->next=head;
	head=p;
	cout<<"��ӳɹ���"<<endl;
	cout<<"ѧ�ţ�"<<p->KEY.Num<<' ' 
		<<"����:"<<p->KEY.Name<<' '
		<<"��ϵ�绰:"<<p->KEY.PhoneNum<<' '
		<<"����:"<<p->KEY.Dorm<<endl;
	Sort();
	Write();
} 
//*************************************************
void Operator::Delete()
{
	NODE*pre,*now; 
	now=head;
	string s;
	cout<<"��������ɾ������ϵ��������ѧ�ţ�";
	cin>>s;
	while(now)
	{
		if(now->KEY.Name==s||now->KEY.Num==s)
		{
			cout<<"ѧ�ţ�"<<now->KEY.Num<<' ' 
				<<"����:"<<now->KEY.Name<<' '
				<<"��ϵ�绰:"<<now->KEY.PhoneNum<<' '
				<<"����:"<<now->KEY.Dorm<<endl;
			cout<<"ȷ��ɾ��������1��ȡ���������1���������:";
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
				cout<<"ɾ���ɹ���"<<endl<<endl; 
				Write();
				return; 
			}
			else  return;
		}
		pre=now;
		now=now->next;	
	} 	
	cout<<"û���ҵ�����ϵ�ˡ�"<<endl<<endl;
} 
//**************************************************
void Operator::Search()
{
	NODE*p;
	p=head;
	string s;
	cout<<"����������ҵ���ϵ��������ѧ�ţ�";
	cin>>s;
	while(p)
	{
		if(p->KEY.Name==s||p->KEY.Num==s)
		{
			cout<<"ѧ�ţ�"<<p->KEY.Num<<' ' 
				<<"����:"<<p->KEY.Name<<' '
				<<"��ϵ�绰:"<<p->KEY.PhoneNum<<' '
				<<"����:"<<p->KEY.Dorm<<endl<<endl;
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
	MyOutput.open("�����Ϣ.txt");
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
	cout<<"���������޸ĵ���ϵ��������ѧ�ţ�";
	string a;
	cin>>a;
	NODE *p;
	p=head;
	while(p)
	{
		if(a==p->KEY.Name||a==p->KEY.Num)
		{
			cout<<"ѧ�ţ�"<<p->KEY.Num<<' ' 
				<<"����:"<<p->KEY.Name<<' '
				<<"��ϵ�绰:"<<p->KEY.PhoneNum<<' '
				<<"����:"<<p->KEY.Dorm<<endl;
			cout<<"�޸�Ϊ��";
			cout<<"ѧ�ţ�";
			cin>>p->KEY.Num; 
			cout<<"������ ";
			cin>>p->KEY.Name;
			cout<<"��ϵ�绰�� " ;
			cin>>p->KEY.PhoneNum;
			cout<<"����: ";				
			cin>>p->KEY.Dorm;
			Write();
			cout<<"�޸ĳɹ���"<<endl;
			cout<<"ѧ�ţ�"<<p->KEY.Num<<' ' 
			<<"����:"<<p->KEY.Name<<' '
			<<"��ϵ�绰:"<<p->KEY.PhoneNum<<' '
			<<"����:"<<p->KEY.Dorm<<endl;//��ʾ�ո���ӵ���ϵ�ˡ� 
			return; 
		}
		p=p->next;
	} 
	cout<<"û���ҵ�����ϵ�ˡ�"<<endl<<endl;
}
//************************************************
void Operator::Print()
{
	NODE*p;
	p=head;
	cout<<"ѧ��              ����            \
��ϵ�绰                  ����" <<endl; 
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
	MyOutput.open("������Ϣ.txt");
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


 
