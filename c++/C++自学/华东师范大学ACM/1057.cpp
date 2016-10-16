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
		}//如果是999999的形式直接输出1000001。 
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
			}//实现加一； 
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
				}//三种情况，一是中间的右边这个数比对应的左边大。 
				else if(a[l/2+i]==a[l/2-i])
				{
					continue;
				} //二是中间的右边这个数与对应的左边相等。 
				else 
				{
					for(int j=i;j<=l/2;j++)
					{
						a[l/2+j]=a[l/2-j];
					}
					break;
				}//三是中间的这个数比对应的左边小。 
			}
			}//位数为奇数。 
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
					}//三种情况，一是中间的右边这个数比对应的左边大。
					else if(a[l/2+i]==a[l/2-i-1])
					{
						continue;
					}//二是中间的右边这个数与对应的左边相等。
					else 
					{
						for(int i=0;i<l/2;i++)
						{
							a[l/2+i]=a[l/2-1-i];
						}
						break;
					}//三是中间的这个数比对应的左边小。
				}
			} //位数为偶数。 
			cout<<a<<endl;//输出回文数。 
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

