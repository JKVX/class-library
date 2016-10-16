#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int year,day,n,s;
	string a="Su Mo Tu We Th Fr Sa  Su Mo \
Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa"; 
	while(cin>>year)
	{
	cout<<"                              "<<year<<"                              "
		<<endl<<endl;
	cout<<"      January               February               March        "<<endl;
	cout<<a<<endl;
	
	if(year<=1900)
	{
		day=(year-1800+(year-1800-1)/4+3)%7;
	}
	else 
	{
		day=(year-1800+(year-1800-1)/4+2)%7;
	}
	
	int arr[24][21]={0};
	int i,j,count=1;
	for(i=0,j=day;j<7;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=1;i<6;i++)
		for(j=0;j<7;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>31) 
			{	
				i=6;
				break;
			}
		}//一月 
	if(j==6)j=-1;
	count=1;
	for(i=0,j=j+8;j<14;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=1;i<6;i++)
		for(j=7;j<14;j++)
		{
			arr[i][j]=count;
			count++;
			if(year%4==0&&year%100!=0||year%400==0)
			{
				if(count>29) 
				{	
					i=6;
					break;
				}
			}
			else 
			{
				if(count>28)
				{
				i=6;
				break;
				}
			}
		}//二月 
	if(j==13)j=6;
	count=1;
	for(i=0,j=j+8;j<21;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=1;i<6;i++)
		for(j=14;j<21;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>31) 
			{	
				i=6;
				break;
			}
		}//三月 
	if(j==20)j=13;
	count=1;
	for(i=6,j=j-13;j<7;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=7;i<12;i++)
		for(j=0;j<7;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>30) 
			{	
				i=12;
				break;
			}
		}//四月 
	if(j==6)j=-1;
	count=1; 
	for(i=6,j=j+8;j<14;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=7;i<12;i++)
		for(j=7;j<14;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>31) 
			{	
				i=12;
				break;
			}
		}//五月 
	if(j==13)j=6;
	count=1;
	for(i=6,j=j+8;j<21;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=7;i<12;i++)
		for(j=14;j<21;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>30) 
			{	
				i=12;
				break;
			}
		}//六月 
	if(j==20)j=13;
	count=1;
	for(i=12,j=j-13;j<7;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=13;i<18;i++)
		for(j=0;j<7;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>31) 
			{	
				i=18;
				break;
			}
		}//七月 
	count=1; 
	if(j==6)j=-1;
	for(i=12,j=j+8;j<14;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=13;i<18;i++)
		for(j=7;j<14;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>31) 
			{	
				i=18;
				break;
			}
		}//八月 
	if(j==13)j=6;
	count=1;
	for(i=12,j=j+8;j<21;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=13;i<18;i++)
		for(j=14;j<21;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>30) 
			{	
				i=18;
				break;
			}
		}//九月
	if(j==20)j=13;
	count=1;
	for(i=18,j=j-13;j<7;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=19;i<24;i++)
		for(j=0;j<7;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>31) 
			{	
				i=24;
				break;
			}
		}//十月 
	if(j==6)j=-1;
	count=1; 
	for(i=18,j=j+8;j<14;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=19;i<24;i++)
		for(j=7;j<14;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>30) 
			{	
				i=24;
				break;
			}
		}//十一月 
	if(j==13)j=6;
	count=1;
	for(i=18,j=j+8;j<21;j++)
	{
		arr[i][j]=count;
		count++;
	}
	for(i=19;i<24;i++)
		for(j=14;j<21;j++)
		{
			arr[i][j]=count;
			count++;
			if(count>31) 
			{	
				i=24;
				break;
			}
		}//十二月
		for(i=0;i<6;i++)
		{
			for(j=0;j<21;j++)
			{
				if(j==0)
				{
					if(arr[i][j]==0)cout<<"  ";
					else cout<<setw(2)<<arr[i][j];
				}
				else if(j==6||j==13)
				{
					if(arr[i][j]==0)cout<<"    ";
					else cout<<setw(3)<<arr[i][j]<<" ";
				}
				else 
				{
					if(arr[i][j]==0)cout<<"   ";
					else cout<<setw(3)<<arr[i][j];
				}
			}
			cout<<endl;
		}
	cout<< "       April                  May                   June        "<<endl;
	cout<<a<<endl;
		for(i=6;i<12;i++)
		{
			for(j=0;j<21;j++)
			{
				if(j==0)
				{
					if(arr[i][j]==0)cout<<"  ";
					else cout<<setw(2)<<arr[i][j];
				}
				else if(j==6||j==13)
				{
					if(arr[i][j]==0)cout<<"    ";
					else cout<<setw(3)<<arr[i][j]<<" ";
				}
				else 
				{
					if(arr[i][j]==0)cout<<"   ";
					else cout<<setw(3)<<arr[i][j];
				}
			}
			cout<<endl;
		}
	cout<<"        July                 August              September      "<<endl;
	cout<<a<<endl;
		for(i=12;i<18;i++)
		{
			for(j=0;j<21;j++)
			{
				if(j==0)
				{
					if(arr[i][j]==0)cout<<"  ";
					else cout<<setw(2)<<arr[i][j];
				}
				else if(j==6||j==13)
				{
					if(arr[i][j]==0)cout<<"    ";
					else cout<<setw(3)<<arr[i][j]<<" ";
				}
				else 
				{
					if(arr[i][j]==0)cout<<"   ";
					else cout<<setw(3)<<arr[i][j];
				}
			}
			cout<<endl;
		}
	cout<< "      October               November              December      "<<endl;
	cout<<a<<endl;
		for(i=18;i<24;i++)
		{
			for(j=0;j<21;j++)
			{
				if(j==0)
				{
					if(arr[i][j]==0)cout<<"  ";
					else cout<<setw(2)<<arr[i][j];
				}
				else if(j==6||j==13)
				{
					if(arr[i][j]==0)cout<<"    ";
					else cout<<setw(3)<<arr[i][j]<<" ";
				}
				else 
				{
					if(arr[i][j]==0)cout<<"   ";
					else cout<<setw(3)<<arr[i][j];
				}
			}
			cout<<endl;
		}
	
}
		return 0;
} 
