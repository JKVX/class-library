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
			cout<<num<<"����������"<<endl;
		else  cout<<num<<"��������"<<"��ɵ���С��λ���ǣ�"
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
		if(num%count==0)//�ж��Ƿ�Ϊ������
			return 0;
		else if(count== d)
			{
				a=num/100;//ȡ��λ�ϵ����֡� 
				b=(num-a*100)/10;//ȡʮλ�ϵ����֡� 
				c=num-a*100-b*10;//ȡ��λ�ϵ����֡�
				if(b==0)
					if(a>=c)
						return 100*c+10*b+a;
					else return 100*a+10*b+c;//���bΪ0����b�޷�����λ�� 
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
