#include<iostream>
using namespace std;
int main()
{
	int a,b;
	float c;
	char d;
	cout<<"输入运算：";
	cin>>a>>d>>b;
	if(d=='+')
		c=a+b;
	else if(d=='-')
			c=a-b;
		else if(d=='*')
				c=a*b;
			else if(b==0)
					cout<<"除数不能为零！"<<endl;
				else c=float(a)/b;
	cout<<'='<<c<<endl;
	return 0;
	 
} 
