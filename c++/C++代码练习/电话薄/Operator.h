#include<iostream>
using namespace std;
struct phoneType
{
	string Name;
	string PhoneNum;
	string Dorm;
	string Num;
};
//*******************************************
struct NODE
{
	phoneType KEY;
	NODE *next;
}; 
//********************************************
class Operator
{
public:
	void Add();
	void Delete();
	void Search();
	void Initialize();
	void Change();
	void Print();
	void FinialWrite();
	~Operator(); 
private:
	NODE *head;
	void Write();
	void Sort();	
};

