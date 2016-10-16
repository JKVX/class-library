#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<ctype.h>
#include <conio.h>
using namespace std;
void Write(int arr[][4]);
bool Check(int arr[][4]);
void Add(int arr[][4]);
bool IfUp(int arr[][4]);
bool IfDown(int arr[][4]);
bool IfLeft(int arr[][4]);
bool IfRight(int arr[][4]);
void Up(int arr[][4]);
void Down(int arr[][4]);
void Left(int arr[][4]);
void Right(int arr[][4]);
const int SPACE=5;
int main()
{	
	int game[4][4]={0};
	char move;
	cout<<"欢迎您走进2048的世界:"<<endl;
	cout<<"游戏指南：上：W，下：S，左：A，右：D"<<endl;
	cout<<"点击“Enter”开始游戏"<<endl;
	cin.get();
	
	Add(game);
	Write(game);
	
	do
	{ 
		move=getch();
		switch(toupper(move)) 
		{
			case 'W':Up(game);break;
			case 'S':Down(game);break;
			case 'A':Left(game);break;
			case 'D':Right(game);break;
			default:cout<<"请用W,S,A,D来执行上，下，左，右"
						<<endl; 
		}
	}while(Check(game));
	return 0; 	
}
//***********************************************************
void Write(int arr[][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			if(arr[i][j]==0) cout<<setw(SPACE)<<"*";
			else cout<<setw(SPACE)<<arr[i][j];
			cout<<endl;
	}
}
//************************************************************
bool Check(int arr[][4])
{
	int i,j,count=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(arr[i][j]==2048)
			{
				cout<<"恭喜你！获得胜利！"<<endl;
				system("pause");
				return false; 
			}
			if(arr[i][j]!=0) count++;
		}
	if(count==16)
	{
		bool m=false;
		bool n=false;
		for(i=0;i<4;i++)
			for(j=0;j<3;j++)
				if(arr[i][j]==arr[i][j+1]) m=true;
		for(j=0;j<4;j++)
			for(i=0;i<3;i++)
				if(arr[i][j]==arr[i+1][j]) n=true;
		if(m==false&&n==false) 
		{
			cout<<"你输啦，真可惜！"<<endl;
			system("pause");
			return false;
		}
	}
	return true;
}
//************************************************************
void Add(int arr[][4])
{
	srand((unsigned int)time(NULL));
	int a,b,c;
	do
	{
		a=rand()%4;
		b=rand()%4;
		if(arr[a][b]==0)
		{
			c=rand()%2;
			arr[a][b]=2*(c+1);
			return;
		}
	}while(1);
}
//************************************************************
bool IfUp(int arr[][4])
{
	int i,j;
	for(j=0;j<4;j++)
		for(i=0;i<3;i++)
			if(arr[i][j]==0||arr[i][j]==arr[i+1][j])
				return false;
	return true;			
}
//************************************************************
void Up(int arr[][4])
{
	int i,j,m,n,p;
	if(IfUp(arr)) 
	{	
		cout<<"无效操作。"<<endl; 
		return;
	}
	for(p=0;p<3;p++)
		for(j=0;j<4;j++)
			for(i=0;i<3;i++)
				for(m=0;m<(3-i);m++)
				{
					if(arr[i][j]==0)
	 				{
						for(n=i;n<3;n++) 
							arr[n][j]=arr[n+1][j];
						arr[3][j]=0;
					} 
					if(arr[i][j]==arr[i+1][j])
					{
						arr[i+1][j]*=2;
						arr[i][j]=0; 
					}
				}
	Add(arr);
	system("CLS");
	Write(arr);
}
//************************************************************
bool IfDown(int arr[][4])
{
	int i,j;
	for(j=0;j<4;j++)
		for(i=3;i>0;i--)
			if(arr[i][j]==0||arr[i][j]==arr[i-1][j])
				return false;
	return true;			
}
//************************************************************
void Down(int arr[][4])
{
	int i,j,m,n,p;
	if(IfDown(arr)) 
	{	
		cout<<"无效操作。"<<endl; 
		return;
	}
	for(p=0;p<3;p++)
		for(j=0;j<4;j++)
			for(i=3;i>0;i--)
				for(m=3;m>(3-i);m--)
				{
					if(arr[i][j]==0)
	 				{
						for(n=i;n>0;n--) 
							arr[n][j]=arr[n-1][j];
						arr[0][j]=0;
					} 
					if(arr[i][j]==arr[i-1][j])
					{
						arr[i-1][j]*=2;
						arr[i][j]=0; 
					}
				}
	Add(arr);
	system("CLS");
	Write(arr);
}
//***********************************************************
bool IfLeft(int arr[][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			if(arr[i][j]==0||arr[i][j]==arr[i][j+1])
				return false;
	return true;			
}
//***********************************************************
void Left(int arr[][4])
{
	int i,j,m,n,p;
	if(IfLeft(arr)) 
	{	
		cout<<"无效操作。"<<endl; 
		return;
	}
	for(p=0;p<3;p++)
		for(i=0;i<4;i++)
			for(j=0;j<3;j++)
				for(m=0;m<(3-j);m++)
				{
					if(arr[i][j]==0)
	 				{
						for(n=j;n<3;n++) 
							arr[i][n]=arr[i][n+1];
						arr[i][3]=0;
					} 
					if(arr[i][j]==arr[i][j+1])
					{
						arr[i][j+1]*=2;
						arr[i][j]=0; 
					}
				}
	Add(arr);
	system("CLS");
	Write(arr);
}
//**********************************************************
bool IfRight(int arr[][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=3;j>0;j--)
			if(arr[i][j]==0||arr[i][j]==arr[i][j-1])
				return false;
	return true;			
}
//**********************************************************
void Right(int arr[][4])
{
	int i,j,m,n,p;
	if(IfRight(arr)) 
	{	
		cout<<"无效操作。"<<endl; 
		return;
	}
	for(p=0;p<3;p++)
		for(i=0;i<4;i++)
			for(j=3;j>0;j--)
				for(m=3;m>(3-j);m--)
				{
					if(arr[i][j]==0)
	 				{
						for(n=j;n>0;n--) 
							arr[i][n]=arr[i][n-1];
						arr[i][0]=0;
					} 
					if(arr[i][j]==arr[i][j-1])
					{
						arr[i][j-1]*=2;
						arr[i][j]=0; 
					}
				}
	Add(arr);
	system("CLS");
	Write(arr);
}
//************************************************************



