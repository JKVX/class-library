#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream outData;
    outData.open("hah.dat"); 
	int a;
	cout<<"����һ����������";
	cin>>a; 
	int n=1;
	int b;//ȡ�� 
	int c;//ȡ�� 
	int total=0;//ƽ���� 
	while(n<=a)
	{
		c=n;
		if (n%7!=0)//���㲻��7��������Ȼ�ͽ�����һ������ 
		{
			
			while(c!=0)// ��cΪ�㣬���ʾȡ�ൽ�����λ�� 
			{
				b=c%10;//ȡ�� 
				c=c/10;//ȡ�� 
				if(b==7)//�ж������Ƿ�Ϊ7���ж��Ƿ�ĳλ��Ϊ7�� 
					c=0;//ʹѭ�������� 
				else 
				{
					if(c==0)//��ʾ����bΪ���λ 
					{
						if(b!=7)//���λҲ��Ϊ7������7����ء� 
						{
							total=total+n*n;//����ƽ���͡�
                            outData<<n<<endl; 
						}
					}
				}
			}
		
		
		}
		n++;			//n��1 
	}
	cout<<total;
	return 0;
}
