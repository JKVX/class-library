#include<iostream>
using namespace std;
int main()
{
	int a,b;
	float c;
	char d;
	cout<<"�������㣺";
	cin>>a>>d>>b;
	if(d=='+')
		c=a+b;
	else if(d=='-')
			c=a-b;
		else if(d=='*')
				c=a*b;
			else if(b==0)
					cout<<"��������Ϊ�㣡"<<endl;
				else c=float(a)/b;
	cout<<'='<<c<<endl;
	return 0;
	 
} 
