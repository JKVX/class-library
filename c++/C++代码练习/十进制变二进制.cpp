#include <iostream>
using namespace std;
void fun(int n)
{
   if(n<2)   
       cout<<n;
   if(n>=2)  
   {
     fun(n/2);
     cout<<n%2;
   }
}
void main()
{ 
  int n;
  cout<<"����ʮ������N��";
  cin>>n;
  fun(n);        
  cout<<endl; 
} 
