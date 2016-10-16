#include<iostream>
#include<cmath> 
using namespace std;
int sortnum(int);
int main()
{
	int num;
	int count=1;
	while(count<=3)
	{ 
		cin>>num;
		if(!sortnum(num))
			cout<<num<<"不是素数。"<<endl;
		else  cout<<num<<"是素数。"<<"组成的最小三位数是："
				<<sortnum(num)<<endl;
		count++;
	}
	return 0;
}
int sortnum(int num)
{
	int count=2;
	int a,b,c;
	int d=sqrt(num);
	while(count<=d) 
	{
		if(num%count==0)//判断是否为素数。
			return 0;
		else if(count== d)
			{
				a=num/100;//取百位上的数字。 
				b=(num-a*100)/10;//取十位上的数字。 
				c=num-a*100-b*10;//取个位上的数字。
				if(b==0)
					if(a>=c)
						return 100*c+10*b+a;
					else return 100*a+10*b+c;//如果b为0，则b无法做百位。 
				else if(a>=b&&b>=c)
					return 100*c+10*b+a;
				else if(a>=c&&c>=b)
					return 100*b+10*c+a;
				else if(b>=c&&c>=a)
					return 100*a+10*c+b;
				else if(b>=a&&a>=c)
					return 100*c+10*a+b;
				else if(c>=a&&a>=b)
					return 100*b+10*a+c;
				else return 100*a+10*b+c; 
			}
		count++;			
	}
}  
