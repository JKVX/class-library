#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  char a;
  bool b=1;
  int count=0;
  double total=0.0;
  while(cin.get(a))
  {
  	if(a!=' ')
  	{
  		if(a!='\n')
  		switch(a)
    	{
		 case 'A': total=total+4.0;count++;break;
      	 case 'B':total=total+3.0;count++;break;
      	 case 'C':total=total+2.0;count++;break;
      	 case 'D':total=total+1.0;count++;break;
      	 case 'F':total=total;count++;break;
		 default:cout<<"Unknown"<<endl;count=0;total=0.0;
		 		cin.ignore(100,'\n');
		}
		else 
		{
			cout<<fixed<<setprecision(2)<<total/count<<endl;
			count=0;
			total=0.0;
		}
	}
  }
  return 0;
}
