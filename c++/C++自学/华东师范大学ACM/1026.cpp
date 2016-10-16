#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)  break;
		int arr[n][n];
		int i,j,a,b=0,c=0,d,e;
		for(i=0;i<n;i++)
		{
			for(a=0,j=0;j<n;j++)
			{
				cin>>arr[i][j];
				if(arr[i][j]==1)a++;
			}
			if(a%2!=0)
			{
				d=i;
				b++;
			}
		}
		for(j=0;j<n;j++)
		{
			for(a=0,i=0;i<n;i++)
			{
				if(arr[i][j]==1)a++;
			}
			if(a%2!=0)
			{
				e=j;
				c++;
			}
		}	
		if(c==0&&b==0)cout<<"OK"<<endl;
		else if(c==1&&b==1)
		{
			cout<<"Change bit ("<<d+1<<','<<e+1<<')'<<endl;
		}
		else cout<<"Corrupt"<<endl; 
	} 
	return 0;
} 
