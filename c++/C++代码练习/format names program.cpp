#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream inData;
	ofstream outData;
	inData.open("name.dat");
	outData.open("name.out");

	string socialNum;
	string firstName;
	string lastName;
	string middleName;
	string initial;

	

	inData>>socialNum>>firstName>>middleName>>lastName;

	initial=middleName.substr(0,1)+'.';
	outData<<firstName<<' '<<middleName<<' '<<lastName<<' '<<socialNum<<endl;
	outData<<lastName<<","<<firstName<<' '<<middleName<<' '<<socialNum<<endl;
	outData<<lastName<<","<<firstName<<' '<<initial<<'	'<<socialNum<<endl;
	outData<<firstName<<' '<<initial<<' '<<lastName;
	inData.close();
	outData.close();
	return 0;
}