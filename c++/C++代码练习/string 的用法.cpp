//*************************************************************
//PrintName program
//This program prints a name in two different formates(∏Ò Ω)
//************************************************************* 
#include<iostream>
#include<string>
using namespace std;
const string FIRST="Herman";//person's first name
const string LAST="Smith";//person's last name
const char MIDDLE='G';//person's middle inital
int main()
{
	string firstLast;//Name in first-last format
	string lastFirst;//Name in last-first formar
	firstLast=FIRST+" "+LAST;
	cout<<"Name in last-first format is"<<firstLast<<endl;
	lastFirst=LAST+" "+FIRST+",";
	cout<<"Name in last-first format is";
	cout<<lastFirst<<MIDDLE<<','<<endl;
	return 0;
}
