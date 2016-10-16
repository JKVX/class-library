#include<fstream>
using namespace std;
int main()
{
	int a;
	int b;
	float c;
	double d;
	ifstream inData;
	ofstream outData;
	inData.open("loan.in");
	outData.open("loan.out");
	inData>>a>>b>>c>>d;
	outData<<a+b<<endl<<b+c<<endl<<c+d<<endl<<d+a<<endl;
	return 0;
	

}
 
