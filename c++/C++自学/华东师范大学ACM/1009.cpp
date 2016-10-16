#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  double a,total=0; 
  int count=1;
  while(count<=12)
  {
    cin>>a;
    total+=a;
    count++;
  }
  cout<<"гд";
  cout<<fixed<<setprecision(2)<<total/12.0;  
}
