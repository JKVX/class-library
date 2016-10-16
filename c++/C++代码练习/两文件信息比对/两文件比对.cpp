#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream Myfile_name;
	ifstream Myfile_id;
	ofstream Myfile_result;
	Myfile_name.open("name.txt");
	Myfile_id.open("id.txt");
	Myfile_result.open("result.txt");
	string num_name,num_id;
	string course,cost;
	string name_name;
	Myfile_id>>num_id>>course>>cost;
	while(Myfile_name>>num_name>>name_name)
	{	
		while(num_name==num_id)
		{
			Myfile_result<<num_name<<' '<<name_name<<' '<<course<<endl;
			Myfile_id>>num_id>>course>>cost;
			if(!Myfile_id)break;
		}
	}
} 
