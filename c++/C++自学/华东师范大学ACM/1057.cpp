#include<iostream>
#include<string>
using namespace std;
bool isNine(string a);
int main()
{
	string a;
	while(cin>>a)
	{
		int l,CI;
		l=a.length();
		if(isNine(a))
		{
			cout<<1;
			for(int i=0;i<l-1;i++)
			cout<<0;
			cout<<1<<endl;
			continue;
		}//�����999999����ʽֱ�����1000001�� 
		else 
		{
			a[l-1]=a[l-1]+1;
			if(a[l-1]=='9'+1)
			{
				a[l-1]='0';
				CI=1;
				for(int i=2;i<=l;i++)
				{
					a[l-i]=a[l-i]+CI;
					if(a[l-i]=='9'+1)
					{
						a[l-i]='0';
					}
					else break;
				}
			}//ʵ�ּ�һ�� 
			if(l%2!=0)
			{
			for(int i=1;i<=l/2;i++)
			{
				if(a[l/2+i]>a[l/2-i])
				{
					a[l/2]=a[l/2]+1;
					if(a[l/2]=='9'+1)
					{
						a[l/2]='0';
						CI=1;
						for(int i=1;i<=l/2;i++)
						{
							a[l/2-i]=a[l/2-i]+CI;
							if(a[l/2-i]=='9'+1)
							{
								a[l/2-i]='0';
							}
							else break;	
						}
					}
					for(int i=1;i<=l/2;i++)
					{
						a[l/2+i]=a[l/2-i];
					}
					break;
				}//���������һ���м���ұ�������ȶ�Ӧ����ߴ� 
				else if(a[l/2+i]==a[l/2-i])
				{
					continue;
				} //�����м���ұ���������Ӧ�������ȡ� 
				else 
				{
					for(int j=i;j<=l/2;j++)
					{
						a[l/2+j]=a[l/2-j];
					}
					break;
				}//�����м��������ȶ�Ӧ�����С�� 
			}
			}//λ��Ϊ������ 
			else
			{
				for(int i=0;i<l/2;i++)
				{
					if(a[l/2+i]>a[l/2-i-1])
					{
						a[l/2-1]=a[l/2-1]+1;
						if(a[l/2-1]=='9'+1)
						{
							a[l/2-1]='0';
							CI=1;
							for(int j=1;j<l/2;j++)
							{
								a[l/2-1-j]=a[l/2-1-j]+CI;
								if(a[l/2-1-j]=='9'+1)
								{
									a[l/2-1-j]='0';
								}
								else break;
							}
						}
						for(int i=0;i<l/2;i++)
						{
							a[l/2+i]=a[l/2-1-i];
						}
						break;
					}//���������һ���м���ұ�������ȶ�Ӧ����ߴ�
					else if(a[l/2+i]==a[l/2-i-1])
					{
						continue;
					}//�����м���ұ���������Ӧ�������ȡ�
					else 
					{
						for(int i=0;i<l/2;i++)
						{
							a[l/2+i]=a[l/2-1-i];
						}
						break;
					}//�����м��������ȶ�Ӧ�����С��
				}
			} //λ��Ϊż���� 
			cout<<a<<endl;//����������� 
		}	
	}
	return 0;
} 
bool isNine(string a)
{
	int l;
	l=a.length();
	for(int i=0;i<l;i++)
	{
		if(a[i]!='9')
		return false ;
	}
	return true;
} 

