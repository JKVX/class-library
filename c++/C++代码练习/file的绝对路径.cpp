#include<fstream>
using namespace std;
int main()
{
	int a,b,c,d;
	ifstream inData;
	ofstream outData;
	inData.open("E:\\��ѧ\\c++������ϰ\\loan,in");
	outData.open("E:\\��ѧ\\c++������ϰ\\loan.out");
	inData>>a>>b>>c>>d;
	outData<<a+b+c+d;
	
} 
