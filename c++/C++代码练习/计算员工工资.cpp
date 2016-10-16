#include<iostream>
#include<fstream>
using namespace std;

const float MAX_HOUR=40.0;
const float OVERTIME=1.5;

void CalcPay(float hours,float payrate,float& wages)
{
	if(hours>MAX_HOUR)
		wages=MAX_HOUR*payrate+(hours-MAX_HOUR)*payrate*OVERTIME;
	else wages=hours*payrate;
}

int main()
{
	float wages;
	float hours;
	float total=0.0;
	float payrate;
	int empnum;
	ofstream payfile;
	payfile.open("payfile.dat");

	cout<<"Enter the employee number:";
	cin>>empnum;

	while(empnum!=0)
	{
		cout<<"Enter hours worked:";
		cin>>hours;
		cout<<"Enter the payrate:";
		cin>>payrate;

		CalcPay(hours,payrate,wages);
		total=total+wages;

		cout<<"Wages:"<<wages<<endl<<endl;
		payfile<<"Empnum:"<<empnum<<"Hours:"<<hours<<"Payrate:"<<payrate<<"Wages:"<<wages<<endl;
        cout<<"Enter the employee number:";
       	cin>>empnum;
	}
	cout<<"Total is "<<total<<endl;
	payfile<<"Total is "<<total<<endl;
	return 0;
}

