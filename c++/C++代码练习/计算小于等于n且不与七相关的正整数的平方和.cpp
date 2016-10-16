#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream outData;
    outData.open("hah.dat"); 
	int a;
	cout<<"输入一个正整数：";
	cin>>a; 
	int n=1;
	int b;//取余 
	int c;//取整 
	int total=0;//平方和 
	while(n<=a)
	{
		c=n;
		if (n%7!=0)//满足不被7整除，不然就进行下一个数。 
		{
			
			while(c!=0)// 若c为零，则表示取余到了最高位。 
			{
				b=c%10;//取余 
				c=c/10;//取整 
				if(b==7)//判断余数是否为7即判断是否某位数为7。 
					c=0;//使循环跳出。 
				else 
				{
					if(c==0)//表示余数b为最高位 
					{
						if(b!=7)//最高位也不为7，即与7不相关。 
						{
							total=total+n*n;//计算平方和。
                            outData<<n<<endl; 
						}
					}
				}
			}
		
		
		}
		n++;			//n加1 
	}
	cout<<total;
	return 0;
}
