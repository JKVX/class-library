#include<iostream>
using namespace std;
bool isRunNian(int);
int main()
{
	int year,month,day,n,m=0;
	char c;
	cout<<"输入你们相爱的日子如1996-1-9：";
	cin>>year>>c>>month>>c>>day;
	cout<<"输入纪念日的天数：";
	cin>>n;
	cout<<"第"<<n<<"天纪念日为：";
	for(int i=1;i<month;i++)
	{
		switch(i)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:m=m+31;break;
			case 4:
			case 6:
			case 9:
			case 11:m=m+30;break;
			case 2:m=m+28;
				if(isRunNian(year))
				{	
					m++;
				}
		}
	}
	m=m+day;
	if(isRunNian(year))
	{
		m=366-m;
	} 
	else 
	{
		m=365-m;
	}
	if(m<n-1)
	{
		year++;
		month=1;
		day=1;
		n=n-m-2;
		while(n>364)
		{
			if(isRunNian(year))
			{
				if(n>365)
				{
					year++;
					n=n-366;
				}
				else 
				{
					month=12;
					day=31;
					n=0;
					break;
				}
			}
			else 
			{
				year++;
				n=n-365;
			}
		}
		while(n>30)
		{
			if(month==2)
			{
				if(isRunNian(year))
				{
					n=n-29;
					month++;
				}
				else 
				{
					n=n-28;
					month++;
				}
			}
			else if(month==4||month==6||month==9||month==11)
			{
				n=n-30;
				month++;
			}
			else 
			{
				n=n-31;
				month++;
			}
		}
		if(n==30)
		{
			if(month==4||month==6||month==9||month==11)
			{
				month++;
			}
			else if(month==2)
			{
				if(isRunNian(year))
				{
					month++;
					day++;
				}
				else
				{
					month++;
					day=day+2;
				}
			}
		}
		else if(n==29)
		{
			if(month==2)
			{
				if(isRunNian(year))
				{
					month++;
				}
				else 
				{
					month++;
					day++;
				}
			}
			else day=day+n;
		}
		else if(n==28)
		{
			if(month==2&&!isRunNian(year))
			{
				month++;
			}
			else day=day+n;
		}
		else day=day+n;
	}
	else 
	{
		while(n>30)
		{
			if(month==2)
			{
				if(isRunNian(year))
				{
					n=n-29;
					month++;
				}
				else 
				{
					n=n-28;
					month++;
				}
			}
			else if(month==4||month==6||month==9||month==11)
			{
				n=n-30;
				month++;
			}
			else 
			{
				n=n-31;
				month++;
			}
		}
		if(n==30)
		{
			if(month==4||month==6||month==9||month==11)
			{
				month++;
			}
			else if(month==2)
			{
				if(isRunNian(year))
				{
					month++;
					day++;
				}
				else
				{
					month++;
					day=day+2;
				}
			}
		}
		else if(n==29)
		{
			if(month==2)
			{
				if(isRunNian(year))
				{
					month++;
				}
				else 
				{
					month++;
					day++;
				}
			}
			else day=day+n;
		}
		else if(n==28)
		{
			if(month==2&&!isRunNian(year))
			{
				month++;
			}
			else day=day+n;
		}
		else day=day+n;
	}
	cout<<year<<'-'<<month<<'-'<<day<<endl;
	return 0;
}
bool isRunNian(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	{
		return true;
	}
	return false;
}
 
