#include<fstream>
using namespace std;
int main()
{
	int a,b,c,d;
	ifstream inData;
	ofstream outData;
	inData.open("E:\\大学\\c++代码练习\\loan,in");
	outData.open("E:\\大学\\c++代码练习\\loan.out");
	inData>>a>>b>>c>>d;
	outData<<a+b+c+d;
	
} 
